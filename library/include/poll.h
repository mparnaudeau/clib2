#if defined(CLIB2_POLL_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _POLL_H
#define _POLL_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: poll.h"

typedef unsigned long nfds_t;
struct pollfd;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int poll(struct pollfd *fds, nfds_t nfds, int timeout);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _POLL_H */

#endif /* defined(CLIB2_POLL_STUB) || defined(CLIB2_MULTUM_STUB) */
