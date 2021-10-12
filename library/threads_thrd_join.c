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
    /* Prevent threads from exiting. */
    FOG((THRD_LOCK(__thrd_store_lock)));
    MutexObtain(__thrd_store_lock);

    DECLARE_UTILITYBASE();

    /* Find thread. This will fail if threads has exited already. */
    __thrd_s *node = (__thrd_s *) FindSkipNode(__thrd_store, thread);
    FOG((THRD_FOUND(node)));

    if(unlikely(!node) || atomic_flag_test_and_set(&(node->gc)))
    {
        /* Thread is no longer running. */
        FOG((THRD_UNLOCK(__thrd_store_lock)));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    /* Allocate signal to be sent by the joined thread upon exit. */
    BYTE sigdeath = AllocSignal(-1);
    FOG((THRD_ALLOC(sigdeath)));

    if(unlikely(sigdeath == -1))
    {
        /* Out of signals. */
        FOG((THRD_UNLOCK(__thrd_store_lock)));
        MutexRelease(__thrd_store_lock);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    /* Set signal to be sent to us by the joined thread upon exit. */
    struct Process *proc = (struct Process *) thread;

    proc->pr_DeathSigBit = sigdeath;
    proc->pr_DeathSigTask = (APTR) FindTask(NULL);

    /* Allow threads to exit. */
    FOG((THRD_UNLOCK(__thrd_store_lock)));
    MutexRelease(__thrd_store_lock);

    /* Wait for signal of death. */
    FOG((THRD_WAIT(sigdeath)));
    Wait(1L << sigdeath);

    SetSignal(0L, 1L << sigdeath);

    FOG((THRD_FREE(sigdeath)));
    FreeSignal(sigdeath);

    if(retval)
    {
        /* Save thread return value. */
        FOG((THRD_TRACE));
        *retval = node->retval;
    }

    /* Remove thread from thread store. */
    FOG((THRD_LOCK(__thrd_store_lock)));
    MutexObtain(__thrd_store_lock);

    FOG((THRD_FREE(node)));
    RemoveSkipNode(__thrd_store, thread);

    FOG((THRD_UNLOCK(__thrd_store_lock)));
    MutexRelease(__thrd_store_lock);

    FOG((THRD_SUCCESS));
    return thrd_success;
}
