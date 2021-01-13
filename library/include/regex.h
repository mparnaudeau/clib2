#if defined(CLIB2_REGEX_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _REGEX_H
#define _REGEX_H

/* POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: regex.h"

typedef struct re_pattern_buffer {
    int dummy;
} regex_t;

typedef struct {
    int dummy;
} regmatch_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int regcomp(regex_t *preg, const char *regex, int cflags);
extern int regexec(const regex_t *preg, const char *string, size_t nmatch,
                   regmatch_t pmatch[], int eflags);
extern size_t regerror(int errcode, const regex_t *preg, char *errbuf,
                       size_t errbuf_size);
extern void regfree(regex_t *preg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _REGEX_H */

#endif /* defined(CLIB2_REGEX_STUB) || defined(CLIB2_MULTUM_STUB) */
