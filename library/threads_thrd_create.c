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

    LOG(("Clear mutex.\n"));
    atomic_uintptr_t mutex = atomic_exchange(target, 0);

    if(unlikely(!mutex))
    {
        LEAVE();
        return;
    }

    LOG(("Unlock mutex.\n"));
    MutexRelease((APTR) mutex);

    LOG(("Free mutex.\n"));
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

    LOG(("Create mutex.\n"));
    atomic_uintptr_t mutex = (atomic_uintptr_t)
        AllocSysObjectTags(ASOT_MUTEX, ASOMUTEX_Recursive,
        rec ? TRUE : FALSE, TAG_END);

    LOG(("Store mutex.\n"));
    atomic_store(target, mutex);

    if(unlikely(!mutex))
    {
        LEAVE();
        return false;
    }

    LOG(("Lock mutex.\n"));
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

    LOG(("Create mutex.\n"));
    if(unlikely(!__thrd_mutex_create(&mutex, true)))
    {
        LEAVE();
        return thrd_error;
    }

    LOG(("Exchange mutex.\n"));
    atomic_uintptr_t old = atomic_exchange(target, mutex);

    if(likely(!old))
    {
        LEAVE();
        return thrd_success;
    }

    LOG(("Lock old mutex.\n"));
    MutexObtain((APTR) old);

    LOG(("Unlock old mutex.\n"));
    MutexRelease((APTR) old);

    LOG(("Free old mutex.\n"));
    FreeSysObject(ASOT_MUTEX, (APTR) old);

    LEAVE();
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
    ENTER();

    (void) hook;
    LONG status = (lhs < rhs) ? -1 : (lhs > rhs) ? 1 : 0;

    LEAVE();
    return status;
}

/*------------------------------------------------------------------------------
 __thrd_store_init

 Description: Initialize thread store.
 Input:       -
 Return:      bool - 'true' on success, 'false' otherwise.
*/
static bool __thrd_store_init(void)
{
    ENTER();
    DECLARE_UTILITYBASE();

    static struct Hook __thrd_ptr_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    LOG(("Create locked thread store mutex.\n"));
    int status = __thrd_mutex_replace(&__thrd_store_lock);

    if(unlikely(status == thrd_error))
    {
        LEAVE();
        return false;
    }

    if(unlikely(status == thrd_busy))
    {
        LOG(("Unlock thread store mutex.\n"));
        MutexRelease((APTR) __thrd_store_lock);

        LEAVE();
        return __thrd_store != NULL;
    }

    LOG(("Create thread store skip list.\n"));
    __thrd_store = CreateSkipList(&__thrd_ptr_cmp_hook, 16);

    if(unlikely(!__thrd_store))
    {
        __thrd_mutex_free(&__thrd_store_lock);

        LEAVE();
        return false;
    }

    LOG(("Unlock thread store mutex.\n"));
    MutexRelease((APTR) __thrd_store_lock);

    LEAVE();
    return true;
}

static atomic_flag __thrd_store_active = ATOMIC_FLAG_INIT;

