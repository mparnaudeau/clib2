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
    ENTER();
    assert(target);

    FOG(("Clear mutex.\n"));
    atomic_uintptr_t mutex = atomic_exchange(target, 0);

    if(unlikely(!mutex))
    {
        LEAVE();
        return;
    }

    FOG(("Unlock mutex.\n"));
    MutexRelease((APTR) mutex);

    FOG(("Free mutex.\n"));
    FreeSysObject(ASOT_MUTEX, (APTR) mutex);

    LEAVE();
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
    ENTER();
    assert(target);

    FOG(("Create mutex.\n"));
    atomic_uintptr_t mutex = (atomic_uintptr_t)
        AllocSysObjectTags(ASOT_MUTEX, ASOMUTEX_Recursive,
        rec ? TRUE : FALSE, TAG_END);

    FOG(("Store mutex.\n"));
    atomic_store(target, mutex);

    if(unlikely(!mutex))
    {
        LEAVE();
        return false;
    }

    FOG(("Lock mutex.\n"));
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
    ENTER();
    assert(target);

    atomic_uintptr_t mutex;

    FOG(("Create mutex.\n"));
    if(unlikely(!__thrd_mutex_create(&mutex, true)))
    {
        LEAVE();
        return thrd_error;
    }

    FOG(("Exchange mutex.\n"));
    atomic_uintptr_t old = atomic_exchange(target, mutex);

    if(likely(!old))
    {
        LEAVE();
        return thrd_success;
    }

    FOG(("Lock old mutex.\n"));
    MutexObtain((APTR) old);

    FOG(("Unlock old mutex.\n"));
    MutexRelease((APTR) old);

    FOG(("Free old mutex.\n"));
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
LONG __thrd_ptr_cmp_callback(struct Hook *hook, APTR lhs, APTR rhs)
{
    ENTER();

    FOG(("LHS %p - RHS %p.\n", lhs, rhs));

    (void) hook;
    LONG status = (lhs < rhs) ? -1 : (lhs > rhs) ? 1 : 0;

    LEAVE();
    return status;
}

/*------------------------------------------------------------------------------
 Global thread store.
 */
struct SkipList *__thrd_store;
APTR __thrd_store_lock;

/*------------------------------------------------------------------------------
 __thrd_store_setup

 Description: Initialize thread store.
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

    FOG(("Initialize thread store.\n"));

    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG(("Already setup.\n"));
        return true;
    }

    FOG(("Create thread store mutex.\n"));
    __thrd_store_lock = AllocSysObjectTags(ASOT_MUTEX, TAG_END);

    if(unlikely(!__thrd_store_lock))
    {
        return false;
    }

    FOG(("Create thread store skip list.\n"));
    __thrd_store = CreateSkipList(&__thrd_ptr_cmp_hook, 16);

    if(unlikely(!__thrd_store))
    {
        FreeSysObject(ASOT_MUTEX, __thrd_store_lock);
        return false;
    }

    return true;
}

/*------------------------------------------------------------------------------
 __thrd_store_teardown

 Description: Join all active threads and tear down thread store.
 Input:       -
 Return:      -
*/
void __thrd_store_teardown(void)
{
    DECLARE_UTILITYBASE();
    assert(__thrd_store_lock && __thrd_store);

    static atomic_flag done = ATOMIC_FLAG_INIT;

    FOG(("Tear down thread store.\n"));

    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG(("Already torn down.\n"));
        return;
    }

    FOG(("Lock thread store mutex.\n"));
    MutexObtain(__thrd_store_lock);

    for(struct SkipNode *head = GetFirstSkipNode(__thrd_store); head;)
    {
        FOG(("Thread store not empty.\n"));

        thrd_t thread = (thrd_t) ((__thrd_s *) head)->node.sn_Key;
        struct SkipNode *next = GetNextSkipNode(__thrd_store, head);

        FOG(("Unlock thread store mutex.\n"));
        MutexRelease(__thrd_store_lock);

        FOG(("Joining %p.\n", thread));
        thrd_join(thread, NULL);

        FOG(("Lock thread store mutex.\n"));
        MutexObtain(__thrd_store_lock);

        FOG(("Remove %p from thread store.\n", thread));
        RemoveSkipNode(__thrd_store, thread);

        head = next;
    }

    FOG(("Free thread store skip list.\n"));
    DeleteSkipList(__thrd_store);

    FOG(("Unlock thread store mutex.\n"));
    MutexRelease(__thrd_store_lock);

    FOG(("Free thread store mutex.\n"));
    FreeSysObject(ASOT_MUTEX, __thrd_store_lock);
}

