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
 tss_get

 Description: Refer to ISO/IEC 9899:2011 section 7.26.6.3 (p. 386).
 Input:       Ibid.
 Return:      Ibid.
*/
void *tss_get(tss_t tss_key)
{
#ifdef THRD_PARANOIA
    if(unlikely(!tss_key.mutex || !tss_key.values))
    {
        FOG((THRD_PANIC));
        return NULL;
    }
#endif
    FOG((THRD_LOCK(tss_key.mutex)));
    MutexObtain(tss_key.mutex);

    DECLARE_UTILITYBASE();
    struct Task *task = FindTask(NULL);

    __tss_v *tss = (__tss_v *) FindSkipNode(tss_key.values, task);

    FOG((THRD_FOUND(tss)));
    void *value = tss ? tss->value : NULL;

    FOG((THRD_UNLOCK(tss_key.mutex)));
    MutexRelease(tss_key.mutex);
    return value;
}
