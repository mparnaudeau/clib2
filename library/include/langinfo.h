#if defined(CLIB2_LANGINFO_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _LANGINFO_H
#define _LANGINFO_H

/* POSIX.1-2001, POSIX.1-2008, SUSv2. */

#warning "STUB: langinfo.h"

#include <stddef.h>

typedef int nl_item;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern char *nl_langinfo(nl_item item);
extern char *nl_langinfo_l(nl_item item, locale_t locale);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LANGINFO_H */

#endif /* defined(CLIB2_LANGINFO_STUB) || defined(CLIB2_MULTUM_STUB) */
