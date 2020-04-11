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
