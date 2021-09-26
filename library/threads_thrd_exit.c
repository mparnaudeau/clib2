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

extern struct SkipList *__thrd_store;
extern atomic_uintptr_t __thrd_store_lock;

void thrd_exit(int retval)
{
    ENTER();
    assert(__thrd_store_lock);

    FOG(("Lock thread store mutex.\n"));
    MutexObtain((APTR) __thrd_store_lock);

    FOG(("Find current thread.\n"));
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, FindTask(NULL));

    FOG(("Unlock thread store mutex.\n"));
    MutexRelease((APTR) __thrd_store_lock);

    if(unlikely(!thread))
    {
        LEAVE();
        return;
    }

    FOG(("Jump to exit point.\n"));
    longjmp(thread->stop, retval);
}
