#if defined(CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _PTRACE_H
#define _PTRACE_H

/* SVr4, 4.3BSD. */

#warning "STUB: sys/ptrace.h"

#include <sys/types.h>

enum ___ptrace_request_stub_dummy {
    PTRACE_STUB_DUMMY
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern long int ptrace(enum ___ptrace_request_stub_dummy request, pid_t pid,
                       void *addr, void *data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PTRACE_H */

#endif /* defined(CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB) */
