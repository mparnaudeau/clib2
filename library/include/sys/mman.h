#if defined(CLIB2_SYS_MMAN_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _MMAN_H
#define _MMAN_H

/* POSIX.1-2001, POSIX.1-2008, SVr4. */

#warning "STUB: sys/mman.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int madvise(void *addr, size_t length, int advice);
extern int mincore(void *addr, size_t length, unsigned char *vec);
extern int mlock(const void *addr, size_t len);
extern int mlockall(int flags);
extern void *mmap(void *addr, size_t length, int prot, int flags, int fd,
                  off_t offset);
extern int munmap(void *addr, size_t length);
extern int mprotect(void *addr, size_t len, int prot);
extern void *mremap(void *old_address, size_t old_size, size_t new_size,
                    int flags, ...);
extern int msync(void *addr, size_t length, int flags);
extern int munlock(const void *addr, size_t len);
extern int munlockall(void);
extern int posix_madvise(void *addr, size_t len, int advice);
extern int remap_file_pages(void *addr, size_t size, int prot, size_t pgoff,
                            int flags);
extern int shm_open(const char *name, int oflag, mode_t mode);
extern int shm_unlink(const char *name);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MMAN_H */

#endif /* defined(CLIB2_SYS_MMAN_STUB) || defined(CLIB2_MULTUM_STUB) */
