# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.6])
AC_INIT([otrd], [1.0], [pr273@cornell.edu])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
LT_INIT([dlopen])
AC_CONFIG_SRCDIR([src/otrd.c]) 
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])
AM_SILENT_RULES([no])

# Checks for programs.
AC_LANG([C])
AC_PROG_CC([gcc llvm cc])
AC_PROG_CC_C_O
AC_PROG_INSTALL

# Checks for compiler characteristics.
AC_PROG_CC_C99
AC_C_INLINE
AC_C_CONST
AC_C_RESTRICT

# Checks for POSIX 2008 compatibility
AC_EGREP_CPP(posix_200809L_supported,
             [#define _POSIX_C_SOURCE 200809L
              #include <unistd.h>
              #ifdef _POSIX_VERSION
              #if _POSIX_VERSION == 200809L
              posix_200809L_supported
              #endif
              #endif
             ],
             [],
             [AC_MSG_FAILURE([Implementation must conform to POSIX.1-2008.])]
)

# Checks for (optional) libraries.
have_math=no
AC_SEARCH_LIBS([exp], [m], [have_math=yes])

# Check for GCrypt and OTR libraries
AM_PATH_LIBGCRYPT(1:1.2.0, [], [AC_MSG_ERROR([libgcrypt 1.2.0+ is required.])])
AM_PATH_LIBOTR(4.0.0, [], [AC_MSG_ERROR([libotr 4.0.0+ is required.])])

# Checks for common header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])
AC_CHECK_HEADERS([errno.h unistd.h inttypes.h memory.h])

# Checks for (optional) header files.
if test "x${have_math}" = xyes; then
   AC_CHECK_HEADERS([math.h], [], [have_math=no])
fi

if test "x${have_math}" = xno; then
   AC_MSG_WARN([
   -------------------------------------
   Unable to find math.h on this system.
   Building without math.h.
   -------------------------------------])
fi

have_x86intrin=no
AC_CHECK_HEADERS([x86intrin.h], [have_x86intrin=yes], [])

if test "x${have_x86intrin}" = xno; then
   AC_MSG_WARN([
   -------------------------------------
   Unable to find x86intrin.h on this system.
   Building crc32 without x86intrin.h.
   -------------------------------------])
   CFLAGS="-std=c99 -O2 -Wall -Wextra -Wpedantic"
else
   CFLAGS="-std=c99 -O2 -msse4.2 -Wall -Wextra -Wpedantic"
fi

# Hardening flags

# Might not actually do anything on some platforms
AX_CHECK_COMPILE_FLAG([-D_FORTIFY_SOURCE=2],
                      [CPPFLAGS="$CPPFLAGS -D_FORTIFY_SOURCE=2"],
                      [AC_MSG_WARN([Building without D_FORTIFY_SOURCE])])

# Check for stack protection for all functions
AX_CHECK_COMPILE_FLAG([-fstack-protector-all],
                      [CFLAGS="$CFLAGS -fstack-protector-all"],
                      [AC_MSG_WARN([Building without stack protector])])

# Check for position-independent executable support
AC_ARG_ENABLE([pie],
[  --enable-pie    Enable position-independent executable, if available],
[case "${enableval}" in
  yes) pie=true ;;
  no)  pie=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-pie]) ;;
esac],[pie=false])
AM_CONDITIONAL([CHECK_PIE], [test x$pie = xtrue])

# Assume we don't have PIE by default, check for compiler/linker flags
_HAVE_PIE=false
_CFLAGS="$CFLAGS"
_LDFLAGS="$LDFLAGS"
## Check for PIE compiler flag
AM_COND_IF(CHECK_PIE, [AX_CHECK_COMPILE_FLAG(
                        [-fpie],
                        [_HAVE_PIE=true; CFLAGS="$CFLAGS -fpie"],
                        [AC_MSG_WARN([Building without PIE support])])],
                     [])
## Check for PIE linker flag
AM_COND_IF(CHECK_PIE, [AC_MSG_CHECKING([if -pie works during linking])], [])
AM_COND_IF(CHECK_PIE,
            [LDFLAGS="$LDFLAGS -pie"],
            [])
AM_COND_IF(CHECK_PIE,
            [AC_LINK_IFELSE(
                [AC_LANG_PROGRAM(
                    [[const char* hw = "Hello, World!\n";]],
                    [[return 0;]])],
                [_HAVE_PIE=true; AC_MSG_RESULT([yes])],
                [AC_MSG_WARN([Building without PIE support.])])],
            [])
## We revert back and set a conditional since this only applies for binaries
LDFLAGS="$_LDFLAGS"
CFLAGS="$_CFLAGS"
AM_CONDITIONAL([HAVE_PIE], [test x$_HAVE_PIE = xtrue])

# Checks for types/typedefs.
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MEMCMP
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
                 common/Makefile
                 include/Makefile
                 libotrd/Makefile
                 src/Makefile])
AC_OUTPUT
