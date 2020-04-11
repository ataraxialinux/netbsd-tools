AM_CPPFLAGS = -I$(top_srcdir)/include -Ilib
AM_YFLAGS = -d
BUILT_SOURCES = parser.h parser.c
SUBDIRS = lib

bin_PROGRAMS = m4
m4_SOURCES = parser.y tokenizer.l eval.c expr.c look.c main.c misc.c gnum4.c trace.c
m4_LDADD = ../libnetbsd/libnetbsd.a lib/libohash.a
man1_MANS = m4.1
