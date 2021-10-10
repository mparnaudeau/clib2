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

struct List *__tss_store;
APTR __tss_store_lock;

/*------------------------------------------------------------------------------
 __tss_store_setup

 Description: Initialize TSS store. Invoked from setup() in stdlib_main.c.
 Input:       -
 Return:      bool - 'true' on success, 'false' otherwise.
*/
bool __tss_store_setup(void)
{
#ifdef THRD_PARANOIA
    static atomic_flag done = ATOMIC_FLAG_INIT;

    /* We shouldn't end up here more than once. */
    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG((THRD_PANIC));
        return __tss_store && __tss_store_lock;
    }
#endif
    /* Allocate TSS store. */
    FOG((THRD_ALLOC));
    __tss_store = (struct List *) AllocSysObjectTags(ASOT_LIST, TAG_END);

    /* Allocate TSS store mutex. */
    FOG((THRD_ALLOC));
    __tss_store_lock = AllocSysObjectTags(ASOT_MUTEX, TAG_END);

    if(unlikely(!__tss_store || !__tss_store_lock))
    {
        /* Out of memory. */
        FOG((THRD_FREE));
        FreeSysObject(ASOT_LIST, __tss_store);

        FOG((THRD_FREE));
        FreeSysObject(ASOT_MUTEX, __tss_store_lock);
    }

    FOG((__tss_store && __tss_store_lock ? THRD_TRUE : THRD_FALSE));
    return __tss_store && __tss_store_lock;
}

/*------------------------------------------------------------------------------
 __tss_store_free_values

 Description: Free TSS values in store entry.
 Input:       struct Node * - store entry.
 Return:      -
*/
static void __tss_store_free_values(struct Node *node)
{
    DECLARE_UTILITYBASE();
    tss_t *tss = &((__tss_n *) node)->tss;

    for(struct SkipNode *head = GetFirstSkipNode(tss->values); head;)
    {
        struct SkipNode *next = GetNextSkipNode(tss->values, head);

        FOG((THRD_FREE));
        RemoveSkipNode(tss->values, head->sn_Key);
        head = next;
    }

    FOG((THRD_FREE));
    DeleteSkipList(tss->values);
}

/*------------------------------------------------------------------------------
 __tss_store_teardown

 Description: Tear down TSS store. Invoked from teardown() or setup() in
              stdlib_main.c.
 Input:       -
 Return:      -
*/
void __tss_store_teardown(void)
{
#ifdef THRD_PARANOIA
    static atomic_flag done = ATOMIC_FLAG_INIT;

    /* We shouldn't end up here more than once. */
    if(unlikely(atomic_flag_test_and_set(&done)))
    {
        FOG((THRD_PANIC));
        return;
    }

    /* Locking the TSS store shouldn't be necessary since the only place where
     * this function is invoked is in teardown() in stdlib_main.c. It could be
     * that there's a user programming error leading to a thread trying to use
     * TSS due to a missing join. By locking the store, there's a small chance
     * that we'll halt until that thread is finished with any TSS operations.
     * Don't assume that the mutex exists since setup() in stdlib_main.c could
     * have failed. */
    if(likely(__tss_store_lock != NULL))
    {
        FOG((THRD_LOCK));
        MutexObtain(__tss_store_lock);
    }
#endif

    for(struct Node *head = GetHead(__tss_store); head;)
    {
        struct Node *next = GetSucc(head);
        __tss_store_free_values(head);

        FOG((THRD_REMOVE));
        Remove(head);

        FOG((THRD_FREE));
        FreeSysObject(ASOT_NODE, head);
        head = next;
    }

    /* Free empty TSS store list. */
    FOG((THRD_FREE));
    FreeSysObject(ASOT_LIST, __tss_store);
#ifdef THRD_PARANOIA
    if(likely(__tss_store_lock != NULL))
    {
        FOG((THRD_UNLOCK));
        MutexRelease(__tss_store_lock);
    }
#endif
    /* Free TSS store mutex. */
    FOG((THRD_FREE));
    FreeSysObject(ASOT_MUTEX, __tss_store_lock);
}

