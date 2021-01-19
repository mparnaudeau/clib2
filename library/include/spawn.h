#if defined(CLIB2_SPAWN_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _SPAWN_H
#define _SPAWN_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: spawn.h"

#undef CLIB2_SCHED_STUB
#define CLIB2_SCHED_STUB

#include <sched.h>

typedef int posix_spawnattr_t;
typedef int posix_spawn_file_actions_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int posix_spawn(pid_t *pid, const char *path,
                       const posix_spawn_file_actions_t *file_actions,
                       const posix_spawnattr_t *attrp, char *const argv[],
                       char *const envp[]);
extern int posix_spawn_file_actions_addclose(
                       posix_spawn_file_actions_t *file_actions, int fildes);
extern int posix_spawn_file_actions_adddup2(
                       posix_spawn_file_actions_t *file_actions, int fildes,
                       int newfildes);
extern int posix_spawn_file_actions_addopen(
                       posix_spawn_file_actions_t *restrict file_actions,
                       int fildes, const char *restrict path, int oflag,
                       mode_t mode);
extern int posix_spawn_file_actions_destroy(
                       posix_spawn_file_actions_t *file_actions);
extern int posix_spawn_file_actions_init(
                       posix_spawn_file_actions_t *file_actions);
extern int posix_spawnattr_destroy(posix_spawnattr_t *attr);
extern int posix_spawnattr_getflags(const posix_spawnattr_t *restrict attr,
                                    short *restrict flags);
extern int posix_spawnattr_getpgroup(const posix_spawnattr_t *restrict attr,
                                     pid_t *restrict pgroup);
extern int posix_spawnattr_getschedparam(
                       const posix_spawnattr_t *restrict attr,
                       struct sched_param *restrict schedparam);
extern int posix_spawnattr_getschedpolicy(
                       const posix_spawnattr_t *restrict attr,
                       int *restrict schedpolicy);
extern int posix_spawnattr_getsigdefault(
                       const posix_spawnattr_t *restrict attr,
                       sigset_t *restrict sigdefault);
extern int posix_spawnattr_getsigmask(const posix_spawnattr_t *restrict attr,
                       sigset_t *restrict sigmask);
extern int posix_spawnattr_init(posix_spawnattr_t *attr);
extern int posix_spawnattr_setflags(posix_spawnattr_t *attr, short flags);
extern int posix_spawnattr_setpgroup(posix_spawnattr_t *attr, pid_t pgroup);
extern int posix_spawnattr_setschedparam(
                       posix_spawnattr_t *restrict attr,
                       const struct sched_param *restrict schedparam);
extern int posix_spawnattr_setschedpolicy(posix_spawnattr_t *attr,
                                          int schedpolicy);
extern int posix_spawnattr_setsigdefault(posix_spawnattr_t *restrict attr,
                                         const sigset_t *restrict sigdefault);
extern int posix_spawnattr_setsigmask(posix_spawnattr_t *restrict attr,
                                      const sigset_t *restrict sigmask);
extern int posix_spawnp(pid_t *pid, const char *file,
                        const posix_spawn_file_actions_t *file_actions,
                        const posix_spawnattr_t *attrp, char *const argv[],
                        char *const envp[]);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SPAWN_H */

#endif /* defined(CLIB2_SPAWN_STUB) || defined(CLIB2_MULTUM_STUB) */
