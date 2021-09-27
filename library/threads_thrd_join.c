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

#include "threads_headers.h"

extern struct SkipList *__thrd_store;
extern APTR __thrd_store_lock;

/*------------------------------------------------------------------------------
 thrd_join

 Description: Refer to ISO/IEC 9899:2011 section 7.26.5.6 (p. 384-385).
 Input:       Ibid.
 Return:      Ibid.
*/
int thrd_join(thrd_t thread, int *retval)
{
    DECLARE_UTILITYBASE();
    assert(__thrd_store && __thrd_store_lock && thread);

    FOG((THRD_LOCK));
    MutexObtain(__thrd_store_lock);

    FOG((THRD_FIND));
    __thrd_s *node = (__thrd_s *) FindSkipNode(__thrd_store, thread);

    if(unlikely(!node) || atomic_flag_test_and_set(&(node->gc)))
    {
        FOG((THRD_UNLOCK));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_ALLOC));
    BYTE sigdeath = AllocSignal(-1);

    if(unlikely(sigdeath == -1))
    {
        FOG((THRD_UNLOCK));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    struct Process *proc = (struct Process *) thread;

    FOG((THRD_TRACE));
    proc->pr_DeathSigBit = sigdeath;

    FOG((THRD_TRACE));
    proc->pr_DeathSigTask = (APTR) FindTask(NULL);

    FOG((THRD_UNLOCK));
    MutexRelease(__thrd_store_lock);

    FOG((THRD_TRACE));
    Wait(1L << sigdeath);

    FOG((THRD_TRACE));
    SetSignal(0L, 1L << sigdeath);

    FOG((THRD_FREE));
    FreeSignal(sigdeath);

    if(retval)
    {
        FOG((THRD_TRACE));
        *retval = node->retval;
    }

    FOG((THRD_LOCK));
    MutexObtain(__thrd_store_lock);

    FOG((THRD_FREE));
    RemoveSkipNode(__thrd_store, thread);

    FOG((THRD_UNLOCK));
    MutexRelease(__thrd_store_lock);

    return thrd_success;
}
