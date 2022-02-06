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
    if(!__thrd_store)
    {
        /* Nothing to join. */
        return thrd_error;
    }

    /* Find thread to be joined. */
    IExec->MutexObtain((APTR) __thrd_store_lock);
    __thrd_s *node = (__thrd_s *)
        IUtility->FindSkipNode(__thrd_store, thread);

    if(unlikely(!node))
    {
        /* Thread is not running anymore. */
        IExec->MutexRelease((APTR) __thrd_store_lock);
        return thrd_error;
    }

    do
    {
        /* Disable __thrd_final garbage collection. */
        atomic_flag_clear(&(node->gc));

        /* Wait for signal of death. */
        IExec->MutexRelease((APTR) __thrd_store_lock);
        IExec->Wait(SIGF_CHILD);
        IExec->SetSignal(0L, SIGF_CHILD);
        IExec->MutexObtain((APTR) __thrd_store_lock);
    }
    while(!atomic_flag_test_and_set(&node->gc));

    if(retval)
    {
        /* Get thread return value. */
        *retval = node->retval;
    }

    /* Remove thread from thread store. */
    IUtility->RemoveSkipNode(__thrd_store, &thread);
    IExec->MutexRelease((APTR) __thrd_store_lock);
    return thrd_success;
}
