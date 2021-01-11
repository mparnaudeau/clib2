#ifdef CLIB2_STUBS

#ifndef _PTHREAD_H
#define _PTHREAD_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: pthread.h"

struct pthread_t {
    int dummy;
};

struct pthread_attr_t {
    int dummy;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int pthread_attr_init(pthread_attr_t *attr);
extern int pthread_attr_destroy(pthread_attr_t *attr);
extern int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
extern int pthread_attr_getdetachstate(const pthread_attr_t *attr,
                                       int *detachstate);
extern int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize);
extern int pthread_attr_getguardsize(const pthread_attr_t *attr,
                                     size_t *guardsize);
extern int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched);
extern int pthread_attr_getinheritsched(const pthread_attr_t *attr,
                                        int *inheritsched);
extern int pthread_attr_setschedparam(pthread_attr_t *attr,
                                      const struct sched_param *param);
extern int pthread_attr_getschedparam(const pthread_attr_t *attr,
                                      struct sched_param *param);
extern int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
extern int pthread_attr_getschedpolicy(const pthread_attr_t *attr, int *policy);
extern int pthread_attr_setscope(pthread_attr_t *attr, int scope);
extern int pthread_attr_getscope(const pthread_attr_t *attr, int *scope);
extern int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr,
                                 size_t stacksize);
extern int pthread_attr_getstack(const pthread_attr_t *attr,
                                 void **stackaddr, size_t *stacksize);
extern int pthread_attr_setstackaddr(pthread_attr_t *attr, void *stackaddr);
extern int pthread_attr_getstackaddr(const pthread_attr_t *attr,
                                     void **stackaddr);
extern int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
extern int pthread_attr_getstacksize(const pthread_attr_t *attr,
                                     size_t *stacksize);
extern int pthread_cancel(pthread_t thread);
extern int pthread_detach(pthread_t thread);
extern int pthread_equal(pthread_t t1, pthread_t t2);
extern void pthread_exit(void *retval);
extern int pthread_join(pthread_t thread, void **retval);
extern pthread_t pthread_self(void);
extern int pthread_setschedparam(pthread_t thread, int policy,
                                 const struct sched_param *param);
extern int pthread_getschedparam(pthread_t thread, int *policy,
                                 struct sched_param *param);
extern int pthread_setschedprio(pthread_t thread, int prio);
extern int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PTHREAD_H */

#endif /* CLIB2_STUBS */
