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
 thrd_exit

 Description: Refer to ISO/IEC 9899:2011 section 7.26.5.5 (p. 384).
 Input:       Ibid.
 Return:      Ibid.
*/
void thrd_exit(int retval)
{
    FOG((THRD_LOCK(__thrd_store_lock)));
    MutexObtain((APTR) __thrd_store_lock);

    DECLARE_UTILITYBASE();
    struct Task *task = FindTask(NULL);

    /* This can fail if invoked by process not created by thrd_create(). */
    __thrd_s *thread = (__thrd_s *) FindSkipNode(__thrd_store, task);
    FOG((THRD_FOUND(thread)));

    FOG((THRD_UNLOCK(__thrd_store_lock)));
    MutexRelease((APTR) __thrd_store_lock);

    if(unlikely(!thread))
    {
        return;
    }

    /* Exit point set in __thrd_wrap(). */
    longjmp(thread->stop, retval);
}
