#ifdef CLIB2_STUBS

#ifndef _ICONV_H
#define _ICONV_H

/* POSIX.1-2001, POSIX.1-2008, SUSv2. */

#warning "STUB: iconv.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern size_t iconv(iconv_t cd, char **inbuf, size_t *inbytesleft,
                    char **outbuf, size_t *outbytesleft);
extern iconv_t iconv_open(const char *tocode, const char *fromcode);
extern int iconv_close(iconv_t cd);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ICONV_H */

#endif /* CLIB2_STUBS */
