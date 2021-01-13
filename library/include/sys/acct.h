#if defined(CLIB2_SYS_ACCT_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _ACCT_H
#define _ACCT_H

/* SVr4, 4.3BSD */

#warning "STUB: sys/acct.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int acct(const char *filename);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ACCT_H */

#endif /* defined(CLIB2_SYS_ACCT_STUB) || defined(CLIB2_MULTUM_STUB) */
