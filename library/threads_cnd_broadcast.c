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

#include "threads_headers.h"

/*------------------------------------------------------------------------------
 cnd_broadcast

 Description: Refer to ISO/IEC 9899:2011 section 7.26.3.1 (p. 378).
 Input:       Ibid.
 Return:      Ibid.
*/
int cnd_broadcast(cnd_t *cond)
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
     * cnd_signal(). */
    FOG((THRD_SIGNAL));
    __cnd_signal(cond, true);

    FOG((THRD_UNLOCK));
    MutexRelease(cond->mtx);

    FOG((THRD_SUCCESS));
    return thrd_success;
}
