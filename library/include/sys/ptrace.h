#if defined(CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _PTRACE_H
#define _PTRACE_H

/* SVr4, 4.3BSD. */

#warning "STUB: sys/ptrace.h"

enum __ptrace_request_dummy {
    int dummy;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern long int ptrace(enum __ptrace_request_dummy request, pid_t pid,
                       void *addr, void *data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PTRACE_H */

#endif /* defined(CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB) */
