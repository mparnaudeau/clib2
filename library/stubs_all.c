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
    ENTER();
}
#endif /* CLIB2_FENV_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FMTMSG_STUB) || defined(CLIB2_MULTUM_STUB)
#include <fmtmsg.h>
/****************************************************************************/
int fmtmsg(long classification, const char *label, int severity,
           const char *text, const char *action, const char *tag)
{
    ENTER();
}
#endif /* CLIB2_FMTMSG_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FNMATCH_STUB) || defined(CLIB2_MULTUM_STUB)
#include <fnmatch.h>
/****************************************************************************/
int fnmatch(const char *pattern, const char *string, int flags)
{
    ENTER();
}
#endif /* CLIB2_FNMATCH_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_FTW_STUB) || defined(CLIB2_MULTUM_STUB)
#include <ftw.h>
/****************************************************************************/
int ftw64(const char *dirpath, int (*fn) (const char *fpath,
          const struct stat *sb, int typeflag), int nopenfd)
{
    ENTER();
}

/****************************************************************************/
int nftw64(const char *dirpath, int (*fn) (const char *fpath,
           const struct stat *sb, int typeflag, struct FTW *ftwbuf),
           int nopenfd, int flags)
{
    ENTER();
}
#endif /* CLIB2_FTW_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_GETOPT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <getopt.h>
/****************************************************************************/
int getopt(int argc, char * const argv[], const char *optstring)
{
    ENTER();
}

/****************************************************************************/
int getopt_long_only(int argc, const char **argv, const char *optstring,
		             const struct option *longopts, int *longindex)
{
    ENTER();
}
#endif /* CLIB2_GETOPT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_GLOB_STUB) || defined(CLIB2_MULTUM_STUB)
#include <glob.h>
/****************************************************************************/
int glob(const char *pattern, int flags,
         int (*errfunc) (const char *epath, int eerrno), glob_t *pglob)
{
    ENTER();
}

/****************************************************************************/
void globfree(glob_t *pglob)
{
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
    ENTER();
}

/****************************************************************************/
int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen,
               struct group **result)
{
    ENTER();
}
#endif /* CLIB2_GRP_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_ICONV_STUB) || defined(CLIB2_MULTUM_STUB)
#include <iconv.h>
/****************************************************************************/
size_t iconv(iconv_t cd, char **inbuf, size_t *inbytesleft, char **outbuf,
             size_t *outbytesleft)
{
    ENTER();
}

/****************************************************************************/
iconv_t iconv_open(const char *tocode, const char *fromcode)
{
    ENTER();
}

/****************************************************************************/
int iconv_close(iconv_t cd)
{
    ENTER();
}
#endif /* CLIB2_ICONV_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_IFADDRS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <ifaddrs.h>
/****************************************************************************/
int getifaddrs(struct ifaddrs **ifap)
{
    ENTER();
}

/****************************************************************************/
void freeifaddrs(struct ifaddrs *ifa)
{
    ENTER();
}
#endif /* CLIB2_IFADDRS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_LANGINFO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <langinfo.h>
/****************************************************************************/
char *nl_langinfo(nl_item item)
{
    ENTER();
}

/****************************************************************************/
char *nl_langinfo_l(nl_item item, locale_t locale)
{
    ENTER();
}
#endif /* CLIB2_LANGINFO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_LIBINTL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <libintl.h>
/****************************************************************************/
char *bindtextdomain(const char * domainname, const char * dirname)
{
    ENTER();
}

/****************************************************************************/
char *bind_textdomain_codeset(const char * domainname, const char * codeset)
{
    ENTER();
}

/****************************************************************************/
char *dgettext(const char * domainname, const char * msgid)
{
    ENTER();
}

/****************************************************************************/
char *dcgettext(const char * domainname, const char * msgid, int category)
{
    ENTER();
}

/****************************************************************************/
char *ngettext(const char * msgid, const char * msgid_plural,
               unsigned long int n)
{
    ENTER();
}

/****************************************************************************/
char *dngettext(const char * domainname, const char * msgid,
                const char * msgid_plural, unsigned long int n)
{
    ENTER();
}

/****************************************************************************/
char *dcngettext(const char * domainname, const char * msgid,
                 const char * msgid_plural, unsigned long int n, int category)
{
    ENTER();
}

/****************************************************************************/
char *gettext(const char * msgid)
{
    ENTER();
}

/****************************************************************************/
char *textdomain(const char * domainname)
{
    ENTER();
}
#endif /* CLIB2_LIBINTL_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_LOCALE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <locale.h>
/****************************************************************************/
locale_t duplocale(locale_t locobj)
{
    ENTER();
}

/****************************************************************************/
locale_t newlocale(int category_mask, const char *locale, locale_t base)
{
    ENTER();
}

/****************************************************************************/
void freelocale(locale_t locobj)
{
    ENTER();
}

