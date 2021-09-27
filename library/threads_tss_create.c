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

struct List *__tss_store = NULL;
atomic_uintptr_t __tss_store_lock = 0;

/*------------------------------------------------------------------------------
 __tss_store_init

 Description: Initialize store.
 Input:       -
 Return:      bool: On success 'true', 'false' otherwise.
*/
static bool __tss_store_init(void)
{
    FOG((THRD_ALLOC));
    int status = __thrd_mutex_replace(&__tss_store_lock);

    if(unlikely(status == thrd_error))
    {
        FOG((THRD_FALSE));
        return false;
    }

    if(unlikely(status == thrd_busy))
    {
        FOG((THRD_UNLOCK));
        MutexRelease((APTR) __tss_store_lock);

        FOG((THRD_TRACE));
        return __tss_store != NULL;
    }

    FOG((THRD_ALLOC));
    __tss_store = (struct List *) AllocSysObjectTags(ASOT_LIST, TAG_END);

    if(unlikely(!__tss_store))
    {
        FOG((THRD_FREE));
        __thrd_mutex_free(&__tss_store_lock);

        FOG((THRD_FALSE));
        return false;
    }

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) __tss_store_lock);

    FOG((THRD_TRUE));
    return true;
}

static atomic_flag __tss_store_active = ATOMIC_FLAG_INIT;

/*------------------------------------------------------------------------------
 __tss_store_insert

 Description: Insert TSS key in store.
 Input:       tss_t *tss_key - TSS key to insert.
 Return:      bool - On success 'true', 'false' otherwise.
*/
static bool __tss_store_insert(tss_t *tss_key)
{
    assert(tss_key);

    if(unlikely(!atomic_flag_test_and_set(&__tss_store_active) &&
       !__tss_store_init()))
    {
        FOG((THRD_TRACE));
        atomic_flag_clear(&__tss_store_active);

        FOG((THRD_FALSE));
        return false;
    }

    FOG((THRD_ALLOC));
    __tss_n *node = (__tss_n *)
        AllocSysObjectTags(ASOT_NODE, ASONODE_Size, sizeof(__tss_n),
        ASONODE_Type, NT_USER, TAG_END);

    if(unlikely(!node))
    {
        FOG((THRD_FALSE));
        return false;
    }

    FOG((THRD_TRACE));
    node->tss = *tss_key;

    FOG((THRD_LOCK));
    MutexObtain((APTR) __tss_store_lock);

    FOG((THRD_TRACE));
    AddTail(__tss_store, (struct Node *) node);

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) __tss_store_lock);

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
    DECLARE_UTILITYBASE();
    assert(tss_key);

    static struct Hook tss_t_cmp_hook =
    {
        .h_Entry = (uint32 (*)()) __thrd_ptr_cmp_callback
    };

    FOG((THRD_ALLOC));
    if(unlikely(!__thrd_mutex_create(&tss_key->mutex, true)))
    {
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_ALLOC));
    tss_key->values = CreateSkipList(&tss_t_cmp_hook, 16);

    if(unlikely(!tss_key->values))
    {
        FOG((THRD_FREE));
        __thrd_mutex_free(&tss_key->mutex);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_TRACE));
    tss_key->destructor = destructor;

    FOG((THRD_TRACE));
    if(unlikely(!__tss_store_insert(tss_key)))
    {
        FOG((THRD_FREE));
        DeleteSkipList(tss_key->values);

        FOG((THRD_FREE));
        __thrd_mutex_free(&tss_key->mutex);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) tss_key->mutex);

    FOG((THRD_SUCCESS));
    return thrd_success;
}
