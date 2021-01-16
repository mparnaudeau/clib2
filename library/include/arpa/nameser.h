#if defined(CLIB2_ARPA_NAMESER_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _ARPA_NAMESER_H
#define _ARPA_NAMESER_H

/* RFC1032, RFC1033, RFC1034, RFC1035, RFC974. */

#warning "STUB: arpa/nameser.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

unsigned int ns_get16(const unsigned char *src);
unsigned long int ns_get32(const unsigned char *src);
void ns_put16(unsigned int src, unsigned char *dst);
void ns_put32(unsigned long int src, unsigned char *dst);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ARPA_NAMESER_H */

#endif /* defined(CLIB2_ARPA_NAMESER_STUB) || defined(CLIB2_MULTUM_STUB) */
