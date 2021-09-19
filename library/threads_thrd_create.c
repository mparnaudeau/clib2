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
 __thrd_mutex_free

 Description: Free locked mutex in a safe manner.
 Input:       atomic_uintptr_t *target - pointer to native mutex.
 Return:      -
*/
void __thrd_mutex_free(atomic_uintptr_t *target)
{
    atomic_uintptr_t mutex = atomic_exchange(target, 0);

    if(unlikely(!mutex))
    {
        return;
    }

    IExec->MutexRelease((APTR) mutex);
    IExec->FreeSysObject(ASOT_MUTEX, (APTR) mutex);
}

/*------------------------------------------------------------------------------
 __thrd_mutex_create

 Description: Create locked mutex.
 Input:       atomic_uintptr_t *target - pointer to native mutex target.
              bool rec - on 'true', a recursive mutex, non-recursive otherwise.
 Return:      bool - On success 'true', 'false' otherwise.
*/
bool __thrd_mutex_create(atomic_uintptr_t *target, bool rec)
{
    atomic_uintptr_t mutex = (atomic_uintptr_t)
        IExec->AllocSysObjectTags(ASOT_MUTEX, ASOMUTEX_Recursive,
        rec ? TRUE : FALSE, TAG_END);

    /* Always store the result. */
    atomic_store(target, mutex);

    if(unlikely(!mutex))
    {
        /* Out of memory. */
        return false;
    }

    /* Locked from birth. */
    IExec->MutexObtain((APTR) mutex);
    return true;
}

/*------------------------------------------------------------------------------
 __thrd_mutex_replace

 Description: Create locked recursive mutex and replace existing mutex, if any.
 Input:       atomic_uintptr_t *target - pointer to native mutex target.
 Return:      int - On out of memory, 'thrd_error', on success 'thrd_success',
              on success with replacement 'thrd_busy'.
*/
int __thrd_mutex_replace(atomic_uintptr_t *target)
{
    atomic_uintptr_t mutex;

    if(unlikely(!__thrd_mutex_create(&mutex, true)))
    {
        /* Out of memory. */
        return thrd_error;
    }

    atomic_uintptr_t old = atomic_exchange(target, mutex);

    if(likely(!old))
    {
        /* Nothing replaced. */
        return thrd_success;
    }

    /* Lock in case it's in use. */
    IExec->MutexObtain((APTR) old);
    IExec->MutexRelease((APTR) old);
    IExec->FreeSysObject(ASOT_MUTEX, (APTR) old);

    /* Signal replacement with thrd_busy. */
    return thrd_busy;
}

/*------------------------------------------------------------------------------
 Global thread store.
 */
struct SkipList *__thrd_store = NULL;
atomic_uintptr_t __thrd_store_lock = 0;

/*------------------------------------------------------------------------------
 __thrd_ptr_cmp_callback

 Description: Used by SkipList hook.
 Input:       See NDK documentation.
 Return:      See NDK documentation.
*/
LONG __thrd_ptr_cmp_callback(struct Hook *hook, APTR lhs, APTR rhs)
{
    return (lhs < rhs) ? -1 : (lhs > rhs) ? 1 : 0;
}

/*------------------------------------------------------------------------------
 __thrd_store_init

 Description: Initialize thread store.
 Input:       -
 Return:      bool - 'true' on success, 'false' otherwise.
*/
static bool __thrd_store_init(void)
{
    static struct Hook __thrd_ptr_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    /* Mutex is locked at birth. */
    int status = __thrd_mutex_replace(&__thrd_store_lock);

    if(unlikely(status == thrd_error))
    {
        /* Out of memory. */
        return false;
    }

    /* This should be impossible. */
    if(unlikely(status == thrd_busy))
    {
        IExec->MutexRelease((APTR) __thrd_store_lock);
        return __thrd_store != NULL;
    }

    /* Create thread store skip list. */
    __thrd_store = IUtility->CreateSkipList(&__thrd_ptr_cmp_hook, 16);

    if(unlikely(!__thrd_store))
    {
        /* Out of memory. */
        __thrd_mutex_free(&__thrd_store_lock);
        return false;
    }

    IExec->MutexRelease((APTR) __thrd_store_lock);
    return true;
}

