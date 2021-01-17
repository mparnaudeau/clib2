#if defined(CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _STATVFS_H
#define _STATVFS_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: sys/statvfs.h"

struct statvfs;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int fstatvfs(int fd, struct statvfs *buf);
extern int statvfs(const char *restrict path, struct statvfs *restrict buf);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STATVFS_H */

#endif /* defined(CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB) */