/****************************************************************************/
locale_t uselocale(locale_t newloc)
{
    ENTER();
}
#endif /* CLIB2_LOCALE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_MATH_STUB) || defined(CLIB2_MULTUM_STUB)
#include <math.h>
/****************************************************************************/
long double acosl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double acoshl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double asinl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double asinhl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double atanl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double atan2l(long double y, long double x)
{
    ENTER();
}

/****************************************************************************/
long double atanhl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double cbrtl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double ceill(long double x)
{
    ENTER();
}

/****************************************************************************/
long double copysignl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double cosl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double coshl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double erfl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double erfcl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double expl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double exp2l(long double x)
{
    ENTER();
}

/****************************************************************************/
long double expm1l(long double x)
{
    ENTER();
}

/****************************************************************************/
long double fabsl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double fdiml(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double floorl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double fmal(long double x, long double y, long double z)
{
    ENTER();
}

/****************************************************************************/
long double fmaxl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double fminl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double fmodl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double frexpl(long double x, int *nptr)
{
    ENTER();
}

/****************************************************************************/
long double hypotl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
int ilogbl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double ldexpl(long double x, int n)
{
    ENTER();
}

/****************************************************************************/
long double lgammal(long double x)
{
    ENTER();
}

/****************************************************************************/
long long llrintl(long double x)
{
    ENTER();
}

/****************************************************************************/
long long lroundl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double logl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double log10l(long double x)
{
    ENTER();
}

/****************************************************************************/
long double log1pl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double log2l(long double x)
{
    ENTER();
}

/****************************************************************************/
long double logbl(long double x)
{
    ENTER();
}

/****************************************************************************/
long lrintl(long double x)
{
    ENTER();
}

/****************************************************************************/
long lroundl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double modfl(long double x, long double *iptr)
{
    ENTER();
}

/****************************************************************************/
long double nanl(const char *tagp)
{
    ENTER();
}

/****************************************************************************/
long double nearbyintl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double nextafterl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double nexttowardl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double powl(long double x, long double y)
{
    ENTER();
}

/****************************************************************************/
long double remainderl(long double x, long double p)
{
    ENTER();
}

/****************************************************************************/
long double remquol(long double x, long double y, int *quo)
{
    ENTER();
}

/****************************************************************************/
long double rintl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double roundl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double scalblnl(long double x, long int n)
{
    ENTER();
}

/****************************************************************************/
long double scalbnl(long double x, int n)
{
    ENTER();
}

/****************************************************************************/
long double sinl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double sinhl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double sqrtl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double tanl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double tanhl(long double x)
{
    ENTER();
}

/****************************************************************************/
long double tgammal(long double x)
{
    ENTER();
}

/****************************************************************************/
long double truncl(long double x)
{
    ENTER();
}
#endif /* CLIB2_MATH_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_MONETARY_STUB) || defined(CLIB2_MULTUM_STUB)
#include <monetary.h>
/****************************************************************************/
ssize_t strfmon(char *s, size_t max, const char *format, ...)
{
    ENTER();
}

/****************************************************************************/
ssize_t strfmon_l(char *s, size_t max, locale_t locale,
                  const char *format, ...)
{
    ENTER();
}
#endif /* CLIB2_MONETARY_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_MQUEUE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <mqueue.h>
/****************************************************************************/
int mq_close(mqd_t mqdes)
{
    ENTER();
}

/****************************************************************************/
int mq_getattr(mqd_t mqdes, struct mq_attr *attr)
{
    ENTER();
}

/****************************************************************************/
int mq_notify(mqd_t mqdes, const struct sigevent *sevp)
{
    ENTER();
}

/****************************************************************************/
mqd_t mq_open( const char *name, int oflag, ...)
{
    ENTER();
}

/****************************************************************************/
ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                   unsigned int *msg_prio)
{
    ENTER();
}

/****************************************************************************/
int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
            unsigned int msg_prio)
{
    ENTER();
}

/****************************************************************************/
int mq_setattr(mqd_t mqdes, const struct mq_attr *newattr,
               struct mq_attr *oldattr)
{
    ENTER();
}

/****************************************************************************/
ssize_t mq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                        unsigned int *msg_prio,
                        const struct timespec *abs_timeout)
{
    ENTER();
}

/****************************************************************************/
int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
                 unsigned int msg_prio,
                 const struct timespec *abs_timeout)
{
    ENTER();
}

/****************************************************************************/
int mq_unlink(const char *name)
{
    ENTER();
}
#endif /* CLIB2_MQUEUE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NETDB_STUB) || defined(CLIB2_MULTUM_STUB)
#include <netdb.h>
/****************************************************************************/
struct netent *getnetent(void)
{
    ENTER();
}

/****************************************************************************/
struct netent *getnetbyaddr(uint32_t net, int type)
{
    ENTER();
}

/****************************************************************************/
void setnetent(int stayopen)
{
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
}

