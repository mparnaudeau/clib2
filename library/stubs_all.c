/*
 *  Stub functions.
 */

#include "debug.h"

/****************************************************************************/
#if defined(CLIB2_AIO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <aio.h>
/****************************************************************************/
int aio_cancel(int fd, struct aiocb *aiocbp)
{
    (void) fd;
    (void) aiocbp;

    ENTER();
    return 0;
}

/****************************************************************************/
int aio_error(const struct aiocb *aiocbp)
{
    (void) aiocbp;

    ENTER();
    return 0;
}

/****************************************************************************/
int aio_fsync(int op, struct aiocb *aiocbp)
{
    (void) op;
    (void) aiocbp;

    ENTER();
    return 0;
}

/****************************************************************************/
int aio_read(struct aiocb *aiocbp)
{
    (void) aiocbp;

    ENTER();
    return 0;
}

/****************************************************************************/
size_t aio_return(struct aiocb *aiocbp)
{
    (void) aiocbp;

    ENTER();
    return 0;
}

/****************************************************************************/
int aio_suspend(const struct aiocb * const aiocb_list[], int nitems,
                const struct timespec *timeout)
{
    (void) aiocb_list;
    (void) nitems;
    (void) timeout;

    ENTER();
    return 0;
}

/****************************************************************************/
int aio_write(struct aiocb *aiocbp)
{
    (void) aiocbp;

    ENTER();
    return 0;
}

/****************************************************************************/
int lio_listio(int mode, struct aiocb *const aiocb_list[], int nitems,
               struct sigevent *sevp)
{
    (void) mode;
    (void) aiocb_list;
    (void) nitems;
    (void) sevp;

    ENTER();
    return 0;
}
#endif /* CLIB2_AIO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_ARPA_NAMESER_STUB) || defined(CLIB2_MULTUM_STUB)
#include <arpa/nameser.h>
/****************************************************************************/
unsigned int ns_get16(const unsigned char *src)
{
    (void) src;

    ENTER();
    return 0;
}

/****************************************************************************/
unsigned long int ns_get32(const unsigned char *src)
{
    (void) src;

    ENTER();
    return 0;
}

/****************************************************************************/
void ns_put16(unsigned int src, unsigned char *dst)
{
    (void) src;
    (void) dst;

    ENTER();
}

