#if defined(CLIB2_PTY_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _PTY_H
#define _PTY_H

/* BSD */

#warning "STUB: pty.h"

struct termios {
    int dummy;
};

struct winsize {
    int dummy;
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int openpty(int *amaster, int *aslave, char *name,
                   const struct termios *termp, const struct winsize *winp);
extern pid_t forkpty(int *amaster, char *name, const struct termios *termp,
                     const struct winsize *winp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _PTY_H */

#endif /* defined(CLIB2_PTY_STUB) || defined(CLIB2_MULTUM_STUB) */
