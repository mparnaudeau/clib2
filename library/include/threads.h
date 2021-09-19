#ifndef _THREADS_H
#define _THREADS_H

#ifndef	_STDATOMIC_H
#include <stdatomic.h>
#endif /* _STDATOMIC_H */

#ifndef	_STDINT_H
#include <stdint.h>
#endif /* _STDINT_H */

#ifndef _STDNORETURN_H
#include <stdnoreturn.h>
#endif /* _STDNORETURN_H */

#ifndef _TIME_H
#include <time.h>
#endif /* _TIME_H */

enum
{
    thrd_success,
    thrd_nomem,
    thrd_timedout,
    thrd_busy,
    thrd_error
};

enum
{
    mtx_plain =     1 << 0,
    mtx_recursive = 1 << 1,
    mtx_timed =     1 << 2
};

typedef struct
{
    atomic_uintptr_t mutex;
    int type;
} mtx_t;

#define ONCE_FLAG_INIT ATOMIC_FLAG_INIT
typedef atomic_flag once_flag;

typedef int (*thrd_start_t)(void *);
typedef struct Task *thrd_t;

typedef void(*tss_dtor_t)(void *);
typedef struct
{
    struct SkipList *values;
    tss_dtor_t destructor;
    atomic_uintptr_t mutex;
} tss_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int mtx_init(mtx_t *mutex, int type);
int mtx_lock(mtx_t *mutex);
int mtx_timedlock(mtx_t *restrict mutex, const struct timespec *restrict time_point);
int mtx_trylock(mtx_t *mutex);
int mtx_unlock(mtx_t *mutex);
void mtx_destroy(mtx_t *mutex);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _THREADS_H */
