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
    ENTER();

    TLOG(("Create locked TSS store mutex.\n"));
    int status = __thrd_mutex_replace(&__tss_store_lock);

    if(unlikely(status == thrd_error))
    {
        TLOG(("Out of memory.\n"));
        assert(!__tss_store_lock);

        LEAVE();
        return false;
    }

    assert(status != thrd_busy);

    if(unlikely(status == thrd_busy))
    {
        TLOG(("Init called more than once.\n"));

        TLOG(("Unlock TSS store mutex.\n"));
        MutexRelease((APTR) __tss_store_lock);

        LEAVE();
        return __tss_store != NULL;
    }

    TLOG(("Create TSS store.\n"));
    __tss_store = (struct List *) AllocSysObjectTags(ASOT_LIST, TAG_END);

    if(unlikely(!__tss_store))
    {
        TLOG(("Out of memory.\n"));

        TLOG(("Free TSS store mutex.\n"));
        __thrd_mutex_free(&__tss_store_lock);
        assert(!__tss_store_lock);

        LEAVE();
        return false;
    }

    TLOG(("Unlock TSS store lock.\n"));
    MutexRelease((APTR) __tss_store_lock);

    LEAVE();
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
    ENTER();
    assert(tss_key);

    /* Init store once only. */
    static atomic_flag init = ATOMIC_FLAG_INIT;

    if(unlikely(!atomic_flag_test_and_set(&init) && !__tss_store_init()))
    {
        TLOG(("Out of memory.\n"));
        atomic_flag_clear(&init);

        LEAVE();
        return false;
    }

    TLOG(("Create TSS node.\n"));
    __tss_n *node = (__tss_n *)
        AllocSysObjectTags(ASOT_NODE, ASONODE_Size, sizeof(__tss_n),
        ASONODE_Type, NT_USER, TAG_END);

    if(unlikely(!node))
    {
        TLOG(("Out of memory.\n"));

        LEAVE();
        return false;
    }

    TLOG(("Initialize TSS node.\n"));
    node->tss = *tss_key;

    TLOG(("Lock TSS store mutex.\n"));
    MutexObtain((APTR) __tss_store_lock);

    TLOG(("Insert TSS node in store.\n"));
    AddTail(__tss_store, (struct Node *) node);

    TLOG(("Unlock TSS store mutex.\n"));
    MutexRelease((APTR) __tss_store_lock);

    LEAVE();
    return true;
}

int tss_create(tss_t *tss_key, tss_dtor_t destructor)
{
    ENTER();
    assert(tss_key);

    static struct Hook tss_t_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    TLOG(("Create locked mutex.\n"));
    if(unlikely(!__thrd_mutex_create(&tss_key->mutex, true)))
    {
        TLOG(("Out of memory.\n"));

        LEAVE();
        return thrd_error;
    }

    TLOG(("Create value skip list.\n"));
    tss_key->values = CreateSkipList(&tss_t_cmp_hook, 16);

    if(unlikely(!tss_key->values))
    {
        TLOG(("Out of memory.\n"));

        TLOG(("Free mutex.\n"));
        __thrd_mutex_free(&tss_key->mutex);
        assert(!tss_key->mutex);

        LEAVE();
        return thrd_error;
    }

    TLOG(("Set destructor.\n"));
    tss_key->destructor = destructor;

    TLOG(("Insert key in global TSS store.\n"));
    if(unlikely(!__tss_store_insert(tss_key)))
    {
        TLOG(("Out of memory.\n"));

        TLOG(("Free value skip list.\n"));
        DeleteSkipList(tss_key->values);

        TLOG(("Free mutex.\n"));
        __thrd_mutex_free(&tss_key->mutex);
        assert(!tss_key->mutex);

        LEAVE();
        return thrd_error;
    }

    TLOG(("Unlock mutex.\n"));
    MutexRelease((APTR) tss_key->mutex);

    LEAVE();
    return thrd_success;
}
