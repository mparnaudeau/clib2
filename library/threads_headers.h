#ifndef _THREADS_HEADERS_H
#define _THREADS_HEADERS_H

#ifndef	PROTO_DOS_H
#include <proto/dos.h>
#endif /* PROTO_DOS_H */

#ifndef	PROTO_EXEC_H
#include <proto/exec.h>
#endif /* PROTO_EXEC_H */

#ifndef	PROTO_UTILITY_H
#include <proto/utility.h>
#endif /* PROTO_UTILITY_H */

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif /* _STDBOOL_H */

#ifndef _SETJMP_H
#include <setjmp.h>
#endif /* _SETJMP_H */

#ifndef _THREADS_H
#include <threads.h>
#endif /* _THREADS_H */

#ifndef _DEBUG_H
#include "debug.h"
#endif /* _DEBUG_H */

#ifndef _MACROS_H
#include "macros.h"
#endif /* _MACROS_H */

#ifndef _STDLIB_UTILITYBASE_H
#include "stdlib_utilitybase.h"
#endif /* _STDLIB_UTILITYBASE_H */

/*------------------------------------------------------------------------------
 * thrd|tss|mtx|cnd
*/
LONG __thrd_ptr_cmp_callback(struct Hook *hook, APTR lhs, APTR rhs);
bool __thrd_mutex_create(atomic_uintptr_t *target, bool rec);
void __thrd_mutex_free(atomic_uintptr_t *target);
int __thrd_mutex_replace(atomic_uintptr_t *target);
bool __thrd_store_setup(void);
void __thrd_store_teardown(void);

/*------------------------------------------------------------------------------
 * cnd|mtx
*/
#define POLL_STRIDE 5

ULONG __eclock_future(const struct timespec *restrict time_point);
int __eclock_poll(int (*poll)(void *), void *data, ULONG time, ULONG stride);

/*------------------------------------------------------------------------------
 * thrd
*/
typedef struct
{
    struct SkipNode node;
    thrd_start_t start;
    atomic_flag gc;
    jmp_buf stop;
    void *arg;
    int retval;
} __thrd_s;

/*------------------------------------------------------------------------------
 * tss
*/
typedef struct
{
    struct SkipNode node;
    void *value;
} __tss_v;

typedef struct
{
    struct Node node;
    tss_t tss;
} __tss_n;

void __tss_store_purge(struct Task *task);

/*------------------------------------------------------------------------------
 * cnd
*/

typedef struct
{
    struct Node node;
    struct Task *task;
    BYTE sigbit;
} __cnd_node;

void __cnd_signal(cnd_t *cond, bool broadcast);
int __cnd_wait(cnd_t *cond, mtx_t *mutex,
               const struct timespec *restrict time_point);

#define FOG(...) DebugPrintF("%s:%d - ", __func__, __LINE__); DebugPrintF __VA_ARGS__
//#define FOG(...)

#endif /* _THREADS_HEADERS_H */
