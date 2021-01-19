#if defined(CLIB2_MQUEUE_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _MQUEUE_H
#define _MQUEUE_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: mqueue.h"

#include <signal.h>
#include <locale.h>

typedef int mqd_t;
struct mq_attr;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int mq_close(mqd_t mqdes);
extern int mq_getattr(mqd_t mqdes, struct mq_attr *attr);
extern int mq_notify(mqd_t mqdes, const struct sigevent *sevp);
extern mqd_t mq_open( const char *name, int oflag, ...);
extern ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                          unsigned int *msg_prio);
extern int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
                   unsigned int msg_prio);
extern int mq_setattr(mqd_t mqdes, const struct mq_attr *newattr,
                      struct mq_attr *oldattr);
extern ssize_t mq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                               unsigned int *msg_prio,
                               const struct timespec *abs_timeout);
extern int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
                        unsigned int msg_prio,
                        const struct timespec *abs_timeout);
extern int mq_unlink(const char *name);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MQUEUE_H */

#endif /* defined(CLIB2_MQUEUE_STUB) || defined(CLIB2_MULTUM_STUB) */