/****************************************************************************/
struct servent *getservbyname(const char *name, const char *proto)
{
    ENTER();
}

/****************************************************************************/
struct servent *getservbyport(int port, const char *proto)
{
    ENTER();
}

/****************************************************************************/
struct hostent *gethostent(void)
{
    ENTER();
}
#endif /* CLIB2_NETDB_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NET_IF_STUB) || defined(CLIB2_MULTUM_STUB)
#include <net/if.h>
/****************************************************************************/
unsigned int if_nametoindex(const char *ifname)
{
    ENTER();
}

/****************************************************************************/
char *if_indextoname(unsigned int ifindex, char *ifname)
{
    ENTER();
}

/****************************************************************************/
struct if_nameindex *if_nameindex(void)
{
    ENTER();
}

/****************************************************************************/
void if_freenameindex(struct if_nameindex *ptr)
{
    ENTER();
}
#endif /* CLIB2_NET_IF_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NETINET_ETHER_STUB) || defined(CLIB2_MULTUM_STUB)
#include <netinet/ether.h>
/****************************************************************************/
char *ether_ntoa(const struct ether_addr *addr)
{
    ENTER();
}

/****************************************************************************/
struct ether_addr *ether_aton(const char *asc)
{
    ENTER();
}

/****************************************************************************/
int ether_ntohost(char *hostname, const struct ether_addr *addr)
{
    ENTER();
}

/****************************************************************************/
int ether_hostton(const char *hostname, struct ether_addr *addr)
{
    ENTER();
}

/****************************************************************************/
int ether_line(const char *line, struct ether_addr *addr, char *hostname)
{
    ENTER();
}

/****************************************************************************/
char *ether_ntoa_r(const struct ether_addr *addr, char *buf)
{
    ENTER();
}

/****************************************************************************/
struct ether_addr *ether_aton_r(const char *asc, struct ether_addr *addr)
{
    ENTER();
}
#endif /* CLIB2_NETINET_ETHER_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_NL_TYPES_STUB) || defined(CLIB2_MULTUM_STUB)
#include <nl_types.h>
/****************************************************************************/
int catclose(nl_catd catalog)
{
    ENTER();
}

/****************************************************************************/
char *catgets(nl_catd catalog, int set_number, int message_number,
              const char *message)
{
    ENTER();
}

/****************************************************************************/
nl_catd catopen(const char *name, int flag)
{
    ENTER();
}
#endif /* CLIB2_NL_TYPES_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_POLL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <poll.h>
/****************************************************************************/
int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    ENTER();
}
#endif /* CLIB2_POLL_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_PTHREAD_STUB) || defined(CLIB2_MULTUM_STUB)
#include <pthread.h>
/****************************************************************************/
int pthread_attr_init(pthread_attr_t *attr)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_destroy(pthread_attr_t *attr)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getdetachstate(const pthread_attr_t *attr,
                                int *detachstate)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getguardsize(const pthread_attr_t *attr, size_t *guardsize)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getinheritsched(const pthread_attr_t *attr,
                                 int *inheritsched)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setschedparam(pthread_attr_t *attr,
                               const struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getschedparam(const pthread_attr_t *attr,
                               struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getschedpolicy(const pthread_attr_t *attr, int *policy)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setscope(pthread_attr_t *attr, int scope)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getscope(const pthread_attr_t *attr, int *scope)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr,
                          size_t stacksize)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getstack(const pthread_attr_t *attr,
                          void **stackaddr, size_t *stacksize)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setstackaddr(pthread_attr_t *attr, void *stackaddr)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getstackaddr(const pthread_attr_t *attr, void **stackaddr)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize)
{
    ENTER();
}

/****************************************************************************/
int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize)
{
    ENTER();
}

/****************************************************************************/
int pthread_cancel(pthread_t thread)
{
    ENTER();
}

/****************************************************************************/
int pthread_detach(pthread_t thread)
{
    ENTER();
}

/****************************************************************************/
int pthread_equal(pthread_t t1, pthread_t t2)
{
    ENTER();
}

/****************************************************************************/
void pthread_exit(void *retval)
{
    ENTER();
}

/****************************************************************************/
int pthread_join(pthread_t thread, void **retval)
{
    ENTER();
}

/****************************************************************************/
pthread_t pthread_self(void)
{
    ENTER();
}

