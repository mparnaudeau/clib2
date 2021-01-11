#ifdef CLIB2_STUBS

#ifndef _ARPA_NAMESER_H
#define _ARPA_NAMESER_H

/* RFC1032, RFC1033, RFC1034, RFC1035, RFC974. */

#warning "STUB: arpa/nameser.h"

#include <stddef.h>
#include <stdint.h>

typedef enum __ns_sect {
    ns_s_qd = 0,
    ns_s_zn = 0,
    ns_s_an = 1,
    ns_s_pr = 1,
    ns_s_ns = 2,
    ns_s_ud = 2,
    ns_s_ar = 3,
    ns_s_max = 4
} ns_sect;

typedef struct __ns_msg {
    const unsigned char *_msg, *_eom;
    uint16_t _id, _flags, _counts[ns_s_max];
    const unsigned char *_sections[ns_s_max];
    ns_sect _sect;
    int _rrnum;
    const unsigned char *_msg_ptr;
} ns_msg;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

unsigned int  ns_get16(const u_char *src);
unsigned long ns_get32(const unsigned char *);
void ns_put16(unsigned int src, unsigned char *dst);
void ns_put32(unsigned long src, unsigned char *dst);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ARPA_NAMESER_H */

#endif /* CLIB2_STUBS */
