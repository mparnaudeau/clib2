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

int cnd_broadcast(cnd_t *cond)
{
    ENTER();
    assert(cond && cond->mutex);

    TLOG(("Lock mutex.\n"));
    MutexObtain((APTR) cond->mutex);

    TLOG(("Signal all threads.\n"));
    __cnd_signal(cond, true);

    TLOG(("Unlock mutex.\n"));
    MutexRelease((APTR) cond->mutex);

    LEAVE();
    return thrd_success;
}
