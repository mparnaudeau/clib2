/*
 * Copyright (c) 2021 Ola Söder
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _THREADS_HEADERS_H
#include "threads_headers.h"
#endif

/*------------------------------------------------------------------------------
 __cnd_sigwait_callback

 Description: Polling signal callback used in combination with __eclock_poll.
 Input:       void *data - callback function input data.
 Return:      int - 'thrd_success' if conditions are met in time,
              'thrd_timedout' on timeout and 'thrd_error' on error.
*/
static int __cnd_sigwait_callback(void *data)
{
    ENTER();
    assert(data);

    ULONG sigmask = 1 << *((BYTE *) data);

    LOG(("Get signal mask.\n"));
    if(SetSignal(0L, 0L) & sigmask)
    {
        LOG(("Got signal.\n"));
        SetSignal(0L, sigmask);

        LEAVE();
        return thrd_success;
    }

    LEAVE();
    return thrd_busy;
}

/*------------------------------------------------------------------------------
 __cnd_wait_signal

 Description: Wait for signal or, if a time point is given, poll until signal is
              received or time is up.
 Input:       BYTE sigbit - signal bit to wait for / poll.
              const struct timespec *restrict time_point - absolute timeout.
 Return:      int - 'thrd_success' if conditions are met in time and
              'thrd_timedout' on timeout, otherwise 'thrd_error'.
*/
static int __cnd_wait_signal(BYTE sigbit,
                             const struct timespec *restrict time_point)
{
    ENTER();
    assert(sigbit != -1);

    if(!time_point)
    {
        LOG(("Wait for signal.\n"));
        Wait(1L << sigbit);

        LOG(("Got signal.\n"));
        SetSignal(0L, 1L << sigbit);

        LEAVE();
        return thrd_success;
    }

    LOG(("Poll signal with timeout.\n"));
    int status =  __eclock_poll(__cnd_sigwait_callback, &sigbit,
        __eclock_future(time_point), POLL_STRIDE);

    LEAVE();
    return status;
}

/*------------------------------------------------------------------------------
 __cnd_wait

 Description: Append current task to the queue of conditional listeners and go
              to sleep, optionally with a timeout. Tasks are kept in priority
              order. The task with the highest priority will always be signaled
              first.
 Input:       cnd_t *cond - conditional to sleep on.
              mtx_t *mutex - locked mutex (refer to cnd_wait documentation).
              const struct timespec *restrict time_point - absolute timeout.
 Return:      int - 'thrd_success' if signaled and 'thrd_timedout' on timeout,
              otherwise 'thrd_error'.
*/
int __cnd_wait(cnd_t *cond, mtx_t *mutex,
               const struct timespec *restrict time_point)
{
    ENTER();
    assert(cond && cond->mutex && mutex && time_point);

    LOG(("Allocate signal.\n"));
    BYTE sigbit = AllocSignal(-1);

    if(unlikely(sigbit == -1))
    {
        LEAVE();
        return thrd_error;
    }

    LOG(("Create listener thread node.\n"));
    __cnd_node *node = (__cnd_node *)
        AllocSysObjectTags(ASOT_NODE, ASONODE_Size, sizeof(__cnd_node),
        ASONODE_Type, NT_USER, TAG_END);

    if(unlikely(!node))
    {
        LEAVE();
        return thrd_error;
    }

    LOG(("Initialize listener thread node.\n"));
    node->node.ln_Type = NT_USER;
    node->node.ln_Name = (STRPTR) __func__;
    node->task = FindTask(NULL);
    node->sigbit = sigbit;

    /* Ordered queue to avoid task priority inversion. */
    node->node.ln_Pri = SetTaskPri(node->task, 0);
    SetTaskPri(node->task, node->node.ln_Pri);

    LOG(("Lock conditional mutex.\n"));
    MutexObtain((APTR) cond->mutex);

    LOG(("Add current thread to list of listeners.\n"));
    Enqueue(cond->tasks, (struct Node *) node);

    LOG(("Unlock conditional mutex.\n"));
    MutexRelease((APTR) cond->mutex);

    /* Go to sleep or poll for signal if time_point exists. Encapsulate */
    /* with mutex unlock and lock (refer to cnd_wait documentation). */

    LOG(("Unlock user mutex.\n"));
    mtx_unlock(mutex);

    LOG(("Wait for signal.\n"));
    int status = __cnd_wait_signal(sigbit, time_point);

    LOG(("Lock user mutex.\n"));
    mtx_lock(mutex);

    LOG(("Lock conditional mutex.\n"));
    MutexObtain((APTR) cond->mutex);

    LOG(("Remove current thread from list of listeners.\n"));
    Remove((struct Node *) node);

    LOG(("Unlock conditional mutex.\n"));
    MutexRelease((APTR) cond->mutex);

    LOG(("Clear signal.\n"));
    SetSignal(0L, 1L << sigbit);

    LOG(("Free signal.\n"));
    FreeSignal(sigbit);

    LOG(("Free listener thread node.\n"));
    FreeSysObject(ASOT_NODE, node);

    LEAVE();
    return status;
}

int cnd_wait(cnd_t *cond, mtx_t *mutex)
{
    ENTER();
    assert(cond && cond->mutex && mutex);

    LOG(("Conditional wait.\n"));
    int status = __cnd_wait(cond, mutex, NULL);

    LEAVE();
    return status;
}
