#ifndef _THREADS_HEADERS_H
#define _THREADS_HEADERS_H

#ifndef	PROTO_DOS_H
#include <proto/dos.h>
#endif /* PROTO_DOS_H */

#ifndef	PROTO_EXEC_H
#include <proto/exec.h>
#endif /* PROTO_EXEC_H */

#ifndef	PROTO_LOWLEVEL_H
#include <proto/lowlevel.h>
#endif /* PROTO_LOWLEVEL_H */

#ifndef	PROTO_UTILITY_H
#include <proto/utility.h>
#endif /* PROTO_UTILITY_H */

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif /* _STDBOOL_H */

#ifndef _ASSERTL_H
#include <assert.h>
#endif /* _ASSERT_H */

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

#define THRD_PARANOIA
#define POLL_STRIDE 5

/*------------------------------------------------------------------------------
 * thrd|tss|cnd|mtx
*/
LONG __thrd_ptr_cmp_callback(struct Hook *hook, APTR lhs, APTR rhs);
bool __thrd_store_setup(void);
void __thrd_store_teardown(void);
bool __tss_store_setup(void);
void __tss_store_teardown(void);
void __tss_store_purge(struct Task *task);
void __cnd_signal(cnd_t *cond, bool broadcast);
int __cnd_wait(cnd_t *cond, mtx_t *mutex,
    const struct timespec *restrict time_point);
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
    void *arg;
    int retval;
    jmp_buf stop;
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

/*------------------------------------------------------------------------------
 * cnd
*/
typedef struct
{
    struct Node node;
    struct Task *task;
    BYTE sigbit;
} __cnd_node;

/*------------------------------------------------------------------------------
 * debug
*/
#define FOG(...) DebugPrintF("%s:%d - ", __func__, __LINE__);\
    DebugPrintF __VA_ARGS__
#define THRD_ERROR "thrd_error.\n"
#define THRD_SUCCESS "thrd_success.\n"
#define THRD_BUSY "thrd_busy.\n"
#define THRD_NOMEM "thrd_nomem.\n"
#define THRD_TIMEDOUT "thrd_timedout.\n"
#define THRD_ALLOC(P) "Alloc %p.\n", P
#define THRD_FREE(P) "Free %p.\n", P
#define THRD_REMOVE(P) "Remove %p.\n", P
#define THRD_INSERT(P) "Insert %p.\n", P
#define THRD_LOCK(L) "Lock %p.\n", L
#define THRD_UNLOCK(L) "Unlock %p.\n", L
#define THRD_TRACE "Trace.\n"
#define THRD_FALSE "False.\n"
#define THRD_TRUE "True.\n"
#define THRD_FOUND(P) "Found %p.\n", P
#define THRD_SIGNAL(P, S) "Signal %p with %d.\n", P, S
#define THRD_WAIT(S) "Wait for %d.\n", S
#define THRD_PANIC "Panic.\n"

#endif /* _THREADS_HEADERS_H */
