#if defined(CLIB2_UCONTEXT_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _UCONTEXT_H
#define _UCONTEXT_H

/* SUSv2, POSIX.1-2001, POSIX.1-2008. */

#warning "STUB: ucontext.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int getcontext(ucontext_t *ucp);
extern void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...);
extern int setcontext(const ucontext_t *ucp);
extern int swapcontext(ucontext_t *oucp, const ucontext_t *ucp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _UCONTEXT_H */

#endif /* defined(CLIB2_UCONTEXT_STUB) || defined(CLIB2_MULTUM_STUB) */