/****************************************************************************/
int pthread_setschedparam(pthread_t thread, int policy,
                          const struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int pthread_getschedparam(pthread_t thread, int *policy,
                          struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int pthread_setschedprio(pthread_t thread, int prio)
{
    ENTER();
}

/****************************************************************************/
int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset)
{
    ENTER();
}
#endif /* CLIB2_PTHREAD_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_PTY_STUB) || defined(CLIB2_MULTUM_STUB)
#include <pty.h>
/****************************************************************************/
int openpty(int *amaster, int *aslave, char *name,
            const struct termios *termp, const struct winsize *winp)
{
    ENTER();
}

/****************************************************************************/
pid_t forkpty(int *amaster, char *name, const struct termios *termp,
              const struct winsize *winp)
{
    ENTER();
}
#endif /* CLIB2_PTY_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_PWD_STUB) || defined(CLIB2_MULTUM_STUB)
#include <pwd.h>
/****************************************************************************/
int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen,
               struct passwd **result)
{
    ENTER();
}

/****************************************************************************/
int getpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen,
               struct passwd **result)
{
    ENTER();
}
#endif /* CLIB2_PWD_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_REGEX_STUB) || defined(CLIB2_MULTUM_STUB)
#include <regex.h>
/****************************************************************************/
int regcomp(regex_t *preg, const char *regex, int cflags)
{
    ENTER();
}

/****************************************************************************/
int regexec(const regex_t *preg, const char *string, size_t nmatch,
            regmatch_t pmatch[], int eflags)
{
    ENTER();
}

/****************************************************************************/
size_t regerror(int errcode, const regex_t *preg, char *errbuf,
                size_t errbuf_size)
{
    ENTER();
}

/****************************************************************************/
void regfree(regex_t *preg)
{
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
    ENTER();
}

/****************************************************************************/
int dn_expand(const unsigned char *msg, const unsigned char *eomorig,
              const unsigned char *comp_dn, char *exp_dn, int length)
{
    ENTER();
}

/****************************************************************************/
void res_nclose(res_state statep)
{
    ENTER();
}

/****************************************************************************/
int res_ninit(res_state statep)
{
    ENTER();
}

/****************************************************************************/
int res_nmkquery(res_state statep, int op, const char *dname, int class,
                 int type, const unsigned char *data, int datalen,
                 const unsigned char *newrr, unsigned char *buf, int buflen)
{
    ENTER();
}

/****************************************************************************/
int res_nquery(res_state statep, const char *dname, int class, int type,
               unsigned char *answer, int anslen)
{
    ENTER();
}

/****************************************************************************/
int res_nquerydomain(res_state statep, const char *name, const char *domain,
                     int class, int type, unsigned char *answer, int anslen)
{
    ENTER();
}

/****************************************************************************/
int res_nsearch(res_state statep, const char *dname, int class, int type,
                unsigned char *answer, int anslen)
{
    ENTER();
}

/****************************************************************************/
int res_nsend(res_state statep, const unsigned char *msg, int msglen,
              unsigned char *answer, int anslen)
{
    ENTER();
}
#endif /* CLIB2_RESOLV_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SCHED_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sched.h>
/****************************************************************************/
int sched_getcpu(void)
{
    ENTER();
}

/****************************************************************************/
int sched_get_priority_max(int policy)
{
    ENTER();
}

/****************************************************************************/
int sched_get_priority_min(int policy)
{
    ENTER();
}

/****************************************************************************/
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask)
{
    ENTER();
}

/****************************************************************************/
int sched_getparam(pid_t pid, struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int sched_getscheduler(pid_t pid)
{
    ENTER();
}

/****************************************************************************/
int sched_rr_get_interval(pid_t pid, struct timespec *tp)
{
    ENTER();
}

/****************************************************************************/
int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask)
{
    ENTER();
}

/****************************************************************************/
int sched_setparam(pid_t pid, const struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param)
{
    ENTER();
}

/****************************************************************************/
int sched_yield(void)
{
    ENTER();
}
#endif /* CLIB2_SCHED_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SEMAPHORE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <semaphore.h>
/****************************************************************************/
int sem_close(sem_t *sem)
{
    ENTER();
}

/****************************************************************************/
int sem_destroy(sem_t *sem)
{
    ENTER();
}

/****************************************************************************/
int sem_getvalue(sem_t *sem, int *sval)
{
    ENTER();
}

/****************************************************************************/
int sem_init(sem_t *sem, int pshared, unsigned int value)
{
    ENTER();
}

/****************************************************************************/
sem_t * sem_open(const char *name, int oflag, ...)
{
    ENTER();
}

/****************************************************************************/
int sem_post(sem_t *sem)
{
    ENTER();
}

/****************************************************************************/
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout)
{
    ENTER();
}

/****************************************************************************/
int sem_trywait(sem_t *sem)
{
    ENTER();
}

/****************************************************************************/
int sem_unlink(const char *name)
{
    ENTER();
}

/****************************************************************************/
int sem_wait(sem_t *sem)
{
    ENTER();
}
#endif /* CLIB2_SEMAPHORE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SIGNAL_STUB) || defined(CLIB2_MULTUM_STUB)
#include <signal.h>
/****************************************************************************/
int sigemptyset(sigset_t *set)
{
    ENTER();
}

