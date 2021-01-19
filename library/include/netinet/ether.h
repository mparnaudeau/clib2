#if defined(CLIB2_NETINET_ETHER_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _ETHER_H
#define _ETHER_H

/* 4.3BSD, SunOS. */

#warning "STUB: netinet/ether.h"

#include <stddef.h>

struct ether_addr;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern char *ether_ntoa(const struct ether_addr *addr);
extern struct ether_addr *ether_aton(const char *asc);
extern int ether_ntohost(char *hostname,
                         const struct ether_addr *addr);
extern int ether_hostton(const char *hostname,
                         struct ether_addr *addr);
extern int ether_line(const char *line, struct ether_addr *addr,
                      char *hostname);
extern char *ether_ntoa_r(const struct ether_addr *addr, char *buf);
extern struct ether_addr *ether_aton_r(const char *asc,
                                       struct ether_addr *addr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ETHER_H */

#endif /* defined(CLIB2_NETINET_ETHER_STUB) || defined(CLIB2_MULTUM_STUB) */
