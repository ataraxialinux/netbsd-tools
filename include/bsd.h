#include <sys/types.h>
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

#ifndef statvfs
#define	_VFS_NAMELEN	32
#define	_VFS_MNAMELEN	1024

struct statvfs {
	unsigned long	f_flag;		/* copy of mount exported flags */
	unsigned long	f_bsize;	/* file system block size */
	unsigned long	f_frsize;	/* fundamental file system block size */
	unsigned long	f_iosize;	/* optimal file system block size */

	/* The following are in units of f_frsize */
	fsblkcnt_t	f_blocks;	/* number of blocks in file system, */
	fsblkcnt_t	f_bfree;	/* free blocks avail in file system */
	fsblkcnt_t	f_bavail;	/* free blocks avail to non-root */
	fsblkcnt_t	f_bresvd;	/* blocks reserved for root */

	fsfilcnt_t	f_files;	/* total file nodes in file system */
	fsfilcnt_t	f_ffree;	/* free file nodes in file system */
	fsfilcnt_t	f_favail;	/* free file nodes avail to non-root */
	fsfilcnt_t	f_fresvd;	/* file nodes reserved for root */

	uint64_t  	f_syncreads;	/* count of sync reads since mount */
	uint64_t  	f_syncwrites;	/* count of sync writes since mount */

	uint64_t  	f_asyncreads;	/* count of async reads since mount */
	uint64_t  	f_asyncwrites;	/* count of async writes since mount */

	fsid_t		f_fsidx;	/* NetBSD compatible fsid */
	unsigned long	f_fsid;		/* Posix compatible fsid */
	unsigned long	f_namemax;	/* maximum filename length */
	uid_t		f_owner;	/* user that mounted the file system */

	uint64_t	f_spare[4];	/* spare space */

	char	f_fstypename[_VFS_NAMELEN];	/* fs type name */
	char	f_mntonname[_VFS_MNAMELEN];	/* directory on which mounted */
	char	f_mntfromname[_VFS_MNAMELEN];	/* mounted file system */
	char	f_mntfromlabel[_VFS_MNAMELEN];  /* disk label name if avail */

};
#endif

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
#define	FNM_CASEFOLD	0x08
#define	ARG_MAX		 (256 * 1024)	/* max bytes for an exec function */
#define	SF_IMMUTABLE	0x00020000	/* file may not be changed */
#define	SF_APPEND	0x00040000	/* writes to file may only append */

#define timespeccmp(tsp, usp, cmp)					\
        (((tsp)->tv_sec == (usp)->tv_sec) ?			\
        ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
        ((tsp)->tv_sec cmp (usp)->tv_sec))

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

__dead void	errc(int, int, const char *, ...)
		     __printflike(3, 4) __dead;
__dead void	verrc(int, int, const char *, va_list)
		    __printflike(3, 0) __dead;
