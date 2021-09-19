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

int tss_set(tss_t tss_key, void *val)
{
    IExec->MutexObtain((APTR) tss_key.mutex);

    /* Search for existing value. */
    struct Task *key = IExec->FindTask(NULL);
    __tss_v *tss = (__tss_v *) IUtility->FindSkipNode(tss_key.values, key);

    if(!tss)
    {
        /* No existing value, create new node. */
        tss = (__tss_v *) IUtility->InsertSkipNode(tss_key.values, key,
              sizeof(__tss_v));
    }

    if(unlikely(!tss))
    {
        /* Out of memory. */
        IExec->MutexRelease((APTR) tss_key.mutex);
        return thrd_error;
    }

    /* Set or update value. */
    tss->value = val;

    IExec->MutexRelease((APTR) tss_key.mutex);
    return thrd_success;
}
