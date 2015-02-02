bin_PROGRAMS = otrd

# otrd daemon binary
otrd_SOURCES = otrd.c
otrd_CPPFLAGS = -I$(top_srcdir)/common -I$(top_srcdir)/include
otrd_LDADD = ../libotrd/libotrd.la  # ../common/libddtablehashes.la

# Tests OTR functions
test_otrd_bin_SOURCES = test_otrd.c
test_otrd_bin_CPPFLAGS = -I$(top_srcdir)/common -I$(top_srcdir)/include
test_otrd_bin_LDADD = ../libotrd/libotrd.la  # ../common/libddtablehashes.la

# Create test scripts
check_PROGRAMS = test_otrd.bin
check_SCRIPTS = test_otrd.sh
TESTS = $(check_SCRIPTS)

$(check_SCRIPTS): %.sh : %.bin
	echo './$< == 0' > $@
	chmod +x $@

CLEANFILES = $(check_SCRIPTS)
