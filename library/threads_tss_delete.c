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

extern struct List *__tss_store;
extern atomic_uintptr_t __tss_store_lock;

/*------------------------------------------------------------------------------
 tss_delete

 Description: Refer to ISO/IEC 9899:2011 section 7.26.6.1 (p. 386).
 Input:       Ibid.
 Return:      Ibid.
*/
void tss_delete(tss_t tss_key)
{
    assert(__tss_store_lock && tss_key.mutex);

    FOG((THRD_LOCK));
    MutexObtain((APTR) __tss_store_lock);

    for(struct Node *head = GetHead(__tss_store); head;)
    {
        tss_t *tss = &((__tss_n *) head)->tss;

        FOG((THRD_TRACE));
        head = GetSucc(head);

        if(tss->values == tss_key.values)
        {
            FOG((THRD_TRACE));
            tss->values = NULL;
            break;
        }
    }

/*
DEN HÄR MÅSTE DU VERKLIGEN KOLLA
*/

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) __tss_store_lock);

    FOG((THRD_LOCK));
    MutexObtain((APTR) tss_key.mutex);

    FOG((THRD_FREE));
    DeleteSkipList(tss_key.values);
    tss_key.values = NULL;

    FOG((THRD_UNLOCK));
    MutexRelease((APTR) tss_key.mutex);
}
