#if defined(CLIB2_SYS_SEM_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _SEM_H
#define _SEM_H

/* POSIX.1-2001, POSIX.1-2008, SVr4. */

#warning "STUB: sys/sem.h"

#include <time.h>

struct sembuf;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int semctl(int semid, int semnum, int cmd, ...);
extern int semget(key_t key, int nsems, int semflg);
extern int semop(int semid, struct sembuf *sops, size_t nsops);
extern int semtimedop(int semid, struct sembuf *sops, size_t nsops,
                      const struct timespec *timeout);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SEM_H */

#endif /* defined(CLIB2_SYS_SEM_STUB) || defined(CLIB2_MULTUM_STUB) */
