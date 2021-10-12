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

#include "threads_headers.h"

/*------------------------------------------------------------------------------
 __thrd_mutex_free

 Description: Free locked mutex in a safe manner.
 Input:       atomic_uintptr_t *target - pointer to native mutex.
 Return:      -
*/
void __thrd_mutex_free(atomic_uintptr_t *target)
{
    FOG((THRD_TRACE));
    atomic_uintptr_t mutex = atomic_exchange(target, 0);

    if(unlikely(!mutex))
    {
        LEAVE();
        return;
    }

    FOG((THRD_UNLOCK(mutex)));
    MutexRelease((APTR) mutex);

    FOG((THRD_FREE(mutex)));
    FreeSysObject(ASOT_MUTEX, (APTR) mutex);
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
        AllocSysObjectTags(ASOT_MUTEX, ASOMUTEX_Recursive,
        rec ? TRUE : FALSE, TAG_END);
    FOG((THRD_ALLOC(mutex)));

    FOG((THRD_TRACE));
    atomic_store(target, mutex);

    if(unlikely(!mutex))
    {
        LEAVE();
        return false;
    }

    FOG((THRD_LOCK(mutex)));
    MutexObtain((APTR) mutex);

    LEAVE();
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
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_TRACE));
    atomic_uintptr_t old = atomic_exchange(target, mutex);

    if(likely(!old))
    {
        LEAVE();
        return thrd_success;
    }

    FOG((THRD_LOCK(old)));
    MutexObtain((APTR) old);

    FOG((THRD_UNLOCK(old)));
    MutexRelease((APTR) old);

    FOG((THRD_FREE(old)));
    FreeSysObject(ASOT_MUTEX, (APTR) old);

    LEAVE();
    return thrd_busy;
}

/*------------------------------------------------------------------------------
 __thrd_ptr_cmp_callback

 Description: Used by SkipList hook.
 Input:       See NDK documentation.
 Return:      See NDK documentation.
*/
LONG __thrd_ptr_cmp_callback(__attribute__((unused)) struct Hook *hook,
    APTR lhs, APTR rhs)
{
    return (lhs < rhs) ? -1 : (lhs > rhs) ? 1 : 0;
}

/*------------------------------------------------------------------------------
 */
struct SkipList *__thrd_store;
APTR __thrd_store_lock;

/*------------------------------------------------------------------------------
 __thrd_store_setup

 Description: Initialize thread store. Invoked from setup() in stdlib_main.c.
 Input:       -
 Return:      bool - 'true' on success, 'false' otherwise.
*/
bool __thrd_store_setup(void)
{
    static atomic_flag done = ATOMIC_FLAG_INIT;

    /* We shouldn't end up here more than once. */
    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG((THRD_TRUE));
        return true;
    }

    static struct Hook __thrd_ptr_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    /* Allocate thread store mutex. Used not just for arbitration of the thread
     * store, but also for halting processes on startup. */
    __thrd_store_lock = AllocSysObjectTags(ASOT_MUTEX, TAG_END);
    FOG((THRD_ALLOC(__thrd_store_lock)));

    DECLARE_UTILITYBASE();

    /* The key used by the thread store skip list is a thrd_t which is the same
     * as the struct Task pointer of the thread. */
    __thrd_store = CreateSkipList(&__thrd_ptr_cmp_hook, 16);
    FOG((THRD_ALLOC(__thrd_store)));

    if(unlikely(!__thrd_store || !__thrd_store_lock))
    {
        /* Out of memory. */
        FOG((THRD_FREE(__thrd_store_lock)));
        FreeSysObject(ASOT_MUTEX, __thrd_store_lock);

        FOG((THRD_FREE(__thrd_store)));
        DeleteSkipList(__thrd_store);
    }

    FOG((__thrd_store && __thrd_store_lock ? THRD_TRUE : THRD_FALSE));
    return __thrd_store && __thrd_store_lock;
}

/*------------------------------------------------------------------------------
 __thrd_store_teardown

 Description: Join all active threads and tear down thread store. Invoked from
              teardown() or setup() in stdlib_main.c.
 Input:       -
 Return:      -
*/
void __thrd_store_teardown(void)
{
#ifdef THRD_PARANOIA
    static atomic_flag done = ATOMIC_FLAG_INIT;

    /* We shouldn't end up here more than once. */
    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG((THRD_TRUE));
        return;
    }

    /* Locking the thread store isn't necessary since the only place where
     * this function is invoked is in teardown() in stdlib_main.c. */
    DECLARE_UTILITYBASE();

    /* Join all threads that are still alive. This shouldn't happen unless
     * there's a user programming error somewhere. */
    for(struct SkipNode *head = GetFirstSkipNode(__thrd_store); head;)
    {
        struct SkipNode *next = GetNextSkipNode(__thrd_store, head);

        /* The skip node key is a thrd_t. */
        FOG((THRD_TRACE));
        thrd_join((thrd_t) head->sn_Key, NULL);

        /* Garbage collect thread. */
        FOG((THRD_FREE(head)));
        RemoveSkipNode(__thrd_store, head->sn_Key);
        head = next;
    }
