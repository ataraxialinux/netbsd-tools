AC_PREREQ(2.59)
AC_INIT([netbsd-tools], [9.0], [ataraxialinux@protonmail.com])
AM_INIT_AUTOMAKE
AM_SANITY_CHECK
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_MAKE_SET
AC_GNU_SOURCE
AC_STDC_HEADERS
AC_PROG_CC()
AC_PROG_RANLIB()

AC_CONFIG_FILES([Makefile
		src/Makefile
		src/libnetbsd/Makefile
		src/sed/Makefile
		src/find/Makefile
		src/xargs/Makefile])
AC_OUTPUT
