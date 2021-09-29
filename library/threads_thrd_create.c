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
    assert(target);

    FOG((THRD_TRACE));
    atomic_uintptr_t mutex = atomic_exchange(target, 0);

    if(unlikely(!mutex))
    {
        LEAVE();
        return;
    }

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) mutex);

    FOG((THRD_FREE));
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
    assert(target);

    FOG((THRD_ALLOC));
    atomic_uintptr_t mutex = (atomic_uintptr_t)
        AllocSysObjectTags(ASOT_MUTEX, ASOMUTEX_Recursive,
        rec ? TRUE : FALSE, TAG_END);

    FOG((THRD_TRACE));
    atomic_store(target, mutex);

    if(unlikely(!mutex))
    {
        LEAVE();
        return false;
    }

    FOG((THRD_LOCK));
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
    assert(target);

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

    FOG((THRD_LOCK));
    MutexObtain((APTR) old);

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) old);

    FOG((THRD_FREE));
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
 Thread store.
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
    DECLARE_UTILITYBASE();

    static atomic_flag done = ATOMIC_FLAG_INIT;
    static struct Hook __thrd_ptr_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    FOG((THRD_TRACE));

    /* We shouldn't end up here more than once. */
    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG((THRD_TRUE));
        return true;
    }

    /* Allocate thread store mutex. Used not just for arbitration of the thread
     * store, but also for halting processes on startup. */
    FOG((THRD_ALLOC));
    __thrd_store_lock = AllocSysObjectTags(ASOT_MUTEX, TAG_END);

    if(unlikely(!__thrd_store_lock))
    {
        FOG((THRD_FALSE));
        return false;
    }

    /* The key used by the thread store skip list is a thrd_t which is the same
     * as the struct Task pointer of the thread. */
    FOG((THRD_ALLOC));
    __thrd_store = CreateSkipList(&__thrd_ptr_cmp_hook, 16);

    if(unlikely(!__thrd_store))
    {
        FOG((THRD_FREE));
        FreeSysObject(ASOT_MUTEX, __thrd_store_lock);

        FOG((THRD_FALSE));
        return false;
    }

    FOG((THRD_TRUE));
    return true;
}

/*------------------------------------------------------------------------------
 __thrd_store_teardown

 Description: Join all active threads and tear down thread store. Invoked from
              teardown() in stdlib_main.c.
 Input:       -
 Return:      -
*/
void __thrd_store_teardown(void)
{
    DECLARE_UTILITYBASE();
    assert(__thrd_store_lock && __thrd_store);

    static atomic_flag done = ATOMIC_FLAG_INIT;

    FOG((THRD_TRACE));

    /* We shouldn't end up here more than once. */
    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG((THRD_TRUE));
        return;
    }

    /* Locking the thread store shouldn't be necessary since the only place
     * where this function is to be invoked is the teardown() function in
     * stdlib_main.c, but let's do so anyways to be on the safe side. */
    FOG((THRD_LOCK));
    MutexObtain(__thrd_store_lock);

    /* Join all threads that are still alive. This shouldn't happen unless
     * there's a programming error somewhere. */
    for(struct SkipNode *head = GetFirstSkipNode(__thrd_store); head;)
    {
        /* The skip node key is a thrd_t which is a struct Task pointer. */
        thrd_t thread = (thrd_t) ((__thrd_s *) head)->node.sn_Key;
        struct SkipNode *next = GetNextSkipNode(__thrd_store, head);

        /* Need to unlock the thread store otherwise threads can't exit. */
        FOG((THRD_UNLOCK));
        MutexRelease(__thrd_store_lock);

        /* Join thread. The return value is of no use. */
        FOG((THRD_TRACE));
        thrd_join(thread, NULL);

        FOG((THRD_LOCK));
        MutexObtain(__thrd_store_lock);

        /* Garbage collect thread. */
        FOG((THRD_FREE));
        RemoveSkipNode(__thrd_store, thread);

        head = next;
    }

    /* Free empty thread store skip list. */
    FOG((THRD_FREE));
    DeleteSkipList(__thrd_store);

    FOG((THRD_UNLOCK));
    MutexRelease(__thrd_store_lock);

    /* Free thread store mutex. */
    FOG((THRD_FREE));
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
    DECLARE_UTILITYBASE();
    assert(__thrd_store_lock && __thrd_store);

    struct Task *task = FindTask(NULL);

    /* Block other processes from joining. */
    FOG((THRD_LOCK));
    MutexObtain(__thrd_store_lock);

    /* This can fail on out of memory in thrd_create(). If so, this thread is
     * stillborn, the user function hasn't been invoked. */
    FOG((THRD_FIND));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);

    if(unlikely(!thread))
    {
        FOG((THRD_UNLOCK));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_NOTFOUND));
        return;
    }

    if(!atomic_flag_test_and_set(&(thread->gc)))
    {
        /* Thread is not being joined. Thread will garbage collect itself. */
        FOG((THRD_FREE));
        RemoveSkipNode(__thrd_store, task);
    }
    else
    {
        /* Thread is being joined. Save return value and leave the garbage
         * collection to the joining process. */
        FOG((THRD_TRACE));
        thread->retval = retval;
    }

    FOG((THRD_UNLOCK));
    MutexRelease(__thrd_store_lock);
}

