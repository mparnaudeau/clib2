#ifdef CLIB2_STUBS

#ifndef _WAIT_H
#define _WAIT_H

/* POSIX.1 */

#warning "STUB: sys/wait.h"

typedef enum {
    P_ALL = 0,
    P_PID = 1,
    P_PGID = 2,
    P_PIDFD = 3
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

#endif /* CLIB2_STUBS */
