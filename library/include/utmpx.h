#ifdef CLIB2_STUBS

#ifndef _UTMPX_H
#define _UTMPX_H

/* XPG2, SVr4. */

#warning "STUB: utmpx.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void endutxent(void);
extern struct utmpx *getutxent(void);
extern struct utmpx *getutxid(const struct utmpx *);
extern struct utmpx *getutxline(const struct utmpx *);
extern struct utmpx *pututxline(const struct utmpx *);
extern void setutxent(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _UTMPX_H */

#endif /* CLIB2_STUBS */
