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
    /* List is sorted by process priority. Descending order, the process with
     * the highest priority will be signaled first. */
    for(__cnd_node *head = (__cnd_node *) GetHead(cond->tasks), *next;
        head; head = next)
    {
        FOG((THRD_SIGNAL));
        Signal(head->task, 1L << head->sigbit);

        /* Break unless we're broadcasting. */
        next = broadcast ? (__cnd_node *)
            GetSucc((struct Node *) head) : NULL;

        /* Dequeue only. Task nodes are freed by the allocating task; the task
         * waiting for a signal. See cnd_wait() and __cnd_wait(). */
        FOG((THRD_REMOVE));
        Remove((struct Node *) head);
    }
}

/*------------------------------------------------------------------------------
 cnd_signal

 Description: Refer to ISO/IEC 9899:2011 section 7.26.3.4 (p. 379).
 Input:       Ibid.
 Return:      Ibid.
*/
int cnd_signal(cnd_t *cond)
{
#ifdef THRD_PARANOIA
    if(unlikely(!cond || atomic_load(&cond->dead)))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    FOG((THRD_LOCK));
    MutexObtain(cond->mtx);

    /* Both singles and broadcasts are supported by __cnd_signal(). See
     * cnd_broadcast(). */
    FOG((THRD_SIGNAL));
    __cnd_signal(cond, false);

    FOG((THRD_UNLOCK));
    MutexRelease(cond->mtx);

    FOG((THRD_SUCCESS));
    return thrd_success;
}
