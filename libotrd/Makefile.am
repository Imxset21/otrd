lib_LTLIBRARIES = libotrd.la
libotrd_la_LDFLAGS = -release 2.9.0 -version-info 0:0:0
libotrd_la_SOURCES = libotrd.c
libotrd_la_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/common $(LIBGCRYPT_CFLAGS) $(LIBOTR_CFLAGS)
libotrd_la_LIBADD = $(LIBOTR_LIBS) $(LIBGCRYPT_LIBS)  # ../common/libddtablehashes.la
