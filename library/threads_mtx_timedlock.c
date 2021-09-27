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
 __mtx_trylock_callback

 Description: Polling mutex callback used in combination with __eclock_poll.
 Input:       void *data - callback function input data.
 Return:      int - 'thrd_success' if conditions are met in time,
              'thrd_timedout' on timeout and 'thrd_error' on error.
*/
static int __mtx_trylock_callback(void *data)
{
    assert(data);

    FOG((THRD_TRACE));
    return mtx_trylock((mtx_t *) data);
}

/*------------------------------------------------------------------------------
 mtx_timedlock

 Description: Refer to ISO/IEC 9899:2011 section 7.26.4.4 (p. 381-382).
 Input:       Ibid.
 Return:      Ibid.
*/
int mtx_timedlock(mtx_t *restrict mutex,
                  const struct timespec *restrict time_point)
{
    assert(mutex && mutex->mutex && time_point);

    /* Not strictly necessary, but validate type anyway. */
    if(unlikely(!(mutex->type & mtx_timed)))
    {
        FOG((THRD_ERROR));
        return thrd_error;
    }

    /* First locking attempt before polling. */
    if(mtx_trylock(mutex) == thrd_success)
    {
        FOG((THRD_SUCCESS));
        return thrd_success;
    }

    FOG((THRD_TRACE));
    /* Lock is busy, resort to polling. */
    return __eclock_poll(__mtx_trylock_callback, mutex,
        __eclock_future(time_point), POLL_STRIDE);
}
