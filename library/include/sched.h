#if defined(CLIB2_SCHED_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _SCHED_H
#define _SCHED_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: sched.h"

struct sched_param {
	int dummy;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int sched_getcpu(void);
extern int sched_get_priority_max(int policy);
extern int sched_get_priority_min(int policy);
extern int sched_getaffinity(pid_t pid,
                             size_t cpusetsize, cpu_set_t *mask);
extern int sched_getparam(pid_t pid, struct sched_param *param);
extern int sched_getscheduler(pid_t pid);
extern int sched_rr_get_interval(pid_t pid, struct timespec *tp);
extern int sched_setaffinity(pid_t pid, size_t cpusetsize,
                             const cpu_set_t *mask);
extern int sched_setparam(pid_t pid, const struct sched_param *param);
extern int sched_setscheduler(pid_t pid, int policy,
                              const struct sched_param *param);
extern int sched_yield(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SCHED_H */

#endif /* defined(CLIB2_SCHED_STUB) || defined(CLIB2_MULTUM_STUB) */
