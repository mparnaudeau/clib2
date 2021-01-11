#ifdef CLIB2_STUBS

#ifndef _IFADDRS_H
#define _IFADDRS_H

/* BSDi */

#warning "STUB: ifaddrs.h"

struct ifaddrs {
    int dummy;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int getifaddrs(struct ifaddrs **ifap);
extern void freeifaddrs(struct ifaddrs *ifa);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _IFADDRS_H */

#endif /* CLIB2_STUBS */
