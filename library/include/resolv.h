#if defined(CLIB2_RESOLV_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _RESOLV_H
#define _RESOLV_H

/* 4.3BSD */

#warning "STUB: resolv.h"

typedef int res_state;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int dn_comp(const char *exp_dn, unsigned char *comp_dn, int length,
                   unsigned char **dnptrs, unsigned char **lastdnptr);
extern int dn_expand(const unsigned char *msg, const unsigned char *eomorig,
                     const unsigned char *comp_dn, char *exp_dn, int length);
extern void res_nclose(res_state statep);
extern int res_ninit(res_state statep);
extern int res_nmkquery(res_state statep, int op, const char *dname,
                        int class, int type, const unsigned char *data,
                        int datalen, const unsigned char *newrr,
                        unsigned char *buf, int buflen);
extern int res_nquery(res_state statep, const char *dname, int class,
                      int type, unsigned char *answer, int anslen);
extern int res_nquerydomain(res_state statep, const char *name,
                            const char *domain, int class, int type,
                            unsigned char *answer, int anslen);
extern int res_nsearch(res_state statep, const char *dname, int class,
                       int type, unsigned char *answer, int anslen);
extern int res_nsend(res_state statep, const unsigned char *msg, int msglen,
                     unsigned char *answer, int anslen);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _RESOLV_H */

#endif /* defined(CLIB2_RESOLV_STUB) || defined(CLIB2_MULTUM_STUB) */
