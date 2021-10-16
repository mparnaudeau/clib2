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
#include <time.h>
#include <sys/time.h>

/*------------------------------------------------------------------------------
 __mtx_trylock_callback

 Description: Polling mutex callback used in combination with __eclock_poll.
 Input:       void *data - callback function input data.
 Return:      int - 'thrd_success' if conditions are met in time,
              'thrd_timedout' on timeout and 'thrd_error' on error.
*/
static int __mtx_trylock_callback(void *data)
{
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
#ifdef THRD_PARANOIA
    if(unlikely(!mutex || !time_point || !atomic_load(&mutex->type)))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
    if(unlikely((mutex->type & mtx_timed) == 0))
    {
        /* Invalid type. */
        FOG((THRD_ERROR));
        return thrd_error;
    }

    /* Do a first attempt before resorting to polling. */
    int status = mtx_trylock(mutex);

    if(status != thrd_busy)
    {
        /* Obtained lock or failed misserably. */
        FOG((status == thrd_success ? THRD_SUCCESS : THRD_ERROR));
        return status;
    }

    /* Lock is busy. Start polling. */
    return __eclock_poll(__mtx_trylock_callback, mutex,
        __eclock_future(time_point), POLL_STRIDE);
}

/*------------------------------------------------------------------------------
 __eclock_future

 Description: Calculate how far into the future a timespec point is in eclocks.
 Input:       const struct timespec *restrict time_point - time point.
 Return:      ULONG: Number of eclocks until time_point is reached.
*/

ULONG __eclock_future(const struct timespec *restrict time_point)
{
    struct timeval now, then = { .tv_secs = time_point->tv_sec,
           .tv_micro = time_point->tv_nsec / 1000 };

    gettimeofday(&now, NULL);

    if(unlikely((then.tv_secs == now.tv_secs && then.tv_micro < now.tv_micro) ||
       then.tv_secs <  now.tv_secs))
    {
        /* time_point already past. */
        return 0;
    }

    /* This is rough, but good enough for most use cases. */
    time_t secs = then.tv_secs - now.tv_secs -
           ((then.tv_micro < now.tv_micro) ? 1 : 0),
           usecs = (then.tv_micro < now.tv_micro) ? 1000000 -
           (now.tv_micro - then.tv_micro) : then.tv_micro - now.tv_micro;

    return ((ULONG) usecs >> 4) + ((ULONG) secs << 16);
}
/*------------------------------------------------------------------------------
 __eclock_poll

 Description: Poll callback until timeout or until conditions are met.
 Input:       int (*)(void *) - callback function.
              void *data - callback function input data.
              ULONG time - time scope in eclocks.
              ULONG stride - polling interval in ticks.
 Return:      int - 'thrd_success' if conditions are met in time,
              'thrd_timedout' on timeout and 'thrd_error' on error.
*/
int __eclock_poll(int (*poll)(void *), void *data, ULONG time, ULONG stride)
{
    struct Library *LowLevelBase = OpenLibrary("lowlevel.library", 0L);
    FOG((THRD_ALLOC(LowLevelBase)));

    if(unlikely(!LowLevelBase))
    {
        FOG((THRD_ERROR));
        return thrd_error;
    }

    struct LowLevelIFace *ILowLevel = (struct LowLevelIFace *)
        GetInterface(LowLevelBase, "main", 1, NULL);
    FOG((THRD_ALLOC(ILowLevel)));

    if(unlikely(!ILowLevel))
    {
        FOG((THRD_FREE(LowLevelBase)));
        CloseLibrary(LowLevelBase);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    struct EClockVal ctx = { 0 };
    (void) ElapsedTime(&ctx);

    for(ULONG done = 0; done < time; done += ElapsedTime(&ctx))
    {
        int lock = poll(data);

        if(lock != thrd_busy)
        {
            FOG((THRD_FREE(ILowLevel)));
            DropInterface((struct Interface *) ILowLevel);

            FOG((THRD_FREE(LowLevelBase)));
            CloseLibrary(LowLevelBase);

            FOG((lock == thrd_success ? THRD_SUCCESS : THRD_ERROR));
            return lock;
        }

        Delay(stride);
    }

    FOG((THRD_FREE(ILowLevel)));
    DropInterface((struct Interface *) ILowLevel);

    FOG((THRD_FREE(LowLevelBase)));
    CloseLibrary(LowLevelBase);

    FOG((THRD_TIMEDOUT));
    return thrd_timedout;
}
