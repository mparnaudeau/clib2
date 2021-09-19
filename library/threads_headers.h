#ifndef _THREADS_HEADERS_H
#define _THREADS_HEADERS_H

#ifndef _MACROS_H
#include "macros.h"
#endif /* _MACROS_H */

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

#include "include/threads.h"

/*------------------------------------------------------------------------------
 Thread list node.
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
 TSS skip list value node.
 */
typedef struct
{
    struct SkipNode node;
    void *value;
} __tss_v;

/*------------------------------------------------------------------------------
 TSS list node.
 */
typedef struct
{
    struct Node node;
    tss_t tss;
} __tss_n;


ULONG __eclock_future(const struct timespec *restrict time_point);
int __eclock_poll(int (*poll)(void *), void *data, ULONG time, ULONG stride);
LONG __thrd_ptr_cmp_callback(struct Hook *hook, APTR lhs, APTR rhs);
bool __thrd_mutex_create(atomic_uintptr_t *target, bool rec);
void __thrd_mutex_free(atomic_uintptr_t *target);
int __thrd_mutex_replace(atomic_uintptr_t *target);
void __tss_store_purge(struct Task *task);


#endif /* _THREADS_HEADERS_H */
