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
 cnd_destroy

 Description: Refer to ISO/IEC 9899:2011 section 7.26.3.2 (p. 378-379).
 Input:       Ibid.
 Return:      Ibid.
*/
void cnd_destroy(cnd_t *cond)
{
    ENTER();
    assert(cond && cond->mutex);

    FOG((THRD_LOCK));
    MutexObtain((APTR) cond->mutex);

    FOG((THRD_SIGNAL));
    (void) __cnd_signal(cond, true);

    FOG((THRD_FREE));
    FreeSysObject(ASOT_LIST, cond->tasks);

    FOG((THRD_FREE));
    __thrd_mutex_free(&cond->mutex);
}