/*------------------------------------------------------------------------------
 __tss_store_purge

 Description: Remove and execute destructors for all TSS values of a task.
 Input:       struct Task *task - the task to purge.
 Return:      -
*/
void __tss_store_purge(__attribute__((unused)) struct Task *task)
{
    FOG((THRD_LOCK));
    MutexObtain(__tss_store_lock);

    DECLARE_UTILITYBASE();

    for(struct Node *head = GetHead(__tss_store); head;)
    {
        tss_t *tss = &((__tss_n *) head)->tss;

        FOG((THRD_FIND));
        struct SkipNode *node = FindSkipNode(tss->values, task);

        head = GetSucc(head);

        if(!node)
        {
            FOG((THRD_NOTFOUND));
            continue;
        }

        if(tss->destructor && ((__tss_v *) node)->value)
        {
            FOG((THRD_TRACE));
            tss->destructor(((__tss_v *) node)->value);
        }

        FOG((THRD_FREE));
        RemoveSkipNode(tss->values, task);
    }

    FOG((THRD_UNLOCK));
    MutexRelease(__tss_store_lock);
}

/*------------------------------------------------------------------------------
 __tss_store_insert

 Description: Insert TSS key in store.
 Input:       tss_t *tss_key - TSS key to insert.
 Return:      bool - On success 'true', 'false' otherwise.
*/
static bool __tss_store_insert(tss_t *tss_key)
{
    FOG((THRD_ALLOC));
    __tss_n *node = (__tss_n *) AllocSysObjectTags(ASOT_NODE, ASONODE_Size,
        sizeof(__tss_n), ASONODE_Type, NT_USER, TAG_END);

    if(unlikely(!node))
    {
        FOG((THRD_FALSE));
        return false;
    }

    FOG((THRD_TRACE));
    node->tss = *tss_key;

    FOG((THRD_LOCK));
    MutexObtain(__tss_store_lock);

    FOG((THRD_INSERT));
    AddHead(__tss_store, (struct Node *) node);

    FOG((THRD_UNLOCK));
    MutexRelease(__tss_store_lock);

    FOG((THRD_TRUE));
    return true;
}

/*------------------------------------------------------------------------------
 tss_create

 Description: Refer to ISO/IEC 9899:2011 section 7.26.6.1 (p. 386).
 Input:       Ibid.
 Return:      Ibid.
*/
int tss_create(tss_t *tss_key, tss_dtor_t destructor)
{
#ifdef THRD_PARANOIA
    if(unlikely(!tss_key))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    FOG((THRD_ALLOC));
    tss_key->mutex = AllocSysObjectTags(ASOT_MUTEX, TAG_END);

    static struct Hook tss_t_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    DECLARE_UTILITYBASE();

    FOG((THRD_ALLOC));
    tss_key->values = CreateSkipList(&tss_t_cmp_hook, 16);

    if(unlikely(!tss_key->mutex || !tss_key->values))
    {
        /* Out of memory. */
        FOG((THRD_FREE));
        FreeSysObject(ASOT_MUTEX, tss_key->mutex);

        FOG((THRD_FREE));
        DeleteSkipList(tss_key->values);
#ifdef THRD_PARANOIA
        tss_key->mutex = tss_key->values = NULL;
#endif
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_TRACE));
    tss_key->destructor = destructor;

    FOG((THRD_TRACE));
    if(unlikely(!__tss_store_insert(tss_key)))
    {
        /* Out of memory. */
        FOG((THRD_FREE));
        DeleteSkipList(tss_key->values);

        FOG((THRD_FREE));
        FreeSysObject(ASOT_MUTEX, tss_key->mutex);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_SUCCESS));
    return thrd_success;
}
