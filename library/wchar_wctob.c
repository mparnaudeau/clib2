/*
 * FIXME: From MUSL.
 */

#ifndef _WCHAR_HEADERS_H
#include "wchar_headers.h"
#endif /* _WCHAR_HEADERS_H */

/****************************************************************************/

int
wctob(wint_t c)
{
    return (c < 128U) ? c : (MB_CUR_MAX == 1 && IS_CODEUNIT(c)) ?
                            (unsigned char) c : EOF;
}
