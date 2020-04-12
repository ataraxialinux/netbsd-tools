AM_CPPFLAGS = -I$(top_srcdir)/include -DSMALL

bin_PROGRAMS = pax
pax_SOURCES = ar_io.c ar_subs.c buf_subs.c file_subs.c ftree.c gen_subs.c getoldopt.c options.c pat_rep.c pax.c sel_subs.c tables.c tar.c tty_subs.c pack_dev.c cpio.c
pax_LDADD = ../libnetbsd/libnetbsd.a
man1_MANS = pax.1 tar.1 cpio.1

install-exec-hook:
	ln -sf pax $(DESTDIR)$(bindir)/cpio
	ln -sf pax $(DESTDIR)$(bindir)/tar
