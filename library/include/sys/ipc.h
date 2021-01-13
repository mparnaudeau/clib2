#if defined(CLIB2_SYS_IPC_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _IPC_H
#define _IPC_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: sys/ipc.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern key_t ftok(char *pathname, char proj_id);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _IPC_H */

#endif /* defined(CLIB2_SYS_IPC_STUB) || defined(CLIB2_MULTUM_STUB) */
