// shit-ton of useless bsd functions

#include <sys/statvfs.h>

void setpassent(i)
int i;
{
}

void setgroupent(i)
int i;
{
}

int
netbsd_statvfs(const char *file, struct statvfs *st)
{
	return statvfs(file, st);
}

const char *const sys_signame[] = {
	"Signal 0",	/* 0 */
	"HUP",		/* 1 SIGHUP */
	"INT",		/* 2 SIGINT */
	"QUIT",		/* 3 SIGQUIT */
	"ILL",		/* 4 SIGILL */
	"TRAP",		/* 5 SIGTRAP */
	"ABRT",		/* 6 SIGABRT */
	"EMT",		/* 7 SIGEMT */
	"FPE",		/* 8 SIGFPE */
	"KILL",		/* 9 SIGKILL */
	"BUS",		/* 10 SIGBUS */
	"SEGV",		/* 11 SIGSEGV */
	"SYS",		/* 12 SIGSYS */
	"PIPE",		/* 13 SIGPIPE */
	"ALRM",		/* 14 SIGALRM */
	"TERM",		/* 15 SIGTERM */
	"URG",		/* 16 SIGURG */
	"STOP",		/* 17 SIGSTOP */
	"TSTP",		/* 18 SIGTSTP */
	"CONT",		/* 19 SIGCONT */
	"CHLD",		/* 20 SIGCHLD */
	"TTIN",		/* 21 SIGTTIN */
	"TTOU",		/* 22 SIGTTOU */
	"IO",		/* 23 SIGIO */
	"XCPU",		/* 24 SIGXCPU */
	"XFSZ",		/* 25 SIGXFSZ */
	"VTALRM",	/* 26 SIGVTALRM */
	"PROF",		/* 27 SIGPROF */
	"WINCH",	/* 28 SIGWINCH */
	"INFO",		/* 29 SIGINFO */
	"USR1",		/* 30 SIGUSR1 */
	"USR2",		/* 31 SIGUSR2 */
};
