#ifdef CLIB2_STUBS

#ifndef _LANGINFO_H
#define _LANGINFO_H

/* POSIX.1-2001, POSIX.1-2008, SUSv2. */

#warning "STUB: langinfo.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern char *nl_langinfo(nl_item item);
extern char *nl_langinfo_l(nl_item item, locale_t locale);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LANGINFO_H */

#endif /* CLIB2_STUBS */
