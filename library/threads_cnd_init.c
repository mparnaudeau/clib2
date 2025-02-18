
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
 cnd_init

 Description: Refer to ISO/IEC 9899:2011 section 7.26.3.3 (p. 379).
 Input:       Ibid.
 Return:      Ibid.
*/
int cnd_init(cnd_t *cond)
{
#ifdef THRD_PARANOIA
    if(unlikely(!cond))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }

    /* We're not alive yet. */
    atomic_store(&cond->dead, true);
#endif
    cond->mtx = AllocSysObjectTags(ASOT_MUTEX, TAG_END);
    FOG((THRD_ALLOC(cond->mtx)));

    /* List of listening tasks. */
    cond->tasks = (struct List *) AllocSysObjectTags(ASOT_LIST, TAG_END);
    FOG((THRD_ALLOC(cond->tasks)));

    if(unlikely(!cond->mtx || !cond->tasks))
    {
        /* Out of memory. */
        FOG((THRD_FREE(cond->mtx)));
        FreeSysObject(ASOT_MUTEX, cond->mtx);

        FOG((THRD_FREE(cond->tasks)));
        FreeSysObject(ASOT_LIST, cond->tasks);

        FOG((THRD_NOMEM));
        return thrd_nomem;
    }

#ifdef THRD_PARANOIA
    /* Now we're alive. */
    atomic_store(&cond->dead, false);
#endif
    FOG((THRD_SUCCESS));
    return thrd_success;
}
