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

/*------------------------------------------------------------------------------
 __cnd_signal

 Description: Signal task(s) waiting for conditional.
 Input:       cnd_t *cond - conditional.
              bool broadcast - on 'true' signal all tasks and empty the queue of
              listeners, on 'false' signal and remove the first task only.
 Return:      -
*/
void __cnd_signal(cnd_t *cond, bool broadcast)
{
    ENTER();
    assert(cond && cond->mutex);

    for(__cnd_node *head = (__cnd_node *) GetHead(cond->tasks), *next;
        head; head = next)
    {
        FOG(("%p Signal task.\n", cond));
        Signal(head->task, 1L << head->sigbit);

        next = broadcast ? (__cnd_node *)
            GetSucc((struct Node *) head) : NULL;

        FOG(("%p Remove task from list of listeners.\n", cond));
        Remove((struct Node *) head);

        FOG(("%p Free task node.\n", cond));
        FreeSysObject(ASOT_NODE, head);
    }

    LEAVE();
}

int cnd_signal(cnd_t *cond)
{
    ENTER();
    assert(cond && cond->mutex);

    FOG(("%p Lock mutex %p.\n", cond, cond->mutex));
    MutexObtain((APTR) cond->mutex);

    FOG(("%p Single signal.\n", cond));
    __cnd_signal(cond, false);

    FOG(("%p Unlock mutex %p.\n", cond, cond->mutex));
    MutexRelease((APTR) cond->mutex);

    LEAVE();
    return thrd_success;
}