/****************************************************************************/
int sigfillset(sigset_t *set)
{
    ENTER();
}

/****************************************************************************/
int sigdelset(sigset_t *set, int signo)
{
    ENTER();
}

/****************************************************************************/
int sigismember(const sigset_t *set, int signo)
{
    ENTER();
}

/****************************************************************************/
int sigsuspend(const sigset_t *sigmask)
{
    ENTER();
}

/****************************************************************************/
int sigaction(int sig, const struct sigaction *restrict act,
              struct sigaction *restrict oact)
{
    ENTER();
}

/****************************************************************************/
int sigpending(sigset_t *set)
{
    ENTER();
}

/****************************************************************************/
int sigwait(const sigset_t *set, int *sig)
{
    ENTER();
}

/****************************************************************************/
int sigwaitinfo(const sigset_t *set, siginfo_t *info)
{
    ENTER();
}

/****************************************************************************/
int sigtimedwait(const sigset_t *set, siginfo_t *info,
                 const struct timespec *timeout)
{
    ENTER();
}

/****************************************************************************/
int sigqueue(pid_t pid, int sig, const union sigval value)
{
    ENTER();
}

/****************************************************************************/
int sigaltstack(const stack_t *ss, stack_t *old_ss)
{
    ENTER();
}

/****************************************************************************/
int sighold(int sig)
{
    ENTER();
}

/****************************************************************************/
int sigignore(int sig)
{
    ENTER();
}

/****************************************************************************/
int siginterrupt(int sig, int flag)
{
    ENTER();
}

/****************************************************************************/
int sigpause(int sig)
{
    ENTER();
}

/****************************************************************************/
int sigrelse(int sig)
{
    ENTER();
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
    ENTER();
}

/****************************************************************************/
int posix_spawn_file_actions_addclose(
                posix_spawn_file_actions_t *file_actions, int fildes)
{
    ENTER();
}

/****************************************************************************/
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *file_actions,
                                     int fildes, int newfildes)
{
    ENTER();
}

/****************************************************************************/
int posix_spawn_file_actions_addopen(
                posix_spawn_file_actions_t *restrict file_actions,
                int fildes, const char *restrict path, int oflag, mode_t mode)
{
    ENTER();
}

/****************************************************************************/
int posix_spawn_file_actions_destroy(
                posix_spawn_file_actions_t *file_actions)
{
    ENTER();
}

/****************************************************************************/
int posix_spawn_file_actions_init(posix_spawn_file_actions_t *file_actions)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_destroy(posix_spawnattr_t *attr)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_getflags(const posix_spawnattr_t *restrict attr,
                             short *restrict flags)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_getpgroup(const posix_spawnattr_t *restrict attr,
                              pid_t *restrict pgroup)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_getschedparam(const posix_spawnattr_t *restrict attr,
                                  struct sched_param *restrict schedparam)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_getschedpolicy(const posix_spawnattr_t *restrict attr,
                                   int *restrict schedpolicy)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_getsigdefault(const posix_spawnattr_t *restrict attr,
                                  sigset_t *restrict sigdefault)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_getsigmask(const posix_spawnattr_t *restrict attr,
                               sigset_t *restrict sigmask)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_init(posix_spawnattr_t *attr)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_setflags(posix_spawnattr_t *attr, short flags)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_setpgroup(posix_spawnattr_t *attr, pid_t pgroup)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_setschedparam(posix_spawnattr_t *restrict attr,
                            const struct sched_param *restrict schedparam)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_setschedpolicy(posix_spawnattr_t *attr,
                                          int schedpolicy)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_setsigdefault(posix_spawnattr_t *restrict attr,
                                  const sigset_t *restrict sigdefault)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnattr_setsigmask(posix_spawnattr_t *restrict attr,
                               const sigset_t *restrict sigmask)
{
    ENTER();
}

/****************************************************************************/
int posix_spawnp(pid_t *pid, const char *file,
                 const posix_spawn_file_actions_t *file_actions,
                 const posix_spawnattr_t *attrp, char *const argv[],
                 char *const envp[])
{
    ENTER();
}
#endif /* CLIB2_SPAWN_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STDIO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <stdio.h>
/****************************************************************************/
FILE *fmemopen(void *buf, size_t size, const char *mode)
{
    ENTER();
}

/****************************************************************************/
FILE *open_memstream(char **ptr, size_t *sizeloc)
{
    ENTER();
}

/****************************************************************************/
FILE *open_wmemstream(wchar_t **ptr, size_t *sizeloc)
{
    ENTER();
}

/****************************************************************************/
int dprintf(int fildes, const char *restrict format, ...)
{
    ENTER();
}

/****************************************************************************/
int vdprintf(int fd, const char *format, va_list ap)
{
    ENTER();
}

/****************************************************************************/
ssize_t getdelim(char **restrict lineptr, size_t *restrict n, int delimiter,
                 FILE *restrict stream)
{
    ENTER();
}

