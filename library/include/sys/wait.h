#if defined(CLIB2_SYS_WAIT_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _WAIT_H
#define _WAIT_H

/* POSIX.1 */

#warning "STUB: sys/wait.h"

#include <sys/types.h>

typedef enum {
    SYS_WAIT_STUB_DUMMY
} idtype_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern pid_t wait(int *stat_loc);
extern pid_t waitpid(pid_t pid, int *stat_loc, int options);
extern int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WAIT_H */

#endif /* defined(CLIB2_SYS_WAIT_STUB) || defined(CLIB2_MULTUM_STUB) */