/*------------------------------------------------------------------------------
 __thrd_final

 Description: Process finalization. Refer to CreateNewProcTags and NP_FinalCode.
 Input:       See NDK documentation.
 Return:      -
*/
static void __thrd_final(int32_t retval, int32_t data, struct ExecBase *sysbase)
{
    struct Task *task = IExec->FindTask(NULL);
    IExec->MutexObtain((APTR) __thrd_store_lock);
    __thrd_s *thread = (__thrd_s *) IUtility->FindSkipNode(__thrd_store, task);

    if(unlikely(!thread))
    {
        /* This will only happen on out of memory. */
        IExec->MutexRelease((APTR) __thrd_store_lock);
        return;
    }

    if(atomic_flag_test_and_set(&(thread->gc)))
    {
        /* Garbage collect thread. */
        IUtility->RemoveSkipNode(__thrd_store, task);

        if(!IUtility->GetFirstSkipNode(__thrd_store))
        {
            /* Delete empty thread store. */
            IUtility->DeleteSkipList(__thrd_store);
            __thrd_store = NULL;
            __thrd_mutex_free(&__thrd_store_lock);
            return;
        }
    }
    else
    {
        /* Thread is being joined. */
        thread->retval = retval;
    }

    IExec->MutexRelease((APTR) __thrd_store_lock);
}

/*------------------------------------------------------------------------------
 __thrd_wrap

 Description: Thread setup, exit and teardown.
 Input:       -
 Return:      int32_t - thread return value.
*/
static int32_t __thrd_wrap(void)
{
    struct Task *task = IExec->FindTask(NULL);

    /* Wait until initialized. */
    IExec->MutexObtain((APTR) __thrd_store_lock);

    /* We should find ourselves unless out of memory. */
    __thrd_s *thread = (__thrd_s *) IUtility->FindSkipNode(__thrd_store, task);
    IExec->MutexRelease((APTR) __thrd_store_lock);

    if(unlikely(!thread))
    {
        return -1;
    }

    /* Exit point. */
    int32_t retval = setjmp(thread->stop);

    if(unlikely(retval))
    {
        /* thrd_exit(). */
        __tss_store_purge(task);
        return retval;
    }

    /* Enter user function. */
    retval = thread->start(thread->arg);

    /* Free TSS. */
    __tss_store_purge(task);
    return retval;
}

int thrd_create(thrd_t *thread, thrd_start_t start, void *arg)
{
    static atomic_flag init = ATOMIC_FLAG_INIT;

    /* Init store one time and one time only. */
    if(unlikely(!atomic_flag_test_and_set(&init) && !__thrd_store_init()))
    {
        atomic_flag_clear(&init);
        return thrd_nomem;
    }

    /* Lock store to halt new process. See __thrd_wrap(). */
    IExec->MutexObtain((APTR) __thrd_store_lock);

    /* Spawn new process. */
    *thread = (struct Task *) IDOS->CreateNewProcTags(NP_Entry, __thrd_wrap,
        NP_FinalCode, __thrd_final, NP_Child, TRUE, NP_NotifyOnDeathSigTask,
        IExec->FindTask(NULL), TAG_END);

    if(unlikely(!*thread))
    {
        IExec->MutexRelease((APTR) __thrd_store_lock);
        return thrd_nomem;
    }

    /* Create thread store entry. */
    __thrd_s *node = (__thrd_s *)
        IUtility->InsertSkipNode(__thrd_store, *thread, sizeof(__thrd_s));

    if(unlikely(!node))
    {
        IExec->MutexRelease((APTR) __thrd_store_lock);
        return thrd_nomem;
    }

    /* Initialize thread. */
    (void) atomic_flag_test_and_set(&(node->gc));
    node->start = start;
    node->arg = arg;
    node->retval = 0;

    /* Unlock will unhalt thread. */
    IExec->MutexRelease((APTR) __thrd_store_lock);
    return thrd_success;
}