/****************************************************************************/
ssize_t getline(char **restrict lineptr, size_t *restrict n,
                FILE *restrict stream)
{
    ENTER();
}

/****************************************************************************/
int renameat(int oldfd, const char *old, int newfd, const char *new)
{
    ENTER();
}
#endif /* CLIB2_STDIO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STDLIB_STUB) || defined(CLIB2_MULTUM_STUB)
#include <stdlib.h>
/****************************************************************************/
long int a64l(const char *str64)
{
    ENTER();
}

/****************************************************************************/
void *aligned_alloc(size_t alignment, size_t size)
{
    ENTER();
}

/****************************************************************************/
int at_quick_exit(void (*func)(void))
{
    ENTER();
}

/****************************************************************************/
int clearenv(void)
{
    ENTER();
}

/****************************************************************************/
double drand48(void)
{
    ENTER();
}

/****************************************************************************/
char *ecvt(double number, int ndigits, int *decpt, int *sign)
{
    ENTER();
}

/****************************************************************************/
double erand48(unsigned short xsubi[3])
{
    ENTER();
}

/****************************************************************************/
char *fcvt(double number, int ndigits, int *decpt, int *sign)
{
    ENTER();
}

/****************************************************************************/
char *gcvt(double number, int ndigit, char *buf)
{
    ENTER();
}

/****************************************************************************/
int getloadavg(double loadavg[], int nelem)
{
    ENTER();
}

/****************************************************************************/
int getsubopt(char **optionp, char * const *tokens, char **valuep)
{
    ENTER();
}

/****************************************************************************/
int grantpt(int fd)
{
    ENTER();
}

/****************************************************************************/
char *initstate(unsigned seed, char *state, size_t n)
{
    ENTER();
}

/****************************************************************************/
long int jrand48(unsigned short xsubi[3])
{
    ENTER();
}

/****************************************************************************/
char *l64a(long value)
{
    ENTER();
}

/****************************************************************************/
void lcong48(unsigned short param[7])
{
    ENTER();
}

/****************************************************************************/
long int lrand48 (void)
{
    ENTER();
}

/****************************************************************************/
size_t malloc_usable_size(void *ptr)
{
    ENTER();
}

/****************************************************************************/
void *memalign(size_t alignment, size_t size)
{
    ENTER();
}

/****************************************************************************/
int mkostemp(char *template, int flags)
{
    ENTER();
}

/****************************************************************************/
long int mrand48(void)
{
    ENTER();
}

/****************************************************************************/
int mkostemps(char *template, int suffixlen, int flags)
{
    ENTER();
}

/****************************************************************************/
int mkstemps(char *template, int suffixlen)
{
    ENTER();
}

/****************************************************************************/
long int nrand48(unsigned short xsubi[3])
{
    ENTER();
}

/****************************************************************************/
int posix_memalign(void **memptr, size_t alignment, size_t size)
{
    ENTER();
}

/****************************************************************************/
int posix_openpt(int flags)
{
    ENTER();
}

/****************************************************************************/
char *ptsname(int fd)
{
    ENTER();
}

/****************************************************************************/
int ptsname_r(int fd, char *buf, size_t buflen)
{
    ENTER();
}

/****************************************************************************/
long int random(void)
{
    ENTER();
}

/****************************************************************************/
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    ENTER();
}

/****************************************************************************/
char *realpath(const char *path, char *resolved_path)
{
    ENTER();
}

/****************************************************************************/
char *secure_getenv(const char *name)
{
    ENTER();
}

/****************************************************************************/
unsigned short *seed48(unsigned short seed16v[3])
{
    ENTER();
}

/****************************************************************************/
void setkey(const char *key)
{
    ENTER();
}

/****************************************************************************/
char *setstate(char *state)
{
    ENTER();
}

/****************************************************************************/
void srand48(long int seedval)
{
    ENTER();
}

/****************************************************************************/
void srandom(unsigned int seed)
{
    ENTER();
}

/****************************************************************************/
float strtof_l(const char *nptr, char **endptr, locale_t loc)
{
    ENTER();
}

/****************************************************************************/
double strtod_l(const char *nptr, char **endptr, locale_t loc)
{
    ENTER();
}

/****************************************************************************/
long double strtold(const char *nptr, char **endptr)
{
    ENTER();
}

/****************************************************************************/
long double strtold_l(const char *nptr, char **endptr, locale_t loc)
{
    ENTER();
}

/****************************************************************************/
int unlockpt(int fd)
{
    ENTER();
}

/****************************************************************************/
void *valloc(size_t size)
{
    ENTER();
}
#endif /* CLIB2_STDLIB_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STRING_STUB) || defined(CLIB2_MULTUM_STUB)
#include <string.h>
/****************************************************************************/
void explicit_bzero(void *s, size_t n)
{
    ENTER();
}

