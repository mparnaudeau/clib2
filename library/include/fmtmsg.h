#if defined(CLIB2_FMTMSG_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _FMTMSG_H
#define _FMTMSG_H

/* POSIX.1-2001 and POSIX.1-2008. */

#warning "STUB: fmtmsg.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int fmtmsg(long classification, const char *label, int severity,
                  const char *text, const char *action, const char *tag);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _FMTMSG_H */

#endif /* defined(CLIB2_FMTMSG_STUB) || defined(CLIB2_MULTUM_STUB) */
