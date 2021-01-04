/*
 * $Id: errno.h,v 1.5 2006-01-08 12:06:14 obarthel Exp $
 *
 * :ts=4
 *
 * Portable ISO 'C' (1994) runtime library for the Amiga computer
 * Copyright (c) 2002-2015 by Olaf Barthel <obarthel (at) gmx.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   - Neither the name of Olaf Barthel nor the names of contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************
 *
 * Documentation and source code for this library, and the most recent library
 * build are available from <http://sourceforge.net/projects/clib2>.
 *
 *****************************************************************************
 */

#ifndef _ERRNO_H
#define _ERRNO_H

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

extern int errno;

/****************************************************************************/

#define EPERM			1		/* Operation not permitted */
#define ENOENT			2		/* No such file or directory */
#define ESRCH			3		/* No such process */
#define EINTR			4		/* Interrupted system call */
#define EIO				5		/* Input/output error */
#define ENXIO			6		/* Device not configured */
#define E2BIG			7		/* Argument list too long */
#define ENOEXEC			8		/* Exec format error */
#define EBADF			9		/* Bad file descriptor */
#define ECHILD			10		/* No child processes */
#define EDEADLK			11		/* Resource deadlock avoided */

#define ENOMEM			12		/* Cannot allocate memory */
#define EACCES			13		/* Permission denied */
#define EFAULT			14		/* Bad address */

#define ENOTBLK			15		/* Block device required */
#define EBUSY			16		/* Device busy */

#define EEXIST			17		/* File exists */
#define EXDEV			18		/* Cross-device link */
#define ENODEV			19		/* Operation not supported by device */
#define ENOTDIR			20		/* Not a directory */
#define EISDIR			21		/* Is a directory */
#define EINVAL			22		/* Invalid argument */
#define ENFILE			23		/* Too many open files in system */
#define EMFILE			24		/* Too many open files */
#define ENOTTY			25		/* Inappropriate ioctl for device */

#define ETXTBSY			26		/* Text file busy */

#define EFBIG			27		/* File too large */
#define ENOSPC			28		/* No space left on device */
#define ESPIPE			29		/* Illegal seek */
#define EROFS			30		/* Read-only file system */
#define EMLINK			31		/* Too many links */
#define EPIPE			32		/* Broken pipe */

#define EDOM			33		/* Numerical argument out of domain */
#define ERANGE			34		/* Result too large */

/* non-blocking and interrupt i/o */
#define EAGAIN			35		/* Resource temporarily unavailable */
#define EWOULDBLOCK		EAGAIN	/* Operation would block */
#define EINPROGRESS		36		/* Operation now in progress */
#define EALREADY		37		/* Operation already in progress */

/* ipc/network software -- argument errors */
#define ENOTSOCK		38		/* Socket operation on non-socket */
#define EDESTADDRREQ	39		/* Destination address required */
#define EMSGSIZE		40		/* Message too long */
#define EPROTOTYPE		41		/* Protocol wrong type for socket */
#define ENOPROTOOPT		42		/* Protocol not available */
#define EPROTONOSUPPORT	43		/* Protocol not supported */
#define ESOCKTNOSUPPORT	44		/* Socket type not supported */
#define EOPNOTSUPP		45		/* Operation not supported on socket */
#define EPFNOSUPPORT	46		/* Protocol family not supported */
#define EAFNOSUPPORT	47		/* Address family not supported by protocol family */
#define EADDRINUSE		48		/* Address already in use */
#define EADDRNOTAVAIL	49		/* Can't assign requested address */

/* ipc/network software -- operational errors */
#define ENETDOWN		50		/* Network is down */
#define ENETUNREACH		51		/* Network is unreachable */
#define ENETRESET		52		/* Network dropped connection on reset */
#define ECONNABORTED	53		/* Software caused connection abort */
#define ECONNRESET		54		/* Connection reset by peer */
#define ENOBUFS			55		/* No buffer space available */
#define EISCONN			56		/* Socket is already connected */
#define ENOTCONN		57		/* Socket is not connected */
#define ESHUTDOWN		58		/* Can't send after socket shutdown */
#define ETOOMANYREFS	59		/* Too many references: can't splice */
#define ETIMEDOUT		60		/* Connection timed out */
#define ECONNREFUSED	61		/* Connection refused */

#define ELOOP			62		/* Too many levels of symbolic links */
#define ENAMETOOLONG	63		/* File name too long */

#define EHOSTDOWN		64		/* Host is down */
#define EHOSTUNREACH	65		/* No route to host */
#define ENOTEMPTY		66		/* Directory not empty */

/* quotas & mush */
#define EPROCLIM		67		/* Too many processes */
#define EUSERS			68		/* Too many users */
#define EDQUOT			69		/* Disc quota exceeded */