/****************************************************************************/
void *memrchr(const void *s, int c, size_t n)
{
    ENTER();
}

/****************************************************************************/
void *memccpy(void *dest, const void *src, int c, size_t n)
{
    ENTER();
}

/****************************************************************************/
void *memmem(const void *haystack, size_t haystacklen, const void *needle,
             size_t needlelen)
{
    ENTER();
}

/****************************************************************************/
void *mempcpy(void *dest, const void *src, size_t n)
{
    ENTER();
}

/****************************************************************************/
char *stpcpy(char *dest, const char *src)
{
    ENTER();
}

/****************************************************************************/
char *stpncpy(char *dest, const char *src, size_t n)
{
    ENTER();
}

/****************************************************************************/
char *strcasestr(const char *haystack, const char *needle)
{
    ENTER();
}

/****************************************************************************/
char *strchrnul(const char *s, int c)
{
    ENTER();
}

/****************************************************************************/
int strcoll_l(const char *s1, const char *s2, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
char *strerror_l(int errnum, locale_t locale)
{
    ENTER();
}

/****************************************************************************/
char *strndup(const char *s, size_t size)
{
    ENTER();
}

/****************************************************************************/
char *strsep(char **stringp, const char *delim)
{
    ENTER();
}

/****************************************************************************/
char *strsignal(int sig)
{
    ENTER();
}

/****************************************************************************/
int strverscmp(const char *s1, const char *s2)
{
    ENTER();
}

/****************************************************************************/
size_t strxfrm_l(char *restrict s1, const char *restrict s2, size_t n,
                 locale_t locale)
{
    ENTER();
}
#endif /* CLIB2_STRING_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_STROPTS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <stropts.h>
/****************************************************************************/
int isastream(int fildes)
{
    ENTER();
}

/****************************************************************************/
int ioctl(int fd, unsigned long request, ...)
{
    ENTER();
}
#endif /* CLIB2_STROPTS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_ACCT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/acct.h>
/****************************************************************************/
int acct(const char *filename)
{
    ENTER();
}
#endif /* CLIB2_SYS_ACCT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_FILE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/file.h>
/****************************************************************************/
int flock(int fd, int operation)
{
    ENTER();
}
#endif /* CLIB2_SYS_FILE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_IPC_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/ipc.h>
/****************************************************************************/
key_t ftok(char *pathname, char proj_id)
{
    ENTER();
}
#endif /* CLIB2_SYS_IPC_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_MMAN_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/mman.h>
/****************************************************************************/
int madvise(void *addr, size_t length, int advice)
{
    ENTER();
}

/****************************************************************************/
int mincore(void *addr, size_t length, unsigned char *vec)
{
    ENTER();
}

/****************************************************************************/
int mlock(const void *addr, size_t len)
{
    ENTER();
}

/****************************************************************************/
int mlockall(int flags)
{
    ENTER();
}

/****************************************************************************/
void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset)
{
    ENTER();
}

/****************************************************************************/
int munmap(void *addr, size_t length)
{
    ENTER();
}

/****************************************************************************/
int mprotect(void *addr, size_t len, int prot)
{
    ENTER();
}

/****************************************************************************/
void *mremap(void *old_address, size_t old_size, size_t new_size,
             int flags, ...)
{
    ENTER();
}

/****************************************************************************/
int msync(void *addr, size_t length, int flags)
{
    ENTER();
}

/****************************************************************************/
int munlock(const void *addr, size_t len)
{
    ENTER();
}

/****************************************************************************/
int munlockall(void)
{
    ENTER();
}

/****************************************************************************/
int posix_madvise(void *addr, size_t len, int advice)
{
    ENTER();
}

/****************************************************************************/
int remap_file_pages(void *addr, size_t size, int prot, size_t pgoff,
                     int flags)
{
    ENTER();
}

/****************************************************************************/
int shm_open(const char *name, int oflag, mode_t mode)
{
    ENTER();
}

/****************************************************************************/
int shm_unlink(const char *name)
{
    ENTER();
}
#endif /* CLIB2_SYS_MMAN_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_MSG_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/msg.h>
/****************************************************************************/
int msgctl(int msqid, int cmd, struct msqid_ds *buf)
{
    ENTER();
}

/****************************************************************************/
int msgget(key_t key, int msgflg)
{
    ENTER();
}

/****************************************************************************/
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
               int msgflg)
{
    ENTER();
}

/****************************************************************************/
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
    ENTER();
}
#endif /* CLIB2_SYS_MSG_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/ptrace.h>
/****************************************************************************/
long int ptrace(enum __ptrace_request request, pid_t pid, void *addr,
                void *data)
{
    ENTER();
}
#endif /* CLIB2_SYS_PTRACE_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_RESOURCE_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/resource.h>
/****************************************************************************/
int getrusage(int who, struct rusage *usage)
{
    ENTER();
}

