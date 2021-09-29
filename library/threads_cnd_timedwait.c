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
 cnd_timedwait

 Description: Refer to ISO/IEC 9899:2011 section 7.26.3.5 (p. 379-380).
 Input:       Ibid.
 Return:      Ibid.
*/
int cnd_timedwait(cnd_t *cond, mtx_t *mutex,
                  const struct timespec *restrict time_point)
{
#ifdef THRD_PARANOIA
    /* __cnd_wait will behave like cnd_wait() if !time_point. */
    if(unlikely(!cond || !cond->mutex || !mutex || !time_point))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    FOG((THRD_TRACE));
    return __cnd_wait(cond, mutex, time_point);
}
