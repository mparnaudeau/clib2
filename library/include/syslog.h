#ifdef CLIB2_STUBS

#ifndef _SYSLOG_H
#define _SYSLOG_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: syslog.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int setlogmask(int mask);
extern void openlog(const char *ident, int option, int facility);
extern void syslog(int priority, const char *format, ...);
extern void closelog(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SYSLOG_H */

#endif /* CLIB2_STUBS */