extern struct List *__tss_store;
extern atomic_uintptr_t __tss_store_lock;

/*------------------------------------------------------------------------------
 __tss_store_purge

 Description: Remove and execute destructors for all TSS values of a task.
 Input:       struct Task *task - the task to purge.
 Return:      -
*/
void __tss_store_purge(__attribute__((unused)) struct Task *task)
{
    assert(task);

    FOG((THRD_TRACE));
    /*
    ENTER();
    DECLARE_UTILITYBASE();
    assert(task);

    if(!atomic_load(&__tss_store))
    {
        LEAVE();
        return;
    }

    FOG(("Lock store mutex.\n"));
    MutexObtain((APTR) __tss_store_lock);

    for(struct Node *head = GetHead(__tss_store); head;)
    {
        tss_t *tss = &((__tss_n *) head)->tss;

        FOG(("Find task value.\n"));
        struct SkipNode *node = FindSkipNode(tss->values, task);
        head = GetSucc(head);

        if(!node)
        {
            FOG(("No value.\n"));
            continue;
        }

        if(tss->destructor && ((__tss_v *) node)->value)
        {
            FOG(("Invoke destructor.\n"));
            tss->destructor(((__tss_v *) node)->value);
        }

        FOG(("Remove value.\n"));
        RemoveSkipNode(tss->values, task);
    }

    FOG(("Unlock store mutex.\n"));
    MutexRelease((APTR) __tss_store_lock);
*/
}

/*------------------------------------------------------------------------------
 __thrd_wrap

 Description: Thread setup, exit and teardown.
 Input:       -
 Return:      int32_t - thread return value.
*/
static int32_t __thrd_wrap(void)
{
    DECLARE_UTILITYBASE();
    assert(__thrd_store && __thrd_store_lock);

    struct Task *task = FindTask(NULL);

    FOG((THRD_LOCK));
    MutexObtain(__thrd_store_lock);

    /* This can fail on out of memory in thrd_create(). */
    FOG((THRD_FIND));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);

    FOG((THRD_UNLOCK));
    MutexRelease(__thrd_store_lock);

    if(unlikely(!thread))
    {
        FOG((THRD_NOTFOUND));
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
    DECLARE_UTILITYBASE();
    assert(thread && start && __thrd_store && __thrd_store_lock);

    FOG((THRD_LOCK));
    MutexObtain(__thrd_store_lock);

    FOG((THRD_TRACE));
    *thread = (struct Task *) CreateNewProcTags(NP_Entry, __thrd_wrap,
        NP_FinalCode, __thrd_final, NP_Child, TRUE, TAG_END);

    if(unlikely(!*thread))
    {
        FOG((THRD_UNLOCK));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_NOMEM));
        return thrd_nomem;
    }

    FOG((THRD_ALLOC));
    __thrd_s *node = (__thrd_s *)
        InsertSkipNode(__thrd_store, *thread, sizeof(__thrd_s));

    if(unlikely(!node))
    {
        FOG((THRD_UNLOCK));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_NOMEM));
        return thrd_nomem;
    }

    FOG((THRD_TRACE));
    atomic_flag_clear(&(node->gc));
    node->start = start;
    node->arg = arg;
    node->retval = 0;

    FOG((THRD_UNLOCK));
    MutexRelease(__thrd_store_lock);

    return thrd_success;
}
