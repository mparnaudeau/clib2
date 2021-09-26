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

int thrd_join(thrd_t thread, int *retval)
{
    ENTER();
    DECLARE_UTILITYBASE();
    assert(thread);

    if(!__thrd_store)
    {
        LEAVE();
        return thrd_error;
    }

    FOG(("%p Lock thread store mutex.\n", thread));
    MutexObtain((APTR) __thrd_store_lock);

    FOG(("%p Find thread in thread store.\n", thread));
    __thrd_s *node = (__thrd_s *) FindSkipNode(__thrd_store, thread);

    FOG(("%p Unlock thread store mutex.\n", thread));
    MutexRelease((APTR) __thrd_store_lock);

    if(unlikely(!node) || atomic_exchange(&(node->gc), GC_DONE) == GC_DONE)
    {
        FOG(("%p Thread not found.\n", thread));

        LEAVE();
        return thrd_error;
    }

    FOG(("%p Found thread.\n", thread));

    while(atomic_load(&(node->gc)) == GC_DONE)
    {
        FOG(("%p Wait for signal of death from thread.\n", thread));
        Wait(SIGF_CHILD);

        FOG(("%p Clear signal of death.\n", thread));
        SetSignal(0L, SIGF_CHILD);
    }

    if(retval)
    {
        FOG(("%p Get thread return value %d.\n", thread, node->retval));
        *retval = node->retval;
    }

    FOG(("%p Lock thread store mutex.\n", thread));
    MutexObtain((APTR) __thrd_store_lock);

    FOG(("%p Garbage collect thread.\n", thread));
    RemoveSkipNode(__thrd_store, thread);

    FOG(("%p Unlock thread store mutex.\n", thread));
    MutexRelease((APTR) __thrd_store_lock);

    LEAVE();
    return thrd_success;
}
