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

extern struct SkipList *__thrd_store;
extern atomic_uintptr_t __thrd_store_lock;

int thrd_join(thrd_t thread, int *retval)
{
    ENTER();
    assert(thread);

    if(!__thrd_store)
    {
        TLOG(("No threads.\n"));

        LEAVE();
        return thrd_error;
    }

    TLOG(("Lock thread store.\n"));
    MutexObtain((APTR) __thrd_store_lock);

    TLOG(("Find thread to be joined.\n"));
    __thrd_s *node = (__thrd_s *) FindSkipNode(__thrd_store, thread);

    if(unlikely(!node))
    {
        TLOG(("Thread not found.\n"));
        MutexRelease((APTR) __thrd_store_lock);

        LEAVE();
        return thrd_error;
    }

    do
    {
        TLOG(("Block garbage collection.\n"));
        atomic_flag_clear(&(node->gc));

        TLOG(("Unlock thread store.\n"));
        MutexRelease((APTR) __thrd_store_lock);

        TLOG(("Wait for signal of death.\n"));
        Wait(SIGF_CHILD);

        TLOG(("Received signal of death.\n"));
        SetSignal(0L, SIGF_CHILD);

        TLOG(("Lock thread store.\n"));
        MutexObtain((APTR) __thrd_store_lock);
    }
    while(!atomic_flag_test_and_set(&node->gc));

    if(retval)
    {
        TLOG(("Get thread return value.\n"));
        *retval = node->retval;
    }

    TLOG(("Garbage collect thread.\n"));
    RemoveSkipNode(__thrd_store, &thread);

    TLOG(("Unlock thread store.\n"));
    MutexRelease((APTR) __thrd_store_lock);

    LEAVE();
    return thrd_success;
}
