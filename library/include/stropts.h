#ifdef CLIB2_STUBS

#ifndef _STROPTS_H
#define _STROPTS_H

/* POSIX.1 & V7 AT&T UNIX */

#warning "STUB: stropts.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int isastream(int fildes);
extern int ioctl(int fd, unsigned long request, ...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STROPTS_H */

#endif /* CLIB2_STUBS */
