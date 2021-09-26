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
    ENTER();
    assert(tss_key.mutex);

    FOG(("Lock mutex.\n"));
    MutexObtain((APTR) tss_key.mutex);

    FOG(("Find value.\n"));
    struct Task *key = FindTask(NULL);
    __tss_v *tss = (__tss_v *) FindSkipNode(tss_key.values, key);

    if(!tss)
    {
        FOG(("Create node.\n"));
        tss = (__tss_v *) InsertSkipNode(tss_key.values, key,
              sizeof(__tss_v));
    }

    if(unlikely(!tss))
    {
        MutexRelease((APTR) tss_key.mutex);

        LEAVE();
        return thrd_error;
    }

    FOG(("Set value.\n"));
    tss->value = val;

    FOG(("Unlock mutex.\n"));
    MutexRelease((APTR) tss_key.mutex);

    LEAVE();
    return thrd_success;
}
