#if defined(CLIB2_UCHAR_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _UCHAR_H
#define _UCHAR_H

/* ISO/IEC 9899:2011 */

#warning "STUB: uchar.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern size_t c16rtomb(char *s, char16_t c16, mbstate_t *ps);
extern size_t c32rtomb(char *s, char32_t c32, mbstate_t *ps);
extern size_t mbrtoc32(char32_t *pc32, const char *s, size_t n, mbstate_t *ps);
extern size_t mbrtoc16(char16_t *pc16, const char *s, size_t n, mbstate_t *ps);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _UCHAR_H */

#endif /* defined(CLIB2_UCHAR_STUB) || defined(CLIB2_MULTUM_STUB) */
