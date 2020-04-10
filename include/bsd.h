#include <sys/types.h>
#include <sys/statfs.h>
#include <sys/statvfs.h>
#include <sys/sysmacros.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

#define	__attribute__(x)
#define __dead		__attribute__((__noreturn__))
#define __pure		__attribute__((__const__))
#define	__constfunc	__attribute__((__const__))
#define	__unused	__attribute__((__unused__))
#define __UNCONST(a)	((void *)(unsigned long)(const void *)(a))

#ifndef __GLIBC__
#if defined(__cplusplus)
#define	__BEGIN_EXTERN_C	extern "C" {
#define	__END_EXTERN_C		}
#else
#define	__BEGIN_EXTERN_C
#define	__END_EXTERN_C
#endif

#define	__BEGIN_DECLS	__BEGIN_EXTERN_C
#define	__END_DECLS	__END_EXTERN_C
#endif

#if !defined(DEF_WEAK)
#define DEF_WEAK(x)
#endif

#define __printflike(fmtarg, firstvararg)	/* nothing */
#define __scanflike(fmtarg, firstvararg)	/* nothing */
#define __sysloglike(fmtarg, firstvararg)	/* nothing */
#define __format_arg(fmtarg)			/* nothing */

#define	S_ISTXT	S_ISVTX /* sticky bit */

#ifndef st_atimespec
#define	st_atimespec		st_atim
#endif

#ifndef st_atimensec
#define	st_atimensec		st_atim.tv_nsec
#endif

#ifndef st_mtimespec
#define	st_mtimespec		st_mtim
#endif

#ifndef st_mtimensec
#define	st_mtimensec		st_mtim.tv_nsec
#endif

#ifndef st_ctimespec
#define	st_ctimespec		st_ctim
#endif

#ifndef st_ctimensec
#define	st_ctimensec		st_ctim.tv_nsec
#endif

#define SIGINFO 29
#ifndef ALLPERMS
#define	ALLPERMS	(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
#endif
#define	DEFFILEMODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#define	MNT_RDONLY	0x00000001
#define	MNT_LOCAL	0x00001000
#ifndef FNM_CASEFOLD
#define	FNM_CASEFOLD	0x08
#endif
#ifndef ARG_MAX
#define	ARG_MAX		 (256 * 1024)	/* max bytes for an exec function */
#endif
#define	SF_IMMUTABLE	0x00020000	/* file may not be changed */
#define	SF_APPEND	0x00040000	/* writes to file may only append */

#define timespeccmp(tsp, usp, cmp)					\
        (((tsp)->tv_sec == (usp)->tv_sec) ?			\
        ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
        ((tsp)->tv_sec cmp (usp)->tv_sec))

#define	_VFS_NAMELEN	32
#define	_VFS_MNAMELEN	1024

struct netbsd_stat {
	uint32_t  st_flags;		/* user defined flags for file */
};

struct netbsd_statvfs {
	struct statvfs buf;
	unsigned long	f_flag;
	char	f_fstypename[_VFS_NAMELEN];
};

#define	statvfs		netbsd_statvfs

size_t	 strlcat(char *, const char *, size_t);
size_t	 strlcpy(char *, const char *, size_t);
const char *getprogname(void) __constfunc;
void	setprogname(const char *);
int	wcswidth(const wchar_t *, size_t);
int	wcwidth(wchar_t);
time_t		parsedate(const char *, const time_t *, const int *);
void 		*emalloc(size_t);
int		string_to_flags(char **, unsigned long *, unsigned long *);
void	*setmode(const char *);
mode_t	 getmode(const void *, mode_t);
void	 strmode(mode_t, char *);
int	statvfs(const char *__restrict, struct statvfs *__restrict);
const char	*group_from_gid(gid_t, int);
const char	*user_from_uid(uid_t, int);

#ifndef __GLIBC__
quad_t	 strtoq(const char * __restrict, char ** __restrict, int);
#endif

__dead void	errc(int, int, const char *, ...)
		     __printflike(3, 4) __dead;
__dead void	verrc(int, int, const char *, va_list)
		    __printflike(3, 0) __dead;
