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

void tss_delete(tss_t tss_key)
{
    ENTER();
    assert(__tss_store_lock && tss_key.mutex);

    TLOG(("Lock store mutex.\n"));
    MutexObtain((APTR) __tss_store_lock);

    TLOG(("Find key in store.\n"));
    for(struct Node *head = GetHead(__tss_store); head;)
    {
        tss_t *tss = &((__tss_n *) head)->tss;
        head = GetSucc(head);

        if(tss->values == tss_key.values)
        {
            TLOG(("Key found. Remove from store.\n"));
            tss->values = NULL;
            break;
        }
    }

/*
DEN HÄR MÅSTE DU VERKLIGEN KOLLA
*/

    TLOG(("Unlock store mutex.\n"));
    MutexRelease((APTR) __tss_store_lock);

    TLOG(("Lock key mutex.\n"));
    MutexObtain((APTR) tss_key.mutex);

    TLOG(("Free key values.\n"));
    DeleteSkipList(tss_key.values);
    tss_key.values = NULL;

    TLOG(("Unlock key mutex.\n"));
    MutexRelease((APTR) tss_key.mutex);

    LEAVE();
}
