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

struct List *__tss_store = NULL;
atomic_uintptr_t __tss_store_lock = 0;

/*------------------------------------------------------------------------------
 __tss_store_init

 Description: Initialize TSS store.
 Input:       -
 Return:      bool: On success 'true', 'false' otherwise.
*/
static bool __tss_store_init(void)
{
    int status = __thrd_mutex_replace(&__tss_store_lock);

    if(unlikely(status == thrd_error))
    {
        /* Out of memory. */
        return false;
    }

    /* This should never happen. */
    if(unlikely(status == thrd_busy))
    {
        IExec->MutexRelease((APTR) __tss_store_lock);
        return __tss_store != NULL;
    }

    /* Create global TSS store. */
    __tss_store = (struct List *) IExec->AllocSysObjectTags(ASOT_LIST, TAG_END);

    if(unlikely(!__tss_store))
    {
        /* Out of memory. */
        __thrd_mutex_free(&__tss_store_lock);
        return false;
    }

    IExec->MutexRelease((APTR) __tss_store_lock);
    return true;
}

/*------------------------------------------------------------------------------
 __tss_store_insert

 Description: Insert TSS key in store.
 Input:       tss_t *tss_key - TSS key to insert.
 Return:      bool - On success 'true', 'false' otherwise.
*/
static bool __tss_store_insert(tss_t *tss_key)
{
    static atomic_flag init = ATOMIC_FLAG_INIT;

    /* Init store once only. */
    if(unlikely(!atomic_flag_test_and_set(&init) && !__tss_store_init()))
    {
        /* Out of memory. */
        atomic_flag_clear(&init);
        return false;
    }

    /* Create list node. */
    __tss_n *node = (__tss_n *)
        IExec->AllocSysObjectTags(ASOT_NODE, ASONODE_Size, sizeof(__tss_n),
        ASONODE_Type, NT_USER, TAG_END);

    if(unlikely(!node))
    {
        /* Out of memory. */
        return false;
    }

    /* Initialize node. */
    node->tss = *tss_key;

    /* Insert node in store list. */
    IExec->MutexObtain((APTR) __tss_store_lock);
    IExec->AddTail(__tss_store, (struct Node *) node);
    IExec->MutexRelease((APTR) __tss_store_lock);
    return true;
}

int tss_create(tss_t *tss_key, tss_dtor_t destructor)
{
    static struct Hook tss_t_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    /* Mutex is locked from birth. */
    if(unlikely(!__thrd_mutex_create(&tss_key->mutex, true)))
    {
        /* Out of memory. */
        return thrd_error;
    }

    /* Values are stored in a skip list. */
    tss_key->values = IUtility->CreateSkipList(&tss_t_cmp_hook, 16);

    if(unlikely(!tss_key->values))
    {
        /* Out of memory. */
        __thrd_mutex_free(&tss_key->mutex);
        return thrd_error;
    }

    /* Set destructor. */
    tss_key->destructor = destructor;

    /* Insert in global TSS store. */
    if(unlikely(!__tss_store_insert(tss_key)))
    {
        /* Out of memory. */
        IUtility->DeleteSkipList(tss_key->values);
        __thrd_mutex_free(&tss_key->mutex);
        return thrd_error;
    }

    IExec->MutexRelease((APTR) tss_key->mutex);
    return thrd_success;
}

