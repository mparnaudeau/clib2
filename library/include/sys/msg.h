#ifdef CLIB2_STUBS

#ifndef _MSG_H
#define _MSG_H

/* POSIX.1-2001, POSIX.1-2008, SVr4. */

#warning "STUB: sys/msg.h"

#include <stddef.h>
#include <sys/ipc.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int msgctl(int msqid, int cmd, struct msqid_ds *buf);
extern int msgget(key_t key, int msgflg);
extern ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
                      int msgflg);
extern int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MSG_H */

#endif /* CLIB2_STUBS */