/****************************************************************************/
int getpriority(int which, id_t who)
{
    ENTER();
}

/****************************************************************************/
int setpriority(int which, id_t who, int prio)
{
    ENTER();
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
    ENTER();
}
#endif /* CLIB2_SYS_SELECT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SEM_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/sem.h>
/****************************************************************************/
int semctl(int semid, int semnum, int cmd, ...)
{
    ENTER();
}

/****************************************************************************/
int semget(key_t key, int nsems, int semflg)
{
    ENTER();
}

/****************************************************************************/
int semop(int semid, struct sembuf *sops, size_t nsops)
{
    ENTER();
}

/****************************************************************************/
int semtimedop(int semid, struct sembuf *sops, size_t nsops,
               const struct timespec *timeout)
{
    ENTER();
}
#endif /* CLIB2_SYS_SEM_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SHM_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/shm.h>
/****************************************************************************/
void *shmat(int shmid, const void *shmaddr, int shmflg)
{
    ENTER();
}

/****************************************************************************/
int shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
    ENTER();
}

/****************************************************************************/
int shmdt(const void *shmaddr)
{
    ENTER();
}

/****************************************************************************/
int shmget(key_t key, size_t size, int shmflg)
{
    ENTER();
}
#endif /* CLIB2_SYS_SHM_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_SOCKET_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/socket.h>
/****************************************************************************/
int socketpair(int domain, int type, int protocol, int sv[2])
{
    ENTER();
}

/****************************************************************************/
int sockatmark(int sockfd)
{
    ENTER();
}
#endif /* CLIB2_SYS_SOCKET_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_STAT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/stat.h>
/****************************************************************************/
int fchmodat(int fd, const char *path, mode_t mode, int flag)
{
    ENTER();
}

/****************************************************************************/
int fstatat(int fd, const char *restrict path, struct stat *restrict buf,
            int flag)
{
    ENTER();
}

/****************************************************************************/
int mkdirat(int fd, const char *path, mode_t mode)
{
    ENTER();
}

/****************************************************************************/
int mkfifo(const char *pathname, mode_t mode)
{
    ENTER();
}

/****************************************************************************/
int mkfifoat(int dirfd, const char *pathname, mode_t mode)
{
    ENTER();
}

/****************************************************************************/
int mknod(const char *pathname, mode_t mode, dev_t dev)
{
    ENTER();
}

/****************************************************************************/
int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev)
{
    ENTER();
}

/****************************************************************************/
int futimens(int fd, const struct timespec times[2])
{
    ENTER();
}

/****************************************************************************/
int utimensat(int fd, const char *path, const struct timespec times[2],
              int flag)
{
    ENTER();
}
#endif /* CLIB2_SYS_STAT_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/statvfs.h>
/****************************************************************************/
int fstatvfs(int fd, struct statvfs *buf)
{
    ENTER();
}

/****************************************************************************/
int statvfs(const char *restrict path, struct statvfs *restric buf)
{
    ENTER();
}
#endif /* CLIB2_SYS_STATVFS_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_TIME_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/time.h>
/****************************************************************************/
int futimes(int fd, const struct timeval tv[2])
{
    ENTER();
}

/****************************************************************************/
int futimesat(int dirfd, const char *pathname, const struct timeval times[2])
{
    ENTER();
}

/****************************************************************************/
int futimens(int fd, const struct timespec times[2])
{
    ENTER();
}

/****************************************************************************/
int getitimer(int which, struct itimerval *curr_value)
{
    ENTER();
}

/****************************************************************************/
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    ENTER();
}

/****************************************************************************/
int lutimes(const char *filename, const struct timeval tv[2])
{
    ENTER();
}

/****************************************************************************/
int setitimer(int which, const struct itimerval *new_value,
              struct itimerval *old_value)
{
    ENTER();
}

/****************************************************************************/
int settimeofday(const struct timeval *tv, const struct timezone *tz)
{
    ENTER();
}

/****************************************************************************/
int utimes(const char *path, const struct timeval times[2])
{
    ENTER();
}

/****************************************************************************/
int utimensat(int fd, const char *path, const struct timespec times[2],
              int flag)
{
    ENTER();
}
#endif /* CLIB2_SYS_TIME_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_UIO_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/uio.h>
/****************************************************************************/
ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset)
{
    ENTER();
}

/****************************************************************************/
ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset)
{
    ENTER();
}
#endif /* CLIB2_SYS_UIO_STUB) || defined(CLIB2_MULTUM_STUB) */

/****************************************************************************/
#if defined(CLIB2_SYS_WAIT_STUB) || defined(CLIB2_MULTUM_STUB)
#include <sys/wait.h>
/****************************************************************************/
pid_t wait(int *stat_loc)
{
    ENTER();
}

/****************************************************************************/
pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
    ENTER();
}

/****************************************************************************/
int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
    ENTER();
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
