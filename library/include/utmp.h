#if defined(CLIB2_UTMP_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _UTMP_H
#define _UTMP_H

/* XPG2, SVr4. */

#warning "STUB: utmp.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void endutent(void);
extern struct utmp *getutent(void);
extern struct utmp *getutid(struct utmp *ut);
extern struct utmp *getutline(struct utmp *ut);
extern struct utmp *pututline(struct utmp *ut);
extern void setutent(void);
extern int utmpname(const char *file);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _UTMP_H */

#endif /* defined(CLIB2_UTMP_STUB) || defined(CLIB2_MULTUM_STUB) */