#else
    DECLARE_UTILITYBASE();
#endif
    /* Free empty thread store skip list. */
    FOG((THRD_FREE(__thrd_store)));
    DeleteSkipList(__thrd_store);

    /* Free thread store mutex. */
    FOG((THRD_FREE(__thrd_store_lock)));
    FreeSysObject(ASOT_MUTEX, __thrd_store_lock);
}

/*------------------------------------------------------------------------------
 __thrd_final

 Description: Process finalization. Refer to CreateNewProcTags and NP_FinalCode.
 Input:       See NDK documentation.
 Return:      -
*/
static void __thrd_final(int32_t retval, __attribute__((unused)) int32_t data,
    __attribute__((unused)) struct ExecBase *sysbase)
{
    /* Block other processes from joining. */
    FOG((THRD_LOCK(__thrd_store_lock)));
    MutexObtain(__thrd_store_lock);

    DECLARE_UTILITYBASE();
    struct Task *task = FindTask(NULL);

    /* This can fail on out of memory in thrd_create(). If so, this thread is
     * stillborn, the user function hasn't been invoked. */
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);
    FOG((THRD_FOUND(thread)));

    if(unlikely(!thread))
    {
        FOG((THRD_UNLOCK(__thrd_store_lock)));
        MutexRelease(__thrd_store_lock);
        return;
    }

    if(!atomic_flag_test_and_set(&(thread->gc)))
    {
        /* Thread is not being joined. Thread will garbage collect itself. */
        FOG((THRD_FREE(thread)));
        RemoveSkipNode(__thrd_store, task);
    }
    else
    {
        /* Thread is being joined. Save return value and leave the garbage
         * collection to the joining process. */
        FOG((THRD_TRACE));
        thread->retval = retval;
    }

    FOG((THRD_UNLOCK(__thrd_store_lock)));
    MutexRelease(__thrd_store_lock);
}

extern struct List *__tss_store;
extern atomic_uintptr_t __tss_store_lock;

/*------------------------------------------------------------------------------
 __thrd_wrap

 Description: Thread setup, exit and teardown.
 Input:       -
 Return:      int32_t - thread return value.
*/
static int32_t __thrd_wrap(void)
{
    /* Block until thrd_create() is done. Refer to thrd_create(). */
    FOG((THRD_LOCK(__thrd_store_lock)));
    MutexObtain(__thrd_store_lock);

    DECLARE_UTILITYBASE();
    struct Task *task = FindTask(NULL);

    /* This can fail on out of memory in thrd_create(). */
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);
    FOG((THRD_FOUND(thread)));

    FOG((THRD_UNLOCK(__thrd_store_lock)));
    MutexRelease(__thrd_store_lock);

    if(unlikely(!thread))
    {
        return -1;
    }

    /* Set exit point used by thrd_exit(). */
    FOG((THRD_TRACE));
    int32_t retval = setjmp(thread->stop);

    if(unlikely(retval))
    {
        /* thrd_exit() invoked. */
        __tss_store_purge(task);
        return retval;
    }

    /* Enter user function. */
    FOG((THRD_TRACE));
    retval = thread->start(thread->arg);

    FOG((THRD_TRACE));
    __tss_store_purge(task);

    return retval;
}

/*------------------------------------------------------------------------------
 thrd_create

 Description: Refer to ISO/IEC 9899:2011 section 7.26.5.1 (p. 383).
 Input:       Ibid.
 Return:      Ibid.
*/
int thrd_create(thrd_t *thread, thrd_start_t start, void *arg)
{
#ifdef THRD_PARANOIA
    if(unlikely(!thread || !start))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    /* Halt new process until we've initialized thread store and thread store
     * entry. Refer to __thrd_wrap(). */
    FOG((THRD_LOCK(__thrd_store_lock)));
    MutexObtain(__thrd_store_lock);

    FOG((THRD_TRACE));
    *thread = (struct Task *) CreateNewProcTags(NP_Entry, __thrd_wrap,
        NP_FinalCode, __thrd_final, NP_Child, TRUE, TAG_END);

    if(unlikely(!*thread))
    {
        /* Out of memory. */
        FOG((THRD_UNLOCK(__thrd_store_lock)));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_NOMEM));
        return thrd_nomem;
    }

    DECLARE_UTILITYBASE();

    /* Create and insert thread store entry in thread store. */
    __thrd_s *node = (__thrd_s *)
        InsertSkipNode(__thrd_store, *thread, sizeof(__thrd_s));
    FOG((THRD_ALLOC(node)));

    if(unlikely(!node))
    {
        /* Out of memory. */
        FOG((THRD_UNLOCK(__thrd_store_lock)));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_NOMEM));
        return thrd_nomem;
    }

    /* Set values needed by __thrd_wrap(). */
    atomic_flag_clear(&(node->gc));
    node->start = start;
    node->arg = arg;
    node->retval = 0;

    /* Unblock __thrd_wrap(). */
    FOG((THRD_UNLOCK(__thrd_store_lock)));
    MutexRelease(__thrd_store_lock);

    FOG((THRD_SUCCESS));
    return thrd_success;
}