/*------------------------------------------------------------------------------
 __thrd_final

 Description: Process finalization. Refer to CreateNewProcTags and NP_FinalCode.
 Input:       See NDK documentation.
 Return:      -
*/
static void __thrd_final(int32_t retval, int32_t data, struct ExecBase *sysbase)
{
    DECLARE_UTILITYBASE();

    (void) data;
    (void) sysbase;
    struct Task *task = FindTask(NULL);

    assert(__thrd_store_lock && __thrd_store);

    FOG(("%p Lock thread store mutex.\n", task));
    MutexObtain(__thrd_store_lock);

    /* Find thread. This can fail on out of memory in thrd_create(). */
    FOG(("%p Find thread in thread store.\n", task));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);

    if(unlikely(!thread))
    {
        FOG(("%p Unlock thread store mutex.\n", task));
        MutexRelease(__thrd_store_lock);
        return;
    }

    if(!atomic_flag_test_and_set(&(thread->gc)))
    {
        FOG(("%p Collect garbage.\n", task));
        RemoveSkipNode(__thrd_store, task);
    }
    else
    {
        FOG(("%p Get return value.\n", task));
        thread->retval = retval;
    }

    FOG(("%p Unlock thread store mutex.\n", task));
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
void __tss_store_purge(struct Task *task)
{
    (void) task;
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
    LEAVE();
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

    FOG(("%p Halt by locking thread store mutex.\n", task));
    MutexObtain(__thrd_store_lock);

    FOG(("%p Find thread in store.\n", task));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);

    FOG(("%p Unlock thread store mutex.\n", task));
    MutexRelease(__thrd_store_lock);

    if(unlikely(!thread))
    {
        FOG(("%p Thread not found.\n", task));
        return -1;
    }

    FOG(("%p Set thread exit point.\n", task));
    int32_t retval = setjmp(thread->stop);

    if(unlikely(retval))
    {
        FOG(("%p Free TSS.\n", task));
        __tss_store_purge(task);
        return retval;
    }

    FOG(("%p Invoke thread start function.\n", task));
    retval = thread->start(thread->arg);

    FOG(("%p Free TSS.\n", task));
    __tss_store_purge(task);

    return retval;
}

int thrd_create(thrd_t *thread, thrd_start_t start, void *arg)
{
    DECLARE_UTILITYBASE();
    assert(thread && start && __thrd_store && __thrd_store_lock);

    FOG(("Lock thread store mutex to halt new process.\n"));
    MutexObtain(__thrd_store_lock);

    FOG(("Spawn new process.\n"));
    *thread = (struct Task *) CreateNewProcTags(NP_Entry, __thrd_wrap,
        NP_FinalCode, __thrd_final, NP_Child, TRUE, TAG_END);

    if(unlikely(!*thread))
    {
        FOG(("%p Unlock thread store mutex.\n", thread));
        MutexRelease(__thrd_store_lock);
        return thrd_nomem;
    }

    FOG(("Create thread %p store entry.\n", *thread));
    __thrd_s *node = (__thrd_s *)
        InsertSkipNode(__thrd_store, *thread, sizeof(__thrd_s));

    if(unlikely(!node))
    {
        FOG(("%p Unlock thread store mutex.\n", thread));
        MutexRelease(__thrd_store_lock);
        return thrd_nomem;
    }

    FOG(("Reset garbage collection in thread %p.\n", thread));
    atomic_flag_clear(&(node->gc));

    FOG(("Initialize user function in %p.\n", thread));
    node->start = start;
    node->arg = arg;
    node->retval = 0;

    FOG(("Unlock thread store mutex to unhalt process.\n"));
    MutexRelease(__thrd_store_lock);

    return thrd_success;
}
