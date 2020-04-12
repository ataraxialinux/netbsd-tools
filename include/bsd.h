#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <wchar.h>
#include <limits.h>

#define	__attribute__(x)
#define __dead		__attribute__((__noreturn__))
#define __pure		__attribute__((__const__))
#define	__constfunc	__attribute__((__const__))
#define	__unused	__attribute__((__unused__))
#define __UNCONST(a)	((void *)(unsigned long)(const void *)(a))
#define _DIAGASSERT assert
#define	__predict_true(exp)	__builtin_expect((exp) != 0, 1)
#define	__predict_false(exp)	__builtin_expect((exp) != 0, 0)
#define __nothing	(/*LINTED*/(void)0)

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

/*
 * Definitions of flags stored in file flags word.
 *
 * Super-user and owner changeable flags.
 */
#define	UF_SETTABLE	0x0000ffff	/* mask of owner changeable flags */
#define	UF_NODUMP	0x00000001	/* do not dump file */
#define	UF_IMMUTABLE	0x00000002	/* file may not be changed */
#define	UF_APPEND	0x00000004	/* writes to file may only append */
#define UF_OPAQUE	0x00000008	/* directory is opaque wrt. union */
/*	UF_NOUNLINK	0x00000010	   [NOT IMPLEMENTED] */
/*
 * Super-user changeable flags.
 */
#define	SF_SETTABLE	0xffff0000	/* mask of superuser changeable flags */
#define	SF_ARCHIVED	0x00010000	/* file is archived */
#define	SF_IMMUTABLE	0x00020000	/* file may not be changed */
#define	SF_APPEND	0x00040000	/* writes to file may only append */
/*	SF_NOUNLINK	0x00100000	   [NOT IMPLEMENTED] */
#define	SF_SNAPSHOT	0x00200000	/* snapshot inode */
#define	SF_LOG		0x00400000	/* WAPBL log file inode */
#define	SF_SNAPINVAL	0x00800000	/* snapshot is invalid */

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
#define REG_BASIC 0000

#define timespeccmp(tsp, usp, cmp)					\
        (((tsp)->tv_sec == (usp)->tv_sec) ?			\
        ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
        ((tsp)->tv_sec cmp (usp)->tv_sec))

#define __arraycount(a) (sizeof(a) / sizeof(*(a)))

#if !defined(_DIRENT_HAVE_NAMLEN)
#define D_NAMLEN(x) \
	strnlen((x)->d_name, (x)->d_reclen)
#else
#define D_NAMLEN(x) \
	(x)->d_namlen
#endif

#define	_VFS_NAMELEN	32
#define	_VFS_MNAMELEN	1024

#define	_PATH_DEFTAPE "/dev/st0"

typedef va_list __va_list;

extern const char *const *sys_signame;

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
int		 gid_from_group(const char *, gid_t *);
const char	*group_from_gid(gid_t, int);
int		 uid_from_user(const char *, uid_t *);
const char	*user_from_uid(uid_t, int);
char	*fgetln(FILE * __restrict, size_t * __restrict);
int	reallocarr(void *, size_t, size_t);
int		 setpassent(int);
int		 setgroupent(int);
int		raise_default_signal(int);

#ifndef __GLIBC__
quad_t	 strtoq(const char * __restrict, char ** __restrict, int);
#endif

__dead void	errc(int, int, const char *, ...)
		     __printflike(3, 4) __dead;
__dead void	verrc(int, int, const char *, va_list)
		    __printflike(3, 0) __dead;
intmax_t	strtoimax(const char * __restrict,
		    char ** __restrict, int);
intmax_t	strtoimax_l(const char * __restrict,
		    char ** __restrict, int, locale_t);
intmax_t	strtoi(const char * __restrict, char ** __restrict, int,
	               intmax_t, intmax_t, int *);
uintmax_t	strtou(const char * __restrict, char ** __restrict, int,
	               uintmax_t, uintmax_t, int *);
int	 vasprintf(char ** __restrict, const char * __restrict,
    __va_list)
		__printflike(2, 0);