/****************************************************************************/
void ns_put32(unsigned long int src, unsigned char *dst)
{
    (void) src;
    (void) dst;

    ENTER();
}
#endif /* (CLIB2_ARPA_NAMESER_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_COMPLEX_STUB) || defined(CLIB2_MULTUM_STUB)
#include <complex.h>
/****************************************************************************/
double complex cacos(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex cacosf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex cacosl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex casin(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex casinf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex casinl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex catan(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex catanf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex catanl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex ccos(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex ccosf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex ccosl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex csin(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex csinf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex csinl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex ctan(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex ctanf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex ctanl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex cacosh(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex cacoshf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex cacoshl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex casinh(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex casinhf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex casinhl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex catanh(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex catanhf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex catanhl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex ccosh(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex ccoshf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex ccoshl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex csinh(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex csinhf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex csinhl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex ctanh(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex ctanhf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex ctanhl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex cexp(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex cexpf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex cexpl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex clog(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex clogf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex clogl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double cabs(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float cabsf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double cabsl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex cpow(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex cpowf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex cpowl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex csqrt(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex csqrtf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex csqrtl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
double complex cproj(double complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
float complex cprojf(float complex z)
{
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double complex cprojl(long double complex z)
{
    (void) z;

    ENTER();
    return 0;
}
#endif /* CLIB2_COMPLEX_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_CTYPE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <ctype.h>
/****************************************************************************/
int isalnum_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isalpha_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isblank_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int iscntrl_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isdigit_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isgraph_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int islower_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isprint_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int ispunct_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isspace_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isupper_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int isxdigit_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int tolower_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
int toupper_l(int c, locale_t locale)
{
    (void) c;
    (void) locale;

    ENTER();
    return 0;
}
#endif /* CLIB2_CTYPE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_DIRENT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <dirent.h>
/****************************************************************************/
DIR *fdopendir(int fd)
{
    (void) fd;

    ENTER();
    return NULL;
}

/****************************************************************************/
int dirfd(DIR *dirp)
{
    (void) dirp;

    ENTER();
    return 0;
}
#endif /* CLIB2_DIRENT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FCNTL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <fcntl.h>
/****************************************************************************/
int posix_fadvise(int fd, off_t offset, off_t len, int advice)
{
    (void) fd;
    (void) offset;
    (void) len;
    (void) advice;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_fallocate(int fd, off_t offset, off_t len)
{
    (void) fd;
    (void) offset;
    (void) len;

    ENTER();
    return 0;
}

/****************************************************************************/
int openat(int fd, const char *path, int oflag, ...)
{
    (void) fd;
    (void) path;
    (void) oflag;

    ENTER();
    return 0;
}
#endif /* CLIB2_FCNTL_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FENV_STUB) || defined(CLIB2_MULTUM_STUB)
#include <fenv.h>
/****************************************************************************/
int fesetround(int rounding_mode)
{
    (void) rounding_mode;

    ENTER();
    return 0;
}
#endif /* CLIB2_FENV_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FMTMSG_STUB) || defined(CLIB2_MULTUM_STUB)
#include <fmtmsg.h>
/****************************************************************************/
int fmtmsg(long classification, const char *label, int severity,
           const char *text, const char *action, const char *tag)
{
    (void) classification;
    (void) label;
    (void) severity;
    (void) text;
    (void) action;
    (void) tag;

    ENTER();
    return 0;
}
#endif /* CLIB2_FMTMSG_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FNMATCH_STUB) || defined(CLIB2_MULTUM_STUB)
#include <fnmatch.h>
/****************************************************************************/
int fnmatch(const char *pattern, const char *string, int flags)
{
    (void) pattern;
    (void) string;
    (void) flags;

    ENTER();
    return 0;
}
#endif /* CLIB2_FNMATCH_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FTW_STUB) || defined(CLIB2_MULTUM_STUB)
#include <ftw.h>
/****************************************************************************/
int ftw64(const char *dirpath, int (*fn) (const char *fpath,
          const struct stat *sb, int typeflag), int nopenfd)
{
    (void) dirpath;
    (void) fn;
    (void) nopenfd;

    ENTER();
    return 0;
}

/****************************************************************************/
int nftw64(const char *dirpath, int (*fn) (const char *fpath,
           const struct stat *sb, int typeflag, struct FTW *ftwbuf),
           int nopenfd, int flags)
{
    (void) dirpath;
    (void) fn;
    (void) nopenfd;
    (void) flags;

    ENTER();
    return 0;
}
#endif /* CLIB2_FTW_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_GETOPT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <getopt.h>
/****************************************************************************/
int getopt(int argc, char * const argv[], const char *optstring)
{
    (void) argc;
    (void) argv;
    (void) optstring;

    ENTER();
    return 0;
}

/****************************************************************************/
int getopt_long_only(int argc, const char **argv, const char *optstring,
		             const struct option *longopts, int *longindex)
{
    (void) argc;
    (void) argv;
    (void) optstring;
    (void) longopts;
    (void) longindex;

    ENTER();
    return 0;
}
#endif /* CLIB2_GETOPT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_GLOB_STUB) || defined(CLIB2_MULTUM_STUB)
#include <glob.h>
/****************************************************************************/
int glob(const char *pattern, int flags,
         int (*errfunc) (const char *epath, int eerrno), glob_t *pglob)
{
    (void) pattern;
    (void) flags;
    (void) errfunc;
    (void) pglob;

    ENTER();
    return 0;
}

/****************************************************************************/
void globfree(glob_t *pglob)
{
    (void) pglob;

    ENTER();
}
#endif /* CLIB2_GLOB_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_GRP_STUB) || defined(CLIB2_MULTUM_STUB)
#include <grp.h>
/****************************************************************************/
int getgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen,
               struct group **result)
{
    (void) name;
    (void) grp;
    (void) buf;
    (void) buflen;
    (void) result;

    ENTER();
    return 0;
}

/****************************************************************************/
int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen,
               struct group **result)
{
    (void) gid;
    (void) grp;
    (void) buf;
    (void) buflen;
    (void) result;

    ENTER();
    return 0;
}
#endif /* CLIB2_GRP_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_ICONV_STUB) || defined(CLIB2_MULTUM_STUB)
#include <iconv.h>
/****************************************************************************/
size_t iconv(iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf,
             size_t *outbytesleft)
{
    (void) cd;
    (void) inbuf;
    (void) inbytesleft;
    (void) outbuf;
    (void) outbytesleft;

    ENTER();
    return 0;
}

/****************************************************************************/
iconv_t iconv_open(const char *tocode, const char *fromcode)
{
    (void) tocode;
    (void) fromcode;

    ENTER();
    return NULL;
}

/****************************************************************************/
int iconv_close(iconv_t cd)
{
    (void) cd;

    ENTER();
    return 0;
}
#endif /* CLIB2_ICONV_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_IFADDRS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <ifaddrs.h>
/****************************************************************************/
int getifaddrs(struct ifaddrs **ifap)
{
    (void) ifap;

    ENTER();
    return 0;
}

/****************************************************************************/
void freeifaddrs(struct ifaddrs *ifa)
{
    (void) ifa;

    ENTER();
}
#endif /* CLIB2_IFADDRS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_LANGINFO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <langinfo.h>
/****************************************************************************/
char *nl_langinfo(nl_item item)
{
    (void) item;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *nl_langinfo_l(nl_item item, locale_t locale)
{
    (void) item;
    (void) locale;

    ENTER();
    return NULL;
}
#endif /* CLIB2_LANGINFO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_LIBINTL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <libintl.h>
/****************************************************************************/
char *bindtextdomain(const char * domainname, const char * dirname)
{
    (void) domainname;
    (void) dirname;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *bind_textdomain_codeset(const char * domainname, const char * codeset)
{
    (void) domainname;
    (void) codeset;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *dgettext(const char * domainname, const char * msgid)
{
    (void) domainname;
    (void) msgid;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *dcgettext(const char * domainname, const char * msgid, int category)
{
    (void) domainname;
    (void) msgid;
    (void) category;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *ngettext(const char * msgid, const char * msgid_plural,
               unsigned long int n)
{
    (void) msgid;
    (void) msgid_plural;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *dngettext(const char * domainname, const char * msgid,
                const char * msgid_plural, unsigned long int n)
{
    (void) domainname;
    (void) msgid;
    (void) msgid_plural;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *dcngettext(const char * domainname, const char * msgid,
                 const char * msgid_plural, unsigned long int n, int category)
{
    (void) domainname;
    (void) msgid;
    (void) msgid_plural;
    (void) n;
    (void) category;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *gettext(const char * msgid)
{
    (void) msgid;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *textdomain(const char * domainname)
{
    (void) domainname;

    ENTER();
    return NULL;
}
#endif /* CLIB2_LIBINTL_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_LOCALE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <locale.h>
/****************************************************************************/
locale_t duplocale(locale_t locobj)
{
    (void) locobj;

    ENTER();
    return NULL;
}

/****************************************************************************/
locale_t newlocale(int category_mask, const char *locale, locale_t base)
{
    (void) category_mask;
    (void) locale;
    (void) base;

    ENTER();
    return NULL;
}

/****************************************************************************/
void freelocale(locale_t locobj)
{
    (void) locobj;

    ENTER();
}

/****************************************************************************/
locale_t uselocale(locale_t newloc)
{
    (void) newloc;

    ENTER();
    return NULL;
}
#endif /* CLIB2_LOCALE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_MATH_STUB) || defined(CLIB2_MULTUM_STUB)
#include <math.h>
/****************************************************************************/
long double acosl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double acoshl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double asinl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double asinhl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double atanl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double atan2l(long double y, long double x)
{
    (void) y;
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double atanhl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double cbrtl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double ceill(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double copysignl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double cosl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double coshl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double erfl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double erfcl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double expl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double exp2l(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double expm1l(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double fabsl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double fdiml(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double floorl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double fmal(long double x, long double y, long double z)
{
    (void) x;
    (void) y;
    (void) z;

    ENTER();
    return 0;
}

/****************************************************************************/
long double fmaxl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double fminl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double fmodl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double frexpl(long double x, int *nptr)
{
    (void) x;
    (void) nptr;

    ENTER();
    return 0;
}

/****************************************************************************/
long double hypotl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
int ilogbl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double ldexpl(long double x, int n)
{
    (void) x;
    (void) n;

    ENTER();
    return 0;
}

/****************************************************************************/
long double lgammal(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long long int llrintl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long long int llroundl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double logl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double log10l(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double log1pl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double log2l(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double logbl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long int lrintl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long int lroundl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double modfl(long double x, long double *iptr)
{
    (void) x;
    (void) iptr;

    ENTER();
    return 0;
}

/****************************************************************************/
long double nanl(const char *tagp)
{
    (void) tagp;

    ENTER();
    return 0;
}

/****************************************************************************/
long double nearbyintl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double nextafterl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double nexttowardl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double powl(long double x, long double y)
{
    (void) x;
    (void) y;

    ENTER();
    return 0;
}

/****************************************************************************/
long double remainderl(long double x, long double p)
{
    (void) x;
    (void) p;

    ENTER();
    return 0;
}

/****************************************************************************/
long double remquol(long double x, long double y, int *quo)
{
    (void) x;
    (void) y;
    (void) quo;

    ENTER();
    return 0;
}

/****************************************************************************/
long double rintl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double roundl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double scalblnl(long double x, long int n)
{
    (void) x;
    (void) n;

    ENTER();
    return 0;
}

/****************************************************************************/
long double scalbnl(long double x, int n)
{
    (void) x;
    (void) n;

    ENTER();
    return 0;
}

/****************************************************************************/
long double sinl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double sinhl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double sqrtl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double tanl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double tanhl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double tgammal(long double x)
{
    (void) x;

    ENTER();
    return 0;
}

/****************************************************************************/
long double truncl(long double x)
{
    (void) x;

    ENTER();
    return 0;
}
#endif /* CLIB2_MATH_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_MONETARY_STUB) || defined(CLIB2_MULTUM_STUB)
#include <monetary.h>
/****************************************************************************/
ssize_t strfmon(char *s, size_t max, const char *format, ...)
{
    (void) s;
    (void) max;
    (void) format;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t strfmon_l(char *s, size_t max, locale_t locale,
                  const char *format, ...)
{
    (void) s;
    (void) max;
    (void) locale;
    (void) format;

    ENTER();
    return 0;
}
#endif /* CLIB2_MONETARY_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_MQUEUE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <mqueue.h>
/****************************************************************************/
int mq_close(mqd_t mqdes)
{
    (void) mqdes;

    ENTER();
    return 0;
}

/****************************************************************************/
int mq_getattr(mqd_t mqdes, struct mq_attr *attr)
{
    (void) mqdes;
    (void) attr;

    ENTER();
    return 0;
}

/****************************************************************************/
int mq_notify(mqd_t mqdes, const struct sigevent *sevp)
{
    (void) mqdes;
    (void) sevp;

    ENTER();
    return 0;
}

/****************************************************************************/
mqd_t mq_open(const char *name, int oflag, ...)
{
    (void) name;
    (void) oflag;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                   unsigned int *msg_prio)
{
    (void) mqdes;
    (void) msg_ptr;
    (void) msg_len;
    (void) msg_prio;

    ENTER();
    return 0;
}

/****************************************************************************/
int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
            unsigned int msg_prio)
{
    (void) mqdes;
    (void) msg_ptr;
    (void) msg_len;
    (void) msg_prio;

    ENTER();
    return 0;
}

/****************************************************************************/
int mq_setattr(mqd_t mqdes, const struct mq_attr *newattr,
               struct mq_attr *oldattr)
{
    (void) mqdes;
    (void) newattr;
    (void) oldattr;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t mq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                        unsigned int *msg_prio,
                        const struct timespec *abs_timeout)
{
    (void) mqdes;
    (void) msg_ptr;
    (void) msg_len;
    (void) msg_prio;
    (void) abs_timeout;

    ENTER();
    return 0;
}

/****************************************************************************/
int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
                 unsigned int msg_prio,
                 const struct timespec *abs_timeout)
{
    (void) mqdes;
    (void) msg_ptr;
    (void) msg_len;
    (void) msg_prio;
    (void) abs_timeout;

    ENTER();
    return 0;
}

/****************************************************************************/
int mq_unlink(const char *name)
{
    (void) name;

    ENTER();
    return 0;
}
#endif /* CLIB2_MQUEUE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NETDB_STUB) || defined(CLIB2_MULTUM_STUB)
#include <netdb.h>
/****************************************************************************/
struct netent *getnetent(void)
{
    ENTER();
    return NULL;
}

/****************************************************************************/
void setnetent(int stayopen)
{
    (void) stayopen;

    ENTER();
}

/****************************************************************************/
void endnetent(void)
{
    ENTER();
}

/****************************************************************************/
void setservent(int stayopen)
{
    (void) stayopen;

    ENTER();
}

/****************************************************************************/
void endservent(void)
{
    ENTER();
}

/****************************************************************************/
struct servent *getservent(void)
{
    ENTER();
    return NULL;
}

/****************************************************************************/
struct servent *getservbyname(const char *name, const char *proto)
{
    (void) name;
    (void) proto;

    ENTER();
    return NULL;
}

/****************************************************************************/
struct servent *getservbyport(int port, const char *proto)
{
    (void) port;
    (void) proto;

    ENTER();
    return NULL;
}

/****************************************************************************/
struct hostent *gethostent(void)
{
    ENTER();
    return NULL;
}
#endif /* CLIB2_NETDB_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NET_IF_STUB) || defined(CLIB2_MULTUM_STUB)
#include <net/if.h>
/****************************************************************************/
unsigned int if_nametoindex(const char *ifname)
{
    (void) ifname;

    ENTER();
    return 0;
}

/****************************************************************************/
char *if_indextoname(unsigned int ifindex, char *ifname)
{
    (void) ifindex;
    (void) ifname;

    ENTER();
    return NULL;
}

/****************************************************************************/
struct if_nameindex *if_nameindex(void)
{
    ENTER();
    return NULL;
}

/****************************************************************************/
void if_freenameindex(struct if_nameindex *ptr)
{
    (void) ptr;

    ENTER();
}
#endif /* CLIB2_NET_IF_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NETINET_ETHER_STUB) || defined(CLIB2_MULTUM_STUB)
#include <netinet/ether.h>
/****************************************************************************/
char *ether_ntoa(const struct ether_addr *addr)
{
    (void) addr;

    ENTER();
    return NULL;
}

/****************************************************************************/
struct ether_addr *ether_aton(const char *asc)
{
    (void) asc;

    ENTER();
    return NULL;
}

/****************************************************************************/
int ether_ntohost(char *hostname, const struct ether_addr *addr)
{
    (void) hostname;
    (void) addr;

    ENTER();
    return 0;
}

/****************************************************************************/
int ether_hostton(const char *hostname, struct ether_addr *addr)
{
    (void) hostname;
    (void) addr;

    ENTER();
    return 0;
}

/****************************************************************************/
int ether_line(const char *line, struct ether_addr *addr, char *hostname)
{
    (void) line;
    (void) addr;
    (void) hostname;

    ENTER();
    return 0;
}

/****************************************************************************/
char *ether_ntoa_r(const struct ether_addr *addr, char *buf)
{
    (void) addr;
    (void) buf;

    ENTER();
    return NULL;
}

/****************************************************************************/
struct ether_addr *ether_aton_r(const char *asc, struct ether_addr *addr)
{
    (void) asc;
    (void) addr;

    ENTER();
    return NULL;
}
#endif /* CLIB2_NETINET_ETHER_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NL_TYPES_STUB) || defined(CLIB2_MULTUM_STUB)
#include <nl_types.h>
/****************************************************************************/
int catclose(nl_catd catalog)
{
    (void) catalog;

    ENTER();
    return 0;
}

/****************************************************************************/
char *catgets(nl_catd catalog, int set_number, int message_number,
              const char *message)
{
    (void) catalog;
    (void) set_number;
    (void) message_number;
    (void) message;

    ENTER();
    return 0;
}

/****************************************************************************/
nl_catd catopen(const char *name, int flag)
{
    (void) name;
    (void) flag;

    ENTER();
    return 0;
}
#endif /* CLIB2_NL_TYPES_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_POLL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <poll.h>
/****************************************************************************/
int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    (void) fds;
    (void) nfds;
    (void) timeout;

    ENTER();
    return 0;
}
#endif /* CLIB2_POLL_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_PTHREAD_STUB) || defined(CLIB2_MULTUM_STUB)
#include <pthread.h>
/****************************************************************************/
int pthread_attr_init(pthread_attr_t *attr)
{
    (void) attr;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_destroy(pthread_attr_t *attr)
{
    (void) attr;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate)
{
    (void) attr;
    (void) detachstate;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getdetachstate(const pthread_attr_t *attr,
                                int *detachstate)
{
    (void) attr;
    (void) detachstate;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize)
{
    (void) attr;
    (void) guardsize;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getguardsize(const pthread_attr_t *attr, size_t *guardsize)
{
    (void) attr;
    (void) guardsize;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched)
{
    (void) attr;
    (void) inheritsched;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getinheritsched(const pthread_attr_t *attr,
                                 int *inheritsched)
{
    (void) attr;
    (void) inheritsched;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setschedparam(pthread_attr_t *attr,
                               const struct sched_param *param)
{
    (void) attr;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getschedparam(const pthread_attr_t *attr,
                               struct sched_param *param)
{
    (void) attr;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy)
{
    (void) attr;
    (void) policy;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getschedpolicy(const pthread_attr_t *attr, int *policy)
{
    (void) attr;
    (void) policy;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setscope(pthread_attr_t *attr, int scope)
{
    (void) attr;
    (void) scope;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getscope(const pthread_attr_t *attr, int *scope)
{
    (void) attr;
    (void) scope;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr,
                          size_t stacksize)
{
    (void) attr;
    (void) stackaddr;
    (void) stacksize;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getstack(const pthread_attr_t *attr,
                          void **stackaddr, size_t *stacksize)
{
    (void) attr;
    (void) stackaddr;
    (void) stacksize;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setstackaddr(pthread_attr_t *attr, void *stackaddr)
{
    (void) attr;
    (void) stackaddr;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getstackaddr(const pthread_attr_t *attr, void **stackaddr)
{
    (void) attr;
    (void) stackaddr;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize)
{
    (void) attr;
    (void) stacksize;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize)
{
    (void) attr;
    (void) stacksize;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_cancel(pthread_t thread)
{
    (void) thread;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_detach(pthread_t thread)
{
    (void) thread;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_equal(pthread_t t1, pthread_t t2)
{
    (void) t1;
    (void) t2;

    ENTER();
    return 0;
}

/****************************************************************************/
void pthread_exit(void *retval)
{
    (void) retval;

    ENTER();
}

/****************************************************************************/
int pthread_join(pthread_t thread, void **retval)
{
    (void) thread;
    (void) retval;

    ENTER();
    return 0;
}

/****************************************************************************/
pthread_t pthread_self(void)
{
    ENTER();
    return NULL;
}

/****************************************************************************/
int pthread_setschedparam(pthread_t thread, int policy,
                          const struct sched_param *param)
{
    (void) thread;
    (void) policy;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_getschedparam(pthread_t thread, int *policy,
                          struct sched_param *param)
{
    (void) thread;
    (void) policy;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_setschedprio(pthread_t thread, int prio)
{
    (void) thread;
    (void) prio;

    ENTER();
    return 0;
}

/****************************************************************************/
int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset)
{
    (void) how;
    (void) set;
    (void) oldset;

    ENTER();
    return 0;
}
#endif /* CLIB2_PTHREAD_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_PTY_STUB) || defined(CLIB2_MULTUM_STUB)
#include <pty.h>
/****************************************************************************/
int openpty(int *amaster, int *aslave, char *name,
            const struct termios *termp, const struct winsize *winp)
{
    (void) amaster;
    (void) aslave;
    (void) name;
    (void) termp;
    (void) winp;

    ENTER();
    return 0;
}

/****************************************************************************/
pid_t forkpty(int *amaster, char *name, const struct termios *termp,
              const struct winsize *winp)
{
    (void) amaster;
    (void) name;
    (void) termp;
    (void) winp;

    ENTER();
    return 0;
}
#endif /* CLIB2_PTY_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_PWD_STUB) || defined(CLIB2_MULTUM_STUB)
#include <pwd.h>
/****************************************************************************/
int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen,
               struct passwd **result)
{
    (void) name;
    (void) pwd;
    (void) buf;
    (void) buflen;
    (void) result;

    ENTER();
    return 0;
}

/****************************************************************************/
int getpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen,
               struct passwd **result)
{
    (void) uid;
    (void) pwd;
    (void) buf;
    (void) buflen;
    (void) result;

    ENTER();
    return 0;
}
#endif /* CLIB2_PWD_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_REGEX_STUB) || defined(CLIB2_MULTUM_STUB)
#include <regex.h>
/****************************************************************************/
int regcomp(regex_t *preg, const char *regex, int cflags)
{
    (void) preg;
    (void) regex;
    (void) cflags;

    ENTER();
    return 0;
}

/****************************************************************************/
int regexec(const regex_t *preg, const char *string, size_t nmatch,
            regmatch_t pmatch[], int eflags)
{
    (void) preg;
    (void) string;
    (void) nmatch;
    (void) pmatch;
    (void) eflags;

    ENTER();
    return 0;
}

/****************************************************************************/
size_t regerror(int errcode, const regex_t *preg, char *errbuf,
                size_t errbuf_size)
{
    (void) errcode;
    (void) preg;
    (void) errbuf;
    (void) errbuf_size;

    ENTER();
    return 0;
}

/****************************************************************************/
void regfree(regex_t *preg)
{
    (void) preg;

    ENTER();
}
#endif /* CLIB2_REGEX_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_RESOLV_STUB) || defined(CLIB2_MULTUM_STUB)
#include <resolv.h>
/****************************************************************************/
int dn_comp(const char *exp_dn, unsigned char *comp_dn, int length,
            unsigned char **dnptrs, unsigned char **lastdnptr)
{
    (void) exp_dn;
    (void) comp_dn;
    (void) length;
    (void) dnptrs;
    (void) lastdnptr;

    ENTER();
    return 0;
}

/****************************************************************************/
int dn_expand(const unsigned char *msg, const unsigned char *eomorig,
              const unsigned char *comp_dn, char *exp_dn, int length)
{
    (void) msg;
    (void) eomorig;
    (void) comp_dn;
    (void) exp_dn;
    (void) length;

    ENTER();
    return 0;
}

/****************************************************************************/
void res_nclose(res_state statep)
{
    (void) statep;

    ENTER();
}

/****************************************************************************/
int res_ninit(res_state statep)
{
    (void) statep;

    ENTER();
    return 0;
}

/****************************************************************************/
int res_nmkquery(res_state statep, int op, const char *dname, int class,
                 int type, const unsigned char *data, int datalen,
                 const unsigned char *newrr, unsigned char *buf, int buflen)
{
    (void) statep;
    (void) op;
    (void) dname;
    (void) class;
    (void) type;
    (void) data;
    (void) datalen;
    (void) newrr;
    (void) buf;
    (void) buflen;

    ENTER();
    return 0;
}

/****************************************************************************/
int res_nquery(res_state statep, const char *dname, int class, int type,
               unsigned char *answer, int anslen)
{
    (void) statep;
    (void) dname;
    (void) class;
    (void) type;
    (void) answer;
    (void) anslen;

    ENTER();
    return 0;
}

/****************************************************************************/
int res_nquerydomain(res_state statep, const char *name, const char *domain,
                     int class, int type, unsigned char *answer, int anslen)
{
    (void) statep;
    (void) name;
    (void) domain;
    (void) class;
    (void) type;
    (void) answer;
    (void) anslen;

    ENTER();
    return 0;
}

/****************************************************************************/
int res_nsearch(res_state statep, const char *dname, int class, int type,
                unsigned char *answer, int anslen)
{
    (void) statep;
    (void) dname;
    (void) class;
    (void) type;
    (void) answer;
    (void) anslen;

    ENTER();
    return 0;
}

/****************************************************************************/
int res_nsend(res_state statep, const unsigned char *msg, int msglen,
              unsigned char *answer, int anslen)
{
    (void) statep;
    (void) msg;
    (void) msglen;
    (void) answer;
    (void) anslen;

    ENTER();
    return 0;
}
#endif /* CLIB2_RESOLV_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SCHED_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sched.h>
/****************************************************************************/
int sched_getcpu(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
int sched_get_priority_max(int policy)
{
    (void) policy;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_get_priority_min(int policy)
{
    (void) policy;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask)
{
    (void) pid;
    (void) cpusetsize;
    (void) mask;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_getparam(pid_t pid, struct sched_param *param)
{
    (void) pid;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_getscheduler(pid_t pid)
{
    (void) pid;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_rr_get_interval(pid_t pid, struct timespec *tp)
{
    (void) pid;
    (void) tp;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask)
{
    (void) pid;
    (void) cpusetsize;
    (void) mask;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_setparam(pid_t pid, const struct sched_param *param)
{
    (void) pid;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param)
{
    (void) pid;
    (void) policy;
    (void) param;

    ENTER();
    return 0;
}

/****************************************************************************/
int sched_yield(void)
{
    ENTER();
    return 0;
}
#endif /* CLIB2_SCHED_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SEMAPHORE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <semaphore.h>
/****************************************************************************/
int sem_close(sem_t *sem)
{
    (void) sem;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_destroy(sem_t *sem)
{
    (void) sem;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_getvalue(sem_t *sem, int *sval)
{
    (void) sem;
    (void) sval;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_init(sem_t *sem, int pshared, unsigned int value)
{
    (void) sem;
    (void) pshared;
    (void) value;

    ENTER();
    return 0;
}

/****************************************************************************/
sem_t * sem_open(const char *name, int oflag, ...)
{
    (void) name;
    (void) oflag;

    ENTER();
    return NULL;
}

/****************************************************************************/
int sem_post(sem_t *sem)
{
    (void) sem;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout)
{
    (void) sem;
    (void) abs_timeout;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_trywait(sem_t *sem)
{
    (void) sem;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_unlink(const char *name)
{
    (void) name;

    ENTER();
    return 0;
}

/****************************************************************************/
int sem_wait(sem_t *sem)
{
    (void) sem;

    ENTER();
    return 0;
}
#endif /* CLIB2_SEMAPHORE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SIGNAL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <signal.h>
/****************************************************************************/
int sigemptyset(sigset_t *set)
{
    (void) set;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigfillset(sigset_t *set)
{
    (void) set;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigdelset(sigset_t *set, int signo)
{
    (void) set;
    (void) signo;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigismember(const sigset_t *set, int signo)
{
    (void) set;
    (void) signo;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigsuspend(const sigset_t *sigmask)
{
    (void) sigmask;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigaction(int sig, const struct sigaction *restrict act,
              struct sigaction *restrict oact)
{
    (void) sig;
    (void) act;
    (void) oact;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigpending(sigset_t *set)
{
    (void) set;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigwait(const sigset_t *set, int *sig)
{
    (void) set;
    (void) sig;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigwaitinfo(const sigset_t *set, siginfo_t *info)
{
    (void) set;
    (void) info;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigtimedwait(const sigset_t *set, siginfo_t *info,
                 const struct timespec *timeout)
{
    (void) set;
    (void) info;
    (void) timeout;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigqueue(pid_t pid, int sig, const union sigval value)
{
    (void) pid;
    (void) sig;
    (void) value;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigaltstack(const stack_t *ss, stack_t *old_ss)
{
    (void) ss;
    (void) old_ss;

    ENTER();
    return 0;
}

/****************************************************************************/
int sighold(int sig)
{
    (void) sig;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigignore(int sig)
{
    (void) sig;

    ENTER();
    return 0;
}

/****************************************************************************/
int siginterrupt(int sig, int flag)
{
    (void) sig;
    (void) flag;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigpause(int sig)
{
    (void) sig;

    ENTER();
    return 0;
}

/****************************************************************************/
int sigrelse(int sig)
{
    (void) sig;

    ENTER();
    return 0;
}
#endif /* CLIB2_SIGNAL_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SPAWN_STUB) || defined(CLIB2_MULTUM_STUB)
#include <spawn.h>
/****************************************************************************/
int posix_spawn(pid_t *pid, const char *path,
                const posix_spawn_file_actions_t *file_actions,
                const posix_spawnattr_t *attrp, char *const argv[],
                char *const envp[])
{
    (void) pid;
    (void) path;
    (void) file_actions;
    (void) attrp;
    (void) argv;
    (void) envp;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawn_file_actions_addclose(
                posix_spawn_file_actions_t *file_actions, int fildes)
{
    (void) file_actions;
    (void) fildes;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *file_actions,
                                     int fildes, int newfildes)
{
    (void) file_actions;
    (void) fildes;
    (void) newfildes;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawn_file_actions_addopen(
                posix_spawn_file_actions_t *restrict file_actions,
                int fildes, const char *restrict path, int oflag, mode_t mode)
{
    (void) file_actions;
    (void) fildes;
    (void) path;
    (void) oflag;
    (void) mode;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawn_file_actions_destroy(
                posix_spawn_file_actions_t *file_actions)
{
    (void) file_actions;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawn_file_actions_init(posix_spawn_file_actions_t *file_actions)
{
    (void) file_actions;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_destroy(posix_spawnattr_t *attr)
{
    (void) attr;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_getflags(const posix_spawnattr_t *restrict attr,
                             short *restrict flags)
{
    (void) attr;
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_getpgroup(const posix_spawnattr_t *restrict attr,
                              pid_t *restrict pgroup)
{
    (void) attr;
    (void) pgroup;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_getschedparam(const posix_spawnattr_t *restrict attr,
                                  struct sched_param *restrict schedparam)
{
    (void) attr;
    (void) schedparam;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_getschedpolicy(const posix_spawnattr_t *restrict attr,
                                   int *restrict schedpolicy)
{
    (void) attr;
    (void) schedpolicy;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_getsigdefault(const posix_spawnattr_t *restrict attr,
                                  sigset_t *restrict sigdefault)
{
    (void) attr;
    (void) sigdefault;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_getsigmask(const posix_spawnattr_t *restrict attr,
                               sigset_t *restrict sigmask)
{
    (void) attr;
    (void) sigmask;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_init(posix_spawnattr_t *attr)
{
    (void) attr;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_setflags(posix_spawnattr_t *attr, short flags)
{
    (void) attr;
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_setpgroup(posix_spawnattr_t *attr, pid_t pgroup)
{
    (void) attr;
    (void) pgroup;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_setschedparam(posix_spawnattr_t *restrict attr,
                            const struct sched_param *restrict schedparam)
{
    (void) attr;
    (void) schedparam;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_setschedpolicy(posix_spawnattr_t *attr,
                                          int schedpolicy)
{
    (void) attr;
    (void) schedpolicy;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_setsigdefault(posix_spawnattr_t *restrict attr,
                                  const sigset_t *restrict sigdefault)
{
    (void) attr;
    (void) sigdefault;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnattr_setsigmask(posix_spawnattr_t *restrict attr,
                               const sigset_t *restrict sigmask)
{
    (void) attr;
    (void) sigmask;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_spawnp(pid_t *pid, const char *file,
                 const posix_spawn_file_actions_t *file_actions,
                 const posix_spawnattr_t *attrp, char *const argv[],
                 char *const envp[])
{
    (void) pid;
    (void) file;
    (void) file_actions;
    (void) attrp;
    (void) argv;
    (void) envp;

    ENTER();
    return 0;
}
#endif /* CLIB2_SPAWN_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STDIO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <stdio.h>
/****************************************************************************/
FILE *fmemopen(void *buf, size_t size, const char *mode)
{
    (void) buf;
    (void) size;
    (void) mode;

    ENTER();
    return NULL;
}

/****************************************************************************/
FILE *open_memstream(char **ptr, size_t *sizeloc)
{
    (void) ptr;
    (void) sizeloc;

    ENTER();
    return NULL;
}

/****************************************************************************/
FILE *open_wmemstream(wchar_t **ptr, size_t *sizeloc)
{
    (void) ptr;
    (void) sizeloc;

    ENTER();
    return NULL;
}

/****************************************************************************/
int dprintf(int fildes, const char *restrict format, ...)
{
    (void) fildes;
    (void) format;

    ENTER();
    return 0;
}

/****************************************************************************/
int vdprintf(int fd, const char *format, va_list ap)
{
    (void) fd;
    (void) format;
    (void) ap;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t getdelim(char **restrict lineptr, size_t *restrict n, int delimiter,
                 FILE *restrict stream)
{
    (void) lineptr;
    (void) n;
    (void) delimiter;
    (void) stream;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t getline(char **restrict lineptr, size_t *restrict n,
                FILE *restrict stream)
{
    (void) lineptr;
    (void) n;
    (void) stream;

    ENTER();
    return 0;
}

/****************************************************************************/
int renameat(int oldfd, const char *old, int newfd, const char *new)
{
    (void) oldfd;
    (void) old;
    (void) newfd;
    (void) new;

    ENTER();
    return 0;
}
#endif /* CLIB2_STDIO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STDLIB_STUB) || defined(CLIB2_MULTUM_STUB)
#include <stdlib.h>
/****************************************************************************/
long int a64l(const char *str64)
{
    (void) str64;

    ENTER();
    return 0;
}

/****************************************************************************/
void *aligned_alloc(size_t alignment, size_t size)
{
    (void) alignment;
    (void) size;

    ENTER();
    return NULL;
}

/****************************************************************************/
int at_quick_exit(void (*func)(void))
{
    (void) func;

    ENTER();
    return 0;
}

/****************************************************************************/
int clearenv(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
double drand48(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
char *ecvt(double number, int ndigits, int *decpt, int *sign)
{
    (void) number;
    (void) ndigits;
    (void) decpt;
    (void) sign;

    ENTER();
    return NULL;
}

/****************************************************************************/
double erand48(unsigned short xsubi[3])
{
    (void) xsubi;

    ENTER();
    return 0;
}

/****************************************************************************/
char *fcvt(double number, int ndigits, int *decpt, int *sign)
{
    (void) number;
    (void) ndigits;
    (void) decpt;
    (void) sign;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *gcvt(double number, int ndigits, char *buf)
{
    (void) number;
    (void) ndigits;
    (void) buf;

    ENTER();
    return NULL;
}

/****************************************************************************/
int getloadavg(double loadavg[], int nelem)
{
    (void) loadavg;
    (void) nelem;

    ENTER();
    return 0;
}

/****************************************************************************/
int getsubopt(char **optionp, char * const *tokens, char **valuep)
{
    (void) optionp;
    (void) tokens;
    (void) valuep;

    ENTER();
    return 0;
}

/****************************************************************************/
int grantpt(int fd)
{
    (void) fd;

    ENTER();
    return 0;
}

/****************************************************************************/
char *initstate(unsigned seed, char *state, size_t n)
{
    (void) seed;
    (void) state;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
long int jrand48(unsigned short xsubi[3])
{
    (void) xsubi;

    ENTER();
    return 0;
}

/****************************************************************************/
char *l64a(long value)
{
    (void) value;

    ENTER();
    return NULL;
}

/****************************************************************************/
void lcong48(unsigned short param[7])
{
    (void) param;

    ENTER();
}

/****************************************************************************/
long int lrand48(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
size_t malloc_usable_size(void *ptr)
{
    (void) ptr;

    ENTER();
    return 0;
}

/****************************************************************************/
void *memalign(size_t alignment, size_t size)
{
    (void) alignment;
    (void) size;

    ENTER();
    return NULL;
}

/****************************************************************************/
int mkostemp(char *template, int flags)
{
    (void) template;
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
long int mrand48(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
int mkostemps(char *template, int suffixlen, int flags)
{
    (void) template;
    (void) suffixlen;
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
int mkstemps(char *template, int suffixlen)
{
    (void) template;
    (void) suffixlen;

    ENTER();
    return 0;
}

/****************************************************************************/
long int nrand48(unsigned short xsubi[3])
{
    (void) xsubi;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_memalign(void **memptr, size_t alignment, size_t size)
{
    (void) memptr;
    (void) alignment;
    (void) size;

    ENTER();
    return 0;
}

/****************************************************************************/
int posix_openpt(int flags)
{
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
char *ptsname(int fd)
{
    (void) fd;

    ENTER();
    return NULL;
}

/****************************************************************************/
int ptsname_r(int fd, char *buf, size_t buflen)
{
    (void) fd;
    (void) buf;
    (void) buflen;

    ENTER();
    return 0;
}

/****************************************************************************/
long int random(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    (void) ptr;
    (void) nmemb;
    (void) size;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *realpath(const char *path, char *resolved_path)
{
    (void) path;
    (void) resolved_path;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *secure_getenv(const char *name)
{
    (void) name;

    ENTER();
    return NULL;
}

/****************************************************************************/
unsigned short *seed48(unsigned short seed16v[3])
{
    (void) seed16v;

    ENTER();
    return 0;
}

/****************************************************************************/
void setkey(const char *key)
{
    (void) key;

    ENTER();
}

/****************************************************************************/
char *setstate(char *state)
{
    (void) state;

    ENTER();
    return NULL;
}

/****************************************************************************/
void srand48(long int seedval)
{
    (void) seedval;

    ENTER();
}

/****************************************************************************/
void srandom(unsigned int seed)
{
    (void) seed;

    ENTER();
}

/****************************************************************************/
float strtof_l(const char *nptr, char **endptr, locale_t loc)
{
    (void) nptr;
    (void) endptr;
    (void) loc;

    ENTER();
    return 0;
}

/****************************************************************************/
double strtod_l(const char *nptr, char **endptr, locale_t loc)
{
    (void) nptr;
    (void) endptr;
    (void) loc;

    ENTER();
    return 0;
}

/****************************************************************************/
long double strtold(const char *nptr, char **endptr)
{
    (void) nptr;
    (void) endptr;

    ENTER();
    return 0;
}

/****************************************************************************/
long double strtold_l(const char *nptr, char **endptr, locale_t loc)
{
    (void) nptr;
    (void) endptr;
    (void) loc;

    ENTER();
    return 0;
}

/****************************************************************************/
int unlockpt(int fd)
{
    (void) fd;

    ENTER();
    return 0;
}

/****************************************************************************/
void *valloc(size_t size)
{
    (void) size;

    ENTER();
    return NULL;
}
#endif /* CLIB2_STDLIB_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STRING_STUB) || defined(CLIB2_MULTUM_STUB)
#include <string.h>
/****************************************************************************/
void explicit_bzero(void *s, size_t n)
{
    (void) s;
    (void) n;

    ENTER();
}

/****************************************************************************/
void *memrchr(const void *s, int c, size_t n)
{
    (void) s;
    (void) c;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
void *memccpy(void *dest, const void *src, int c, size_t n)
{
    (void) dest;
    (void) src;
    (void) c;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
void *memmem(const void *haystack, size_t haystacklen, const void *needle,
             size_t needlelen)
{
    (void) haystack;
    (void) haystacklen;
    (void) needle;
    (void) needlelen;

    ENTER();
    return NULL;
}

/****************************************************************************/
void *mempcpy(void *dest, const void *src, size_t n)
{
    (void) dest;
    (void) src;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *stpcpy(char *dest, const char *src)
{
    (void) dest;
    (void) src;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *stpncpy(char *dest, const char *src, size_t n)
{
    (void) dest;
    (void) src;
    (void) n;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *strcasestr(const char *haystack, const char *needle)
{
    (void) haystack;
    (void) needle;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *strchrnul(const char *s, int c)
{
    (void) s;
    (void) c;

    ENTER();
    return NULL;
}

/****************************************************************************/
int strcoll_l(const char *s1, const char *s2, locale_t locale)
{
    (void) s1;
    (void) s2;
    (void) locale;

    ENTER();
    return 0;
}

/****************************************************************************/
char *strerror_l(int errnum, locale_t locale)
{
    (void) errnum;
    (void) locale;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *strndup(const char *s, size_t size)
{
    (void) s;
    (void) size;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *strsep(char **stringp, const char *delim)
{
    (void) stringp;
    (void) delim;

    ENTER();
    return NULL;
}

/****************************************************************************/
char *strsignal(int sig)
{
    (void) sig;

    ENTER();
    return NULL;
}

/****************************************************************************/
int strverscmp(const char *s1, const char *s2)
{
    (void) s1;
    (void) s2;

    ENTER();
    return 0;
}

/****************************************************************************/
size_t strxfrm_l(char *restrict s1, const char *restrict s2, size_t n,
                 locale_t locale)
{
    (void) s1;
    (void) s2;
    (void) n;
    (void) locale;

    ENTER();
    return 0;
}
#endif /* CLIB2_STRING_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STROPTS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <stropts.h>
/****************************************************************************/
int isastream(int fildes)
{
    (void) fildes;

    ENTER();
    return 0;
}

/****************************************************************************/
int ioctl(int fd, unsigned long request, ...)
{
    (void) fd;
    (void) request;

    ENTER();
    return 0;
}
#endif /* CLIB2_STROPTS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_ACCT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/acct.h>
/****************************************************************************/
int acct(const char *filename)
{
    (void) filename;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_ACCT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_FILE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/file.h>
/****************************************************************************/
int flock(int fd, int operation)
{
    (void) fd;
    (void) operation;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_FILE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_IPC_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/ipc.h>
/****************************************************************************/
key_t ftok(char *pathname, char proj_id)
{
    (void) pathname;
    (void) proj_id;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_IPC_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_MMAN_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/mman.h>
/****************************************************************************/
int madvise(void *addr, size_t length, int advice)
{
    (void) addr;
    (void) length;
    (void) advice;

    ENTER();
    return 0;
}

/****************************************************************************/
int mincore(void *addr, size_t length, unsigned char *vec)
{
    (void) addr;
    (void) length;
    (void) vec;

    ENTER();
    return 0;
}

/****************************************************************************/
int mlock(const void *addr, size_t len)
{
    (void) addr;
    (void) len;

    ENTER();
    return 0;
}

/****************************************************************************/
int mlockall(int flags)
{
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset)
{
    (void) addr;
    (void) length;
    (void) prot;
    (void) flags;
    (void) fd;
    (void) offset;

    ENTER();
    return NULL;
}

/****************************************************************************/
int munmap(void *addr, size_t length)
{
    (void) addr;
    (void) length;

    ENTER();
    return 0;
}

/****************************************************************************/
int mprotect(void *addr, size_t len, int prot)
{
    (void) addr;
    (void) len;
    (void) prot;

    ENTER();
    return 0;
}

/****************************************************************************/
void *mremap(void *old_address, size_t old_size, size_t new_size,
             int flags, ...)
{
    (void) old_address;
    (void) old_size;
    (void) new_size;
    (void) flags;

    ENTER();
    return NULL;
}

/****************************************************************************/
int msync(void *addr, size_t length, int flags)
{
    (void) addr;
    (void) length;
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
int munlock(const void *addr, size_t len)
{
    (void) addr;
    (void) len;

    ENTER();
    return 0;
}

/****************************************************************************/
int munlockall(void)
{
    ENTER();
    return 0;
}

/****************************************************************************/
int posix_madvise(void *addr, size_t len, int advice)
{
    (void) addr;
    (void) len;
    (void) advice;

    ENTER();
    return 0;
}

/****************************************************************************/
int remap_file_pages(void *addr, size_t size, int prot, size_t pgoff,
                     int flags)
{
    (void) addr;
    (void) size;
    (void) prot;
    (void) pgoff;
    (void) flags;

    ENTER();
    return 0;
}

/****************************************************************************/
int shm_open(const char *name, int oflag, mode_t mode)
{
    (void) name;
    (void) oflag;
    (void) mode;

    ENTER();
    return 0;
}

/****************************************************************************/
int shm_unlink(const char *name)
{
    (void) name;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_MMAN_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_MSG_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/msg.h>
/****************************************************************************/
int msgctl(int msqid, int cmd, struct msqid_ds *buf)
{
    (void) msqid;
    (void) cmd;
    (void) buf;

    ENTER();
    return 0;
}

/****************************************************************************/
int msgget(key_t key, int msgflg)
{
    (void) key;
    (void) msgflg;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
               int msgflg)
{
    (void) msqid;
    (void) msgp;
    (void) msgsz;
    (void) msgtyp;
    (void) msgflg;

    ENTER();
    return 0;
}

/****************************************************************************/
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
    (void) msqid;
    (void) msgp;
    (void) msgsz;
    (void) msgflg;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_MSG_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/ptrace.h>
/****************************************************************************/
long int ptrace(enum __ptrace_request_dummy request, pid_t pid,
                void *addr, void *data)
{
    (void) request;
    (void) pid;
    (void) addr;
    (void) data;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_RESOURCE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/resource.h>
/****************************************************************************/
int getrusage(int who, struct rusage *usage)
{
    (void) who;
    (void) usage;

    ENTER();
    return 0;
}

/****************************************************************************/
int getpriority(int which, id_t who)
{
    (void) which;
    (void) who;

    ENTER();
    return 0;
}

/****************************************************************************/
int setpriority(int which, id_t who, int prio)
{
    (void) which;
    (void) who;
    (void) prio;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_RESOURCE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SELECT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/select.h>
/****************************************************************************/
int pselect(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
            fd_set *restrict errorfds,
            const struct timespec *restrict timeout,
            const sigset_t *restrict sigmask)
{
    (void) nfds;
    (void) readfds;
    (void) writefds;
    (void) errorfds;
    (void) timeout;
    (void) sigmask;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_SELECT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SEM_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/sem.h>
/****************************************************************************/
int semctl(int semid, int semnum, int cmd, ...)
{
    (void) semid;
    (void) semnum;
    (void) cmd;

    ENTER();
    return 0;
}

/****************************************************************************/
int semget(key_t key, int nsems, int semflg)
{
    (void) key;
    (void) nsems;
    (void) semflg;

    ENTER();
    return 0;
}

/****************************************************************************/
int semop(int semid, struct sembuf *sops, size_t nsops)
{
    (void) semid;
    (void) sops;
    (void) nsops;

    ENTER();
    return 0;
}

/****************************************************************************/
int semtimedop(int semid, struct sembuf *sops, size_t nsops,
               const struct timespec *timeout)
{
    (void) semid;
    (void) sops;
    (void) nsops;
    (void) timeout;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_SEM_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SHM_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/shm.h>
/****************************************************************************/
void *shmat(int shmid, const void *shmaddr, int shmflg)
{
    (void) shmid;
    (void) shmaddr;
    (void) shmflg;

    ENTER();
    return NULL;
}

/****************************************************************************/
int shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
    (void) shmid;
    (void) cmd;
    (void) buf;

    ENTER();
    return 0;
}

/****************************************************************************/
int shmdt(const void *shmaddr)
{
    (void) shmaddr;

    ENTER();
    return 0;
}

/****************************************************************************/
int shmget(key_t key, size_t size, int shmflg)
{
    (void) key;
    (void) size;
    (void) shmflg;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_SHM_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SOCKET_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/socket.h>
/****************************************************************************/
int socketpair(int domain, int type, int protocol, int sv[2])
{
    (void) domain;
    (void) type;
    (void) protocol;
    (void) sv;

    ENTER();
    return 0;
}

/****************************************************************************/
int sockatmark(int sockfd)
{
    (void) sockfd;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_SOCKET_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_STAT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/stat.h>
/****************************************************************************/
int fchmodat(int fd, const char *path, mode_t mode, int flag)
{
    (void) fd;
    (void) path;
    (void) mode;
    (void) flag;

    ENTER();
    return 0;
}

/****************************************************************************/
int fstatat(int fd, const char *restrict path, struct stat *restrict buf,
            int flag)
{
    (void) fd;
    (void) path;
    (void) buf;
    (void) flag;

    ENTER();
    return 0;
}

/****************************************************************************/
int mkdirat(int fd, const char *path, mode_t mode)
{
    (void) fd;
    (void) path;
    (void) mode;

    ENTER();
    return 0;
}

/****************************************************************************/
int mkfifo(const char *pathname, mode_t mode)
{
    (void) pathname;
    (void) mode;

    ENTER();
    return 0;
}

/****************************************************************************/
int mkfifoat(int dirfd, const char *pathname, mode_t mode)
{
    (void) dirfd;
    (void) pathname;
    (void) mode;

    ENTER();
    return 0;
}

/****************************************************************************/
int mknod(const char *pathname, mode_t mode, dev_t dev)
{
    (void) pathname;
    (void) mode;
    (void) dev;

    ENTER();
    return 0;
}

/****************************************************************************/
int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev)
{
    (void) dirfd;
    (void) pathname;
    (void) mode;
    (void) dev;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_STAT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/statvfs.h>
/****************************************************************************/
int fstatvfs(int fd, struct statvfs *buf)
{
    (void) fd;
    (void) buf;

    ENTER();
    return 0;
}

/****************************************************************************/
int statvfs(const char *restrict path, struct statvfs *restrict buf)
{
    (void) path;
    (void) buf;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_TIME_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/time.h>
/****************************************************************************/
int futimes(int fd, const struct timeval tv[2])
{
    (void) fd;
    (void) tv;

    ENTER();
    return 0;
}

/****************************************************************************/
int futimesat(int dirfd, const char *pathname, const struct timeval times[2])
{
    (void) dirfd;
    (void) pathname;
    (void) times;

    ENTER();
    return 0;
}

/****************************************************************************/
int futimens(int fd, const struct timespec times[2])
{
    (void) fd;
    (void) times;

    ENTER();
    return 0;
}

/****************************************************************************/
int getitimer(int which, struct itimerval *curr_value)
{
    (void) which;
    (void) curr_value;

    ENTER();
    return 0;
}

/****************************************************************************/
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    (void) tv;
    (void) tz;

    ENTER();
    return 0;
}

/****************************************************************************/
int lutimes(const char *filename, const struct timeval tv[2])
{
    (void) filename;
    (void) tv;

    ENTER();
    return 0;
}

/****************************************************************************/
int setitimer(int which, const struct itimerval *new_value,
              struct itimerval *old_value)
{
    (void) which;
    (void) new_value;
    (void) old_value;

    ENTER();
    return 0;
}

/****************************************************************************/
int settimeofday(const struct timeval *tv, const struct timezone *tz)
{
    (void) tv;
    (void) tz;

    ENTER();
    return 0;
}

/****************************************************************************/
int utimes(const char *path, const struct timeval times[2])
{
    (void) path;
    (void) times;

    ENTER();
    return 0;
}

/****************************************************************************/
int utimensat(int fd, const char *path, const struct timespec times[2],
              int flag)
{
    (void) fd;
    (void) path;
    (void) times;
    (void) flag;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_TIME_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_UIO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/uio.h>
/****************************************************************************/
ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset)
{
    (void) fd;
    (void) iov;
    (void) iovcnt;
    (void) offset;

    ENTER();
    return 0;
}

/****************************************************************************/
ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset)
{
    (void) fd;
    (void) iov;
    (void) iovcnt;
    (void) offset;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_UIO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_WAIT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/wait.h>
/****************************************************************************/
pid_t wait(int *stat_loc)
{
    (void) stat_loc;

    ENTER();
    return 0;
}

/****************************************************************************/
pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
    (void) pid;
    (void) stat_loc;
    (void) options;

    ENTER();
    return 0;
}

/****************************************************************************/
int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
    (void) idtype;
    (void) id;
    (void) infop;
    (void) options;

    ENTER();
    return 0;
}
#endif /* CLIB2_SYS_WAIT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYSLOG_STUB) || defined(CLIB2_MULTUM_STUB)
#include <syslog.h>
/****************************************************************************/
int setlogmask(int mask)
{
    ENTER();
}

/****************************************************************************/
void openlog(const char *ident, int option, int facility)
{
    ENTER();
}

/****************************************************************************/
void syslog(int priority, const char *format, ...)
{
    ENTER();
}

/****************************************************************************/
void closelog(void)
{
    ENTER();
}
#endif /* CLIB2_SYSLOG_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_TERMIOS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <termios.h>
/****************************************************************************/
pid_t tcgetsid(int fd)
{
    ENTER();
}

/****************************************************************************/
int tcgetwinsize(int fd, struct winsize *gws)
{
    ENTER();
}

/****************************************************************************/
int tcsetwinsize(int fd, const struct winsize *sws)
{
    ENTER();
}
#endif /* CLIB2_TERMIOS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_TIME_STUB) || defined(CLIB2_MULTUM_STUB)
#include <time.h>
/****************************************************************************/
int clock_getcpuclockid(pid_t pid, clockid_t *clockid)
{
    ENTER();
}

/****************************************************************************/
int clock_getres(clockid_t clockid, struct timespec *res)
{
    ENTER();
}

/****************************************************************************/
int clock_gettime(clockid_t clockid, struct timespec *tp)
{
    ENTER();
}

/****************************************************************************/
int clock_nanosleep(clockid_t clockid, int flags,
                    const struct timespec *request, struct timespec *remain)
{
    ENTER();
}

/****************************************************************************/
int clock_settime(clockid_t clockid, const struct timespec *tp)
{
    ENTER();
}

/****************************************************************************/
int nanosleep(const struct timespec *req, struct timespec *rem)
{
    ENTER();
}

/****************************************************************************/
size_t strftime_l(char *restrict s, size_t maxsize,
                  const char *restrict format,
                  const struct tm *restrict timeptr, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int timer_create(clockid_t clockid, struct sigevent *sevp, timer_t *timerid)
{
    ENTER();
}

/****************************************************************************/
int timer_delete(timer_t timerid)
{
    ENTER();
}

/****************************************************************************/
int timer_getoverrun(timer_t timerid)
{
    ENTER();
}

/****************************************************************************/
int timer_gettime(timer_t timerid, struct itimerspec *curr_value)
{
    ENTER();
}

/****************************************************************************/
int timer_settime(timer_t timerid, int flags,
                  const struct itimerspec *new_value,
                  struct itimerspec *old_value)
{
    ENTER();
}
#endif /* CLIB2_TIME_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_UCHAR_STUB) || defined(CLIB2_MULTUM_STUB)
#include <uchar.h>
/****************************************************************************/
size_t c16rtomb(char *s, char16_t c16, mbstate_t *ps)
{
    ENTER();
}

/****************************************************************************/
size_t c32rtomb(char *s, char32_t c32, mbstate_t *ps)
{
    ENTER();
}

/****************************************************************************/
size_t mbrtoc32(char32_t *pc32, const char *s, size_t n, mbstate_t *ps)
{
    ENTER();
}

/****************************************************************************/
size_t mbrtoc16(char16_t *pc16, const char *s, size_t n, mbstate_t *ps)
{
    ENTER();
}
#endif /* CLIB2_UCHAR_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_UCONTEXT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <ucontext.h>
/****************************************************************************/
int getcontext(ucontext_t *ucp)
{
    ENTER();
}

/****************************************************************************/
void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...)
{
    ENTER();
}

/****************************************************************************/
int setcontext(const ucontext_t *ucp)
{
    ENTER();
}

/****************************************************************************/
int swapcontext(ucontext_t *oucp, const ucontext_t *ucp)
{
    ENTER();
}
#endif /* CLIB2_UCONTEXT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_UNISTD_STUB) || defined(CLIB2_MULTUM_STUB)
#include <unistd.h>
/****************************************************************************/
int pipe(int pipefd[2])
{
    ENTER();
}

/****************************************************************************/
int pipe2(int pipefd[2], int flags)
{
    ENTER();
}

/****************************************************************************/
int close(int fd)
{
    ENTER();
}

/****************************************************************************/
int dup3(int oldfd, int newfd, int flags)
{
    ENTER();
}

/****************************************************************************/
off_t lseek(int fd, off_t offset, int whence)
{
    ENTER();
}

/****************************************************************************/
ssize_t read(int fd, void *buf, size_t count)
{
    ENTER();
}

/****************************************************************************/
ssize_t write(int fd, const void *buf, size_t count)
{
    ENTER();
}

/****************************************************************************/
ssize_t pread(int fd, void *buf, size_t count, off_t offset)
{
    ENTER();
}

/****************************************************************************/
ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset)
{
    ENTER();
}

/****************************************************************************/
int fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group,
             int flags)
{
    ENTER();
}

/****************************************************************************/
int linkat(int olddirfd, const char *oldpath, int newdirfd,
           const char *newpath, int flags)
{
    ENTER();
}

/****************************************************************************/
int symlinkat(const char *oldpath, int newdirfd, const char *newpath)
{
    ENTER();
}

/****************************************************************************/
int rmdir(const char *path)
{
    ENTER();
}

/****************************************************************************/
int unlinkat(int dirfd, const char *pathname, int flags)
{
    ENTER();
}

/****************************************************************************/
int faccessat(int dirfd, const char *pathname, int mode, int flags)
{
    ENTER();
}

/****************************************************************************/
int fchdir(int fd)
{
    ENTER();
}

/****************************************************************************/
unsigned alarm(unsigned seconds)
{
    ENTER();
}

/****************************************************************************/
int pause(void)
{
    ENTER();
}

/****************************************************************************/
pid_t getppid(void)
{
    ENTER();
}

/****************************************************************************/
pid_t getpgrp(void)
{
    ENTER();
}

/****************************************************************************/
pid_t getpgid(pid_t pid)
{
    ENTER();
}

/****************************************************************************/
int setpgid(pid_t pid, pid_t pgid)
{
    ENTER();
}

/****************************************************************************/
pid_t getsid(pid_t pid)
{
    ENTER();
}

/****************************************************************************/
pid_t tcgetpgrp(int fd)
{
    ENTER();
}

/****************************************************************************/
int tcsetpgrp(int fd, pid_t pgrp)
{
    ENTER();
}

/****************************************************************************/
char *getlogin(void)
{
    ENTER();
}

/****************************************************************************/
int getlogin_r(char *buf, size_t bufsize)
{
    ENTER();
}

/****************************************************************************/
char *ctermid(char *s)
{
    ENTER();
}

/****************************************************************************/
long sysconf(int name)
{
    ENTER();
}

/****************************************************************************/
size_t confstr(int name, char *buf, size_t len)
{
    ENTER();
}

/****************************************************************************/
int nice(int inc)
{
    ENTER();
}

/****************************************************************************/
void sync(void)
{
    ENTER();
}

/****************************************************************************/
pid_t setpgrp(void)
{
    ENTER();
}

/****************************************************************************/
void encrypt(char block[64], int edflag)
{
    ENTER();
}

/****************************************************************************/
void swab(const void *from, void *to, ssize_t n)
{
    ENTER();
}

/****************************************************************************/
useconds_t ualarm(useconds_t usecs, useconds_t interval)
{
    ENTER();
}
#endif /* CLIB2_UNISTD_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_UTMP_STUB) || defined(CLIB2_MULTUM_STUB)
#include <utmp.h>
/****************************************************************************/
void endutent(void)
{
    ENTER();
}

/****************************************************************************/
struct utmp *getutent(void)
{
    ENTER();
}

/****************************************************************************/
struct utmp *getutid(struct utmp *ut)
{
    ENTER();
}

/****************************************************************************/
struct utmp *getutline(struct utmp *ut)
{
    ENTER();
}

/****************************************************************************/
struct utmp *pututline(struct utmp *ut)
{
    ENTER();
}

/****************************************************************************/
void setutent(void)
{
    ENTER();
}

/****************************************************************************/
int utmpname(const char *file)
{
    ENTER();
}
#endif /* CLIB2_UTMP_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_UTMPX_STUB) || defined(CLIB2_MULTUM_STUB)
#include <utmpx.h>
/****************************************************************************/
void endutxent(void)
{
    ENTER();
}

/****************************************************************************/
struct utmpx *getutxent(void)
{
    ENTER();
}

/****************************************************************************/
struct utmpx *getutxid(const struct utmpx *)
{
    ENTER();
}

/****************************************************************************/
struct utmpx *getutxline(const struct utmpx *)
{
    ENTER();
}

/****************************************************************************/
struct utmpx *pututxline(const struct utmpx *)
{
    ENTER();
}

/****************************************************************************/
void setutxent(void)
{
    ENTER();
}
#endif /* CLIB2_UTMPX_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_WCHAR_STUB) || defined(CLIB2_MULTUM_STUB)
#include <wchar.h>
/****************************************************************************/
wchar_t *wcswcs(const wchar_t *ws1, const wchar_t *ws2)
{
    ENTER();
}

/****************************************************************************/
float wcstof(const wchar_t *restrict nptr, wchar_t **restrict endptr)
{
    ENTER();
}

/****************************************************************************/
long double wcstold(const wchar_t *restrict nptr, wchar_t **restrict endptr)
{
    ENTER();
}

/****************************************************************************/
int vwscanf(const wchar_t *restrict format, va_list arg)
{
    ENTER();
}

/****************************************************************************/
int vfwscanf(FILE *restrict stream, const wchar_t *restrict format,
             va_list arg)
{
    ENTER();
}

/****************************************************************************/
int vswscanf(const wchar_t *restrict ws, const wchar_t *restrict format,
             va_list arg)
{
    ENTER();
}

/****************************************************************************/
wint_t fgetwc_unlocked(FILE *stream)
{
    ENTER();
}

/****************************************************************************/
wint_t getwc_unlocked(FILE *stream)
{
    ENTER();
}

/****************************************************************************/
wint_t getwchar_unlocked(void)
{
    ENTER();
}

/****************************************************************************/
wint_t fputwc_unlocked(wchar_t wc, FILE *stream)
{
    ENTER();
}

/****************************************************************************/
wint_t putwc_unlocked(wchar_t wc, FILE *stream)
{
    ENTER();
}

/****************************************************************************/
wint_t putwchar_unlocked(wchar_t wc)
{
    ENTER();
}

/****************************************************************************/
wchar_t *fgetws_unlocked(wchar_t *ws, int n, FILE *stream)
{
    ENTER();
}

/****************************************************************************/
int fputws_unlocked(const wchar_t *ws, FILE *stream)
{
    ENTER();
}

/****************************************************************************/
size_t wcsftime_l(wchar_t *restrict wcs, size_t maxsize,
                  const wchar_t *restrict format,
                  const struct tm *restrict timeptr, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
FILE *open_wmemstream(wchar_t **ptr, size_t *sizeloc)
{
    ENTER();
}

/****************************************************************************/
wchar_t *wcsdup(const wchar_t *s)
{
    ENTER();
}

/****************************************************************************/
wchar_t *wcpcpy(wchar_t *dest, const wchar_t *src)
{
    ENTER();
}

/****************************************************************************/
wchar_t *wcpncpy(wchar_t *dest, const wchar_t *src, size_t n)
{
    ENTER();
}

/****************************************************************************/
int wcscasecmp(const wchar_t *s1, const wchar_t *s2)
{
    ENTER();
}

/****************************************************************************/
int wcscasecmp_l(const wchar_t *ws1, const wchar_t *ws2,
                        locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int wcsncasecmp(const wchar_t *s1, const wchar_t *s2, size_t n)
{
    ENTER();
}

/****************************************************************************/
int wcsncasecmp_l(const wchar_t *ws1, const wchar_t *ws2, size_t n,
                  locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int wcwidth(wchar_t c)
{
    ENTER();
}

/****************************************************************************/
int wcswidth(const wchar_t *s, size_t n)
{
    ENTER();
}
#endif /* CLIB2_WCHAR_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_WCTYPE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <wctype.h>
/****************************************************************************/
int iswalnum_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswalpha_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswcntrl_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswdigit_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswxdigit_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswgraph_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswpunct_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswprint_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswlower_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswupper_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswspace_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
int iswblank_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
wint_t towlower_l(wint_t c, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
wint_t towupper_l(wint_t c, locale_t locale)
{
    ENTER();
}
#endif /* CLIB2_WCTYPE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_WORDEXP_STUB) || defined(CLIB2_MULTUM_STUB)
#include <wordexp.h>
/****************************************************************************/
int wordexp(const char *s, wordexp_t *p, int flags)
{
    ENTER();
}

/****************************************************************************/
void wordfree(wordexp_t *p)
{
    ENTER();
}
#endif /* CLIB2_WORDEXP_STUB) || defined(CLIB2_MULTUM_STUB) */
