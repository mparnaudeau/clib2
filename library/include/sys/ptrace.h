#ifdef CLIB2_STUBS

#ifndef _PTRACE_H
#define _PTRACE_H

/* SVr4, 4.3BSD. */

#warning "STUB: sys/ptrace.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern long int ptrace(enum __ptrace_request request, pid_t pid, void *addr,
                       void *data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PTRACE_H */

#endif /* CLIB2_STUBS */
