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
 mtx_init

 Description: Refer to ISO/IEC 9899:2011 section 7.26.4.2 (p. 380).
 Input:       Ibid.
 Return:      Ibid.
*/
int mtx_init(mtx_t *mutex, int type)
{
#ifdef THRD_MTX_WARY
    if(unlikely(!mutex))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    /* Validate mutex type. See ref for valid combinations. */
    if(unlikely(!type || type >= (mtx_timed << 1) || ((type & mtx_timed) &&
      (type & mtx_plain))))
    {
#ifdef THRD_MTX_WARY
        mutex->mutex = NULL;
#endif
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_ALLOC));
    mutex->mutex = AllocSysObjectTags(ASOT_MUTEX, ASOMUTEX_Recursive,
        (type & mtx_recursive) ? TRUE : FALSE, TAG_END);

    if(unlikely(!mutex->mutex))
    {
        FOG((THRD_ERROR));
        return thrd_error;
    }

    /* Not strictly necessary, but save type anyway. */
    FOG((THRD_TRACE));
    mutex->type = type;

    FOG((THRD_SUCCESS));
    return thrd_success;
}
