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
extern APTR __thrd_store_lock;

int thrd_join(thrd_t thread, int *retval)
{
    DECLARE_UTILITYBASE();
    assert(__thrd_store && __thrd_store_lock && thread);

    FOG(("%p Lock thread store mutex.\n", thread));
    MutexObtain(__thrd_store_lock);

    FOG(("%p Find thread in thread store.\n", thread));
    __thrd_s *node = (__thrd_s *) FindSkipNode(__thrd_store, thread);

    if(unlikely(!node) || atomic_flag_test_and_set(&(node->gc)))
    {
        FOG(("%p Unlock thread store mutex.\n", thread));
        MutexRelease(__thrd_store_lock);

        FOG(("%p Thread not found.\n", thread));
        return thrd_error;
    }

    FOG(("Allocate death signal.\n"));
    BYTE sigdeath = AllocSignal(-1);

    if(unlikely(sigdeath == -1))
    {
        FOG(("%p Unlock thread store mutex.\n", thread));
        MutexRelease(__thrd_store_lock);

        FOG(("%p No free signals.\n", thread));
        return thrd_error;
    }

    struct Process *proc = (struct Process *) thread;

    FOG(("%p Set death signal.\n", thread));
    proc->pr_DeathSigBit = sigdeath;

    FOG(("%p Set death signal receiver.\n", thread));
    proc->pr_DeathSigTask = (APTR) FindTask(NULL);

    FOG(("%p Unlock thread store mutex.\n", thread));
    MutexRelease(__thrd_store_lock);

    FOG(("%p Wait for death signal.\n", thread));
    Wait(1L << sigdeath);

    FOG(("%p Got death signal.\n", thread));

    FOG(("%p Lock thread store mutex.\n", thread));
    MutexObtain(__thrd_store_lock);

    FOG(("%p Clear death signal.\n", thread));
    SetSignal(0L, 1L << sigdeath);

    FOG(("%p Free death signal.\n", thread));
    FreeSignal(sigdeath);

    if(retval)
    {
        FOG(("%p Get return value %d.\n", thread, node->retval));
        *retval = node->retval;
    }

    FOG(("%p Garbage collect thread.\n", thread));
    RemoveSkipNode(__thrd_store, thread);

    FOG(("%p Unlock thread store mutex.\n", thread));
    MutexRelease(__thrd_store_lock);

    return thrd_success;
}
