#if defined(CLIB2_SYS_SHM_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _SHM_H
#define _SHM_H

/* POSIX.1-2001, POSIX.1-2008, SVr4. */

#warning "STUB: sys/shm.h"

#include <sys/types.h>

struct shmid_ds;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void *shmat(int shmid, const void *shmaddr, int shmflg);
extern int shmctl(int shmid, int cmd, struct shmid_ds *buf);
extern int shmdt(const void *shmaddr);
extern int shmget(key_t key, size_t size, int shmflg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SHM_H */

#endif /* defined(CLIB2_SYS_SHM_STUB) || defined(CLIB2_MULTUM_STUB) */
