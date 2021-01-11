#ifdef CLIB2_STUBS

#ifndef _GLOB_H
#define _GLOB_H

/* POSIX.1-2001, POSIX.1-2008, POSIX.2. */

#warning "STUB: glob.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int glob(const char *pattern, int flags,
                int (*errfunc) (const char *epath, int eerrno), glob_t *pglob);
extern void globfree(glob_t *pglob);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _GLOB_H */

#endif /* CLIB2_STUBS */
