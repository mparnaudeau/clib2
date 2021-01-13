#if defined(CLIB2_LIBINTL_STUB) || defined(CLIB2_MULTUM_STUB)

#ifndef _LIBINTL_H
#define _LIBINTL_H

/* GNU. */

#warning "STUB: libintl.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern char *bindtextdomain(const char * domainname, const char * dirname);
extern char *bind_textdomain_codeset(const char * domainname,
                                     const char * codeset);
extern char *dgettext(const char * domainname, const char * msgid);
extern char *dcgettext(const char * domainname, const char * msgid,
                       int category);
extern char *ngettext(const char * msgid, const char * msgid_plural,
                      unsigned long int n);
extern char *dngettext(const char * domainname, const char * msgid,
                       const char * msgid_plural, unsigned long int n);
extern char *dcngettext(const char * domainname, const char * msgid,
                        const char * msgid_plural, unsigned long int n,
                        int category);
extern char *gettext(const char * msgid);
extern char *textdomain(const char * domainname);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LIBINTL_H */

#endif /* defined(CLIB2_LIBINTL_STUB) || defined(CLIB2_MULTUM_STUB) */
