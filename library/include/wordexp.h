#if defined(CLIB2_WORDEXP_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _WORDEXP_H
#define _WORDEXP_H

/* POSIX.1-2001. */

#warning "STUB: wordexp.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int wordexp(const char *s, wordexp_t *p, int flags);
extern void wordfree(wordexp_t *p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WORDEXP_H */

#endif /* defined(CLIB2_WORDEXP_STUB) || defined(CLIB2_MULTUM_STUB) */
