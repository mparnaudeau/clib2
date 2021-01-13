#if defined(CLIB2_SEMAPHORE_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: semaphore.h"

typedef struct {
    int dummy;
} sem_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int sem_close(sem_t *sem);
extern int sem_destroy(sem_t *sem);
extern int sem_getvalue(sem_t *sem, int *sval);
extern int sem_init(sem_t *sem, int pshared, unsigned int value);
extern sem_t * sem_open(const char *name, int oflag, ...);
extern int sem_post(sem_t *sem);
extern int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
extern int sem_trywait(sem_t *sem);
extern int sem_unlink(const char *name);
extern int sem_wait(sem_t *sem);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SEMAPHORE_H */

#endif /* defined(CLIB2_SEMAPHORE_STUB) || defined(CLIB2_MULTUM_STUB) */
