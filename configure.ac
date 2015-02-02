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
AM_SILENT_RULES([yes])

# Checks for programs.
AC_LANG([C])
AC_PROG_CC([gcc llvm cc])
AC_PROG_CC_C_O
# AC_PROG_RANLIB - Not needed since we're using libtool
AC_PROG_INSTALL


# Checks for (optional) libraries.
have_math=no
AC_SEARCH_LIBS([exp], [m], [have_math=yes])

# Check for GCrypt and OTR libraries
AM_PATH_LIBGCRYPT(1:1.2.0, [], [AC_MSG_ERROR([libgcrypt 1.2.0 or newer is required.])])
AM_PATH_LIBOTR(4.0.0, [], [AC_MSG_ERROR([libotr 4.0.0 or newer is required.])])

# Checks for common header files.
AC_CHECK_HEADERS([inttypes.h memory.h stddef.h stdint.h stdlib.h string.h errno.h])

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

# Checks for compiler characteristics.
AC_PROG_CC_C99
AC_C_INLINE
AC_C_CONST
AC_C_RESTRICT

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