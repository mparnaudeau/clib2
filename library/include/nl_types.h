#ifdef CLIB2_STUBS

#ifndef _NL_TYPES_H
#define _NL_TYPES_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: nl_types.h"

typedef int nl_item;
typedef void *nl_catd;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int catclose(nl_catd catalog);
extern char *catgets(nl_catd catalog, int set_number, int message_number,
                     const char *message);
extern nl_catd catopen(const char *name, int flag);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _NL_TYPES_H */

#endif /* CLIB2_STUBS */
