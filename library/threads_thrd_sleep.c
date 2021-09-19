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

int thrd_sleep(const struct timespec *duration, struct timespec *remaining)
{
    /* Very crude sleep by converting timespec to ticks. */
    uint32_t nsecs_per_tick = 1000000000 / TICKS_PER_SECOND,
             nsecs_remain = duration->tv_nsec % nsecs_per_tick,
             nticks = duration->tv_nsec / nsecs_per_tick +
             duration->tv_sec * TICKS_PER_SECOND + (nsecs_remain ? 1 : 0);

    if(remaining)
    {
        remaining->tv_sec = remaining->tv_nsec = 0;
    }

    Delay(nticks);
    return 0;
}
