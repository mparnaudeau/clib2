#if defined(CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _STATVFS_H
#define _STATVFS_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: sys/statvfs.h"

struct statvfs {
    unsigned long f_bsize, f_frsize;
    fsblkcnt_t f_blocks, f_bfree, f_bavail;
    fsfilcnt_t f_files, f_ffree, f_favail;
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned long f_fsid;
    unsigned :8*(2*sizeof(int)-sizeof(long));
#else
    unsigned :8*(2*sizeof(int)-sizeof(long));
    unsigned long f_fsid;
#endif
    unsigned long f_flag, f_namemax;
    int __reserved[6];
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int fstatvfs(int fd, struct statvfs *buf);
extern int statvfs(const char *restrict path, struct statvfs *restric buf);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STATVFS_H */

#endif /* defined(CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB) */
