/*
 * Copyright (c) 2021 Ola S�der
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
 cnd_wait

 Description: Refer to ISO/IEC 9899:2011 section 7.26.3.6 (p. 380).
 Input:       Ibid.
 Return:      Ibid.
*/
int cnd_wait(cnd_t *cond, mtx_t *mutex)
{
#ifdef THRD_PARANOIA
    if(unlikely(!mutex || !cond || atomic_load(&cond->dead)))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    if(unlikely(__cnd_wait(cond, mutex, NULL) == thrd_error))
    {
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_SUCCESS));
    return thrd_success;
}

/*------------------------------------------------------------------------------
 __cnd_sigwait_callback

 Description: Polling signal callback used in combination with __eclock_poll.
 Input:       void *data - callback function input data.
 Return:      int - 'thrd_success' if conditions are met in time,
              'thrd_timedout' on timeout and 'thrd_error' on error.
*/
static int __cnd_sigwait_callback(void *data)
{
    ULONG sigmask = 1 << *((BYTE *) data);
    FOG((THRD_WAIT(*((BYTE *) data))));

    /* Poll task signal mask. */
    if(SetSignal(0L, 0L) & sigmask)
    {
        SetSignal(0L, sigmask);

        FOG((THRD_SUCCESS));
        return thrd_success;
    }

    FOG((THRD_BUSY));
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
    if(likely(!time_point))
    {
        /* Refer to cnd_wait(). */
        FOG((THRD_WAIT(sigbit)));
        Wait(1L << sigbit);

        FOG((THRD_TRACE));
        SetSignal(0L, 1L << sigbit);

        FOG((THRD_SUCCESS));
        return thrd_success;
    }

    /* Refer to cnd_timedwait(). */
    return __eclock_poll(__cnd_sigwait_callback, &sigbit,
        __eclock_future(time_point), POLL_STRIDE);
}

/*------------------------------------------------------------------------------
 __cnd_new_node

 Description: Create and initialize new task node.
 Input:       -
 Return:      Task node on success, NULL on failure.
*/
static __cnd_node *__cnd_new_node(void)
{
    BYTE sigbit = AllocSignal(-1);
    FOG((THRD_ALLOC(sigbit)));

    if(unlikely(sigbit == -1))
    {
        /* Out of signals. */
        FOG((THRD_ERROR));
        return NULL;
    }

    __cnd_node *node = (__cnd_node *) AllocSysObjectTags(ASOT_NODE,
        ASONODE_Size, sizeof(__cnd_node), ASONODE_Type, NT_USER, TAG_END);
    FOG((THRD_ALLOC(node)));

    if(unlikely(!node))
    {
        /* Out of memory. */
        FOG((THRD_FREE(sigbit)));
        FreeSignal(sigbit);

        FOG((THRD_ERROR));
        return NULL;
    }

    FOG((THRD_TRACE));
    node->node.ln_Type = NT_USER;

    /* Not sure if ln_Name really needs to be a valid string. */
    node->node.ln_Name = (STRPTR) __func__;

    node->task = FindTask(NULL);
    node->sigbit = sigbit;

    /* Priority ordered queue to avoid task priority inversion. Fiddling with
     * the priority will cause uneccesary rescheduling but it won't hurt much
     * and there doesn't seem to be a better way of doing it. */
    FOG((THRD_TRACE));
    node->node.ln_Pri = SetTaskPri(node->task, 0);
    SetTaskPri(node->task, node->node.ln_Pri);

    return node;
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
    __cnd_node *node = __cnd_new_node();

    if(unlikely(!node))
    {
        /* Out of memory. */
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_LOCK(cond->mtx)));
    MutexObtain(cond->mtx);

    /* Add task to list of listeners taking task priority into account. */
    FOG((THRD_INSERT(node)));
    Enqueue(cond->tasks, (struct Node *) node);

    FOG((THRD_UNLOCK(cond->mtx)));
    MutexRelease(cond->mtx);

    /* Go to sleep or poll for signal if time_point exists. Encapsulate */
    /* with user mutex unlock and lock. Refer to cnd_wait() documentation. */
    FOG((THRD_UNLOCK(mutex)));
    mtx_unlock(mutex);

    int status = __cnd_wait_signal(node->sigbit, time_point);

    FOG((THRD_LOCK(mutex)));
    mtx_lock(mutex);

    /* Task nodes are dequeued by the signaling task. On timeouts and errors
     * this must be done here. See __cnd_signal(). */
    if(status != thrd_success)
    {
        FOG((THRD_LOCK(cond->mtx)));
        MutexObtain(cond->mtx);

        FOG((THRD_REMOVE(node)));
        Remove((struct Node *) node);

        FOG((THRD_UNLOCK(cond->mtx)));
        MutexRelease(cond->mtx);
    }

    /* Clear user signal. */
    FOG((THRD_TRACE));
    SetSignal(0L, 1L << node->sigbit);

    FOG((THRD_FREE(node->sigbit)));
    FreeSignal(node->sigbit);

    FOG((THRD_FREE(node)));
    FreeSysObject(ASOT_NODE, node);

    return status;
}