/*------------------------------------------------------------------------------
 __thrd_final

 Description: Process finalization. Refer to CreateNewProcTags and NP_FinalCode.
 Input:       See NDK documentation.
 Return:      -
*/
static void __thrd_final(int32_t retval, int32_t data, struct ExecBase *sysbase)
{
    ENTER();
    DECLARE_UTILITYBASE();
    assert(__thrd_store && __thrd_store_lock);

    (void) data;
    (void) sysbase;
    struct Task *task = FindTask(NULL);

    LOG(("Lock thread store mutex.\n"));
    MutexObtain((APTR) __thrd_store_lock);

    LOG(("Find thread in store.\n"));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);

    if(unlikely(!thread))
    {
        LOG(("Thread not found.\n"));
        MutexRelease((APTR) __thrd_store_lock);

        LEAVE();
        return;
    }

    if(atomic_flag_test_and_set(&(thread->gc)))
    {
        LOG(("Garbage collect thread.\n"));
        RemoveSkipNode(__thrd_store, task);

        if(!GetFirstSkipNode(__thrd_store))
        {
            LOG(("Free empty thread store.\n"));
            DeleteSkipList(__thrd_store);

            LOG(("Clear thread store ok.\n"));
            atomic_flag_clear(&__thrd_store_active);

            LOG(("Free thread store mutex.\n"));
            __thrd_mutex_free(&__thrd_store_lock);

            LEAVE();
            return;
        }
    }
    else
    {
        LOG(("Get thread return value.\n"));
        thread->retval = retval;
    }

    LOG(("Unlock thread store mutex.\n"));
    MutexRelease((APTR) __thrd_store_lock);

    LEAVE();
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
    ENTER();
    DECLARE_UTILITYBASE();
    assert(task);

    if(!atomic_load(&__tss_store))
    {
        LEAVE();
        return;
    }

    LOG(("Lock store mutex.\n"));
    MutexObtain((APTR) __tss_store_lock);

    for(struct Node *head = GetHead(__tss_store); head;)
    {
        tss_t *tss = &((__tss_n *) head)->tss;

        LOG(("Find task value.\n"));
        struct SkipNode *node = FindSkipNode(tss->values, task);
        head = GetSucc(head);

        if(!node)
        {
            LOG(("No value.\n"));
            continue;
        }

        if(tss->destructor && ((__tss_v *) node)->value)
        {
            LOG(("Invoke destructor.\n"));
            tss->destructor(((__tss_v *) node)->value);
        }

        LOG(("Remove value.\n"));
        RemoveSkipNode(tss->values, task);
    }

    LOG(("Unlock store mutex.\n"));
    MutexRelease((APTR) __tss_store_lock);

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
    ENTER();
    DECLARE_UTILITYBASE();
    assert(__thrd_store && __thrd_store_lock);

    struct Task *task = FindTask(NULL);

    LOG(("Halt by locking thread store mutex.\n"));
    MutexObtain((APTR) __thrd_store_lock);

    LOG(("Find thread in store.\n"));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);

    LOG(("Unlock thread store mutex.\n"));
    MutexRelease((APTR) __thrd_store_lock);

    if(unlikely(!thread))
    {
        LOG(("Thread not found.\n"));

        LEAVE();
        return -1;
    }

    LOG(("Set thread exit point.\n"));
    int32_t retval = setjmp(thread->stop);

    if(unlikely(retval))
    {
        LOG(("Free TSS.\n"));
        __tss_store_purge(task);

        LEAVE();
        return retval;
    }

    LOG(("Invoke thread start function.\n"));
    retval = thread->start(thread->arg);

    LOG(("Free TSS.\n"));
    __tss_store_purge(task);

    LEAVE();
    return retval;
}

int thrd_create(thrd_t *thread, thrd_start_t start, void *arg)
{
    PUSHDEBUGLEVEL(2);

    ENTER();
    DECLARE_UTILITYBASE();
    assert(thread && start);

    if(unlikely(!atomic_flag_test_and_set(&__thrd_store_active) &&
       !__thrd_store_init()))
    {
        LOG(("Clear thread store ok.\n"));
        atomic_flag_clear(&__thrd_store_active);

        LEAVE();
        return thrd_nomem;
    }

    assert(__thrd_store && __thrd_store_lock);

    LOG(("Lock thread store mutex to halt new process.\n"));
    MutexObtain((APTR) __thrd_store_lock);

    LOG(("Create new process.\n"));
    *thread = (struct Task *) CreateNewProcTags(NP_Entry, __thrd_wrap,
        NP_FinalCode, __thrd_final, NP_Child, TRUE, NP_NotifyOnDeathSigTask,
        FindTask(NULL), TAG_END);

    if(unlikely(!*thread))
    {
        MutexRelease((APTR) __thrd_store_lock);

        LEAVE();
        return thrd_nomem;
    }

    LOG(("Create thread store entry.\n"));
    __thrd_s *node = (__thrd_s *)
        InsertSkipNode(__thrd_store, *thread, sizeof(__thrd_s));

    if(unlikely(!node))
    {
        MutexRelease((APTR) __thrd_store_lock);

        LEAVE();
        return thrd_nomem;
    }

    LOG(("Initialize thread.\n"));
    (void) atomic_flag_test_and_set(&(node->gc));
    node->start = start;
    node->arg = arg;
    node->retval = 0;

    LOG(("Unlock thread store mutex.\n"));
    MutexRelease((APTR) __thrd_store_lock);

    LEAVE();
    POPDEBUGLEVEL();
    return thrd_success;
}