/* Network File System */
#define ESTALE			70		/* Stale NFS file handle */
#define EREMOTE			71		/* Too many levels of remote in path */
#define EBADRPC			72		/* RPC struct is bad */
#define ERPCMISMATCH	73		/* RPC version wrong */
#define EPROGUNAVAIL	74		/* RPC prog. not avail */
#define EPROGMISMATCH	75		/* Program version wrong */
#define EPROCUNAVAIL	76		/* Bad procedure for program */

#define ENOLCK			77		/* No locks available */
#define ENOSYS			78		/* Function not implemented */

#define EFTYPE			79		/* Inappropriate file type or format */

#define EAUTH			80		/* Authentication error. */

#define ENEEDAUTH		81		/* Need authenticator. */

#define EIDRM			82		/* Identifier removed. */

#define ENOMSG			83		/* No message of the desired type. */

#define EOVERFLOW		84		/* Value too large to be stored in data type. */

#define EILSEQ			85		/* Encoding error detected. */

/* Additional error codes from the GNU C library */
#define ENOTSUP         86		/* Not supported. */
#define EBACKGROUND     87		/* Inappropriate operation for background process. */
#define EDIED           88		/* Translator died. */
#define ED              89		/* The experienced user will know what's wrong. */
#define EGREGIOUS       90		/* You really blew it this time. */
#define EIEIO           91		/* Computer bought the farm. */
#define EGRATUITOUS     92		/* Gratuitous error. */
#define EBADMSG         93		/* Bad message. */
#define EMULTIHOP       94		/* Multihop attempted. */
#define ENODATA         95		/* No data available. */
#define ENOLINK         96		/* Link has been severed. */
#define ENOSR           97		/* Out of streams resources. */
#define ENOSTR          98		/* Device not a stream. */
#define EPROTO          99		/* Protocol error. */
#define ETIME           100		/* Timer expired. */
#define ECANCELED       101		/* Operation canceled. */
#define EOWNERDEAD      102		/* Owner died. */
#define ENOTRECOVERABLE 103		/* State not recoverable. */
#define ERESTART        104		/* Interupted system call could not be restarted. */
#define ECHRNG          105		/* Channel number out of range. */
#define EL2NSYNC        106		/* Level 2 not synchronized. */
#define EL3HLT          107		/* Level 3 halted. */
#define EL3RST          108		/* Level 3 reset. */
#define ELNRNG          109		/* Link number out of range. */
#define EUNATCH         110		/* Protocol driver not attached. */
#define ENOCSI          111		/* No CSI structure available. */
#define EL2HLT          112		/* Level 2 halted. */
#define EBADE           113		/* Invalid exchange. */
#define EBADR           114		/* Invalid request descriptor. */
#define EXFULL          115		/* Exchange full. */
#define ENOANO          116		/* No anode. */
#define EBADRQC         117		/* Invalid request code. */
#define EBADSLT         118		/* Invalid slot. */
#define EDEADLOCK       119		/* File locking deadlock error. */
#define EBFONT          120		/* Bad font file format. */
#define ENONET          121		/* Machine is not on the network. */
#define ENOPKG          122		/* Package not installed. */
#define EADV            123		/* Advertise error. */
#define ESRMNT          124		/* Srmount error. */
#define ECOMM           125		/* Communication error on send. */
#define EDOTDOT         126		/* RFS specific error. */
#define ENOTUNIQ        127		/* Name not unique on network. */
#define EBADFD          128		/* File descriptor in bad state. */
#define EREMCHG         129		/* Remote address changed. */
#define ELIBACC         130		/* Can not access a needed shared library. */
#define ELIBBAD         131		/* Accessing a corrupt shared library. */
#define ELIBSCN         132		/* .lib section in a.out corrupted. */
#define ELIBMAX         133		/* Attempting to link in too many shared libraries. */
#define ELIBEXEC        134		/* Cannot exec a shared library directly. */
#define ESTRPIPE        135		/* Streams pipe error. */
#define EUCLEAN         136		/* Structure needs cleaning. */
#define ENOTNAM         137		/* Not a XENIX named type file. */
#define ENAVAIL         138		/* No XENIX semaphores available. */
#define EISNAM          139		/* Is a named type file. */
#define EREMOTEIO       140		/* Remote I/O error. */
#define ENOMEDIUM       141		/* No medium found. */
#define EMEDIUMTYPE     142		/* Wrong medium type. */
#define ENOKEY          143		/* Required key not available. */
#define EKEYEXPIRED     144		/* Key has expired. */
#define EKEYREVOKED     145		/* Key has been revoked. */
#define EKEYREJECTED    146		/* Key was rejected by service. */
#define ERFKILL         147		/* Operation not possible due to RF-kill. */
#define EHWPOISON       148		/* Memory page has hardware error. */

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _ERRNO_H */
