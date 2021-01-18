#if defined(CLIB2_AIO_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _AIO_H
#define _AIO_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: aio.h"

#include <signal.h>

struct aiocb;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int aio_cancel(int fd, struct aiocb *aiocbp);
extern int aio_error(const struct aiocb *aiocbp);
extern int aio_fsync(int op, struct aiocb *aiocbp);
extern int aio_read(struct aiocb *aiocbp);
extern size_t aio_return(struct aiocb *aiocbp);
extern int aio_suspend(const struct aiocb * const aiocb_list[], int nitems,
                       const struct timespec *timeout);
extern int aio_write(struct aiocb *aiocbp);
extern int lio_listio(int mode, struct aiocb *const aiocb_list[], int nitems,
                      struct sigevent *sevp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _AIO_H */

#endif /* defined(CLIB2_AIO_STUB) || defined(CLIB2_MULTUM_STUB) */
