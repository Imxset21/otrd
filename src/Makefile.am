bin_PROGRAMS = otrd

# otrd daemon binary
otrd_SOURCES = otrd.c
# Check for optional Position-Independent Executable support
if HAVE_PIE
otrd_CFLAGS = $(AM_CFLAGS) -fpie
otrd_LDFLAGS = $(AM_LDFLAGS) -pie
else
otrd_CFLAGS = $(AM_CFLAGS)
otrd_LDFLAGS = $(AM_LDFLAGS)
endif
otrd_CPPFLAGS = -I$(top_srcdir)/common -I$(top_srcdir)/include
otrd_LDADD = ../libotrd/libotrd.la  # ../common/libutil.la

# Tests OTR functions
test_otrd_bin_SOURCES = test_otrd.c
test_otrd_bin_CPPFLAGS = -I$(top_srcdir)/common -I$(top_srcdir)/include
test_otrd_bin_LDADD = ../libotrd/libotrd.la  # ../common/libutil.la

# Create test scripts
check_PROGRAMS = test_otrd.bin
check_SCRIPTS = test_otrd.sh
TESTS = $(check_SCRIPTS)

$(check_SCRIPTS): %.sh : %.bin
	echo './$< == 0' > $@
	chmod +x $@

CLEANFILES = $(check_SCRIPTS)
