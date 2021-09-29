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
    if(unlikely(!mutex || !mutex->mutex || !time_point))
    {
        FOG((THRD_PANIC));
        return thrd_error;
    }
#endif
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

    /* Lock is busy, resort to polling. */
    FOG((THRD_TRACE));
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

    /* Does time_point belong to the past or the future? */
    if(unlikely((then.tv_secs == now.tv_secs && then.tv_micro < now.tv_micro) ||
       then.tv_secs <  now.tv_secs))
    {
        return 0;
    }

    /* This is very rough but likely good enough for most use cases. */
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
    FOG((THRD_ALLOC));
    struct Library *LowLevelBase = OpenLibrary("lowlevel.library", 0L);

    if(unlikely(!LowLevelBase))
    {
        FOG((THRD_ERROR));
        return thrd_error;
    }

    FOG((THRD_ALLOC));
    struct LowLevelIFace *ILowLevel = (struct LowLevelIFace *)
        GetInterface(LowLevelBase, "main", 1, NULL);

    if(unlikely(!ILowLevel))
    {
        FOG((THRD_FREE));
        CloseLibrary(LowLevelBase);

        FOG((THRD_ERROR));
        return thrd_error;
    }

    struct EClockVal ctx = { 0 };
    (void) ElapsedTime(&ctx);

    FOG((THRD_TRACE));
    for(ULONG done = 0; done < time; done += ElapsedTime(&ctx))
    {
        int lock = poll(data);

        if(lock != thrd_busy)
        {
            FOG((THRD_FREE));
            DropInterface((struct Interface *) ILowLevel);

            FOG((THRD_FREE));
            CloseLibrary(LowLevelBase);

            FOG((THRD_TRACE));
            return lock;
        }

        FOG((THRD_WAIT));
        Delay(stride);
    }

    FOG((THRD_FREE));
    DropInterface((struct Interface *) ILowLevel);

    FOG((THRD_FREE));
    CloseLibrary(LowLevelBase);

    FOG((THRD_TIMEDOUT));
    return thrd_timedout;
}
