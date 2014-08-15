# calc/configure.ac

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([calc],[0.1.0-snapshot],[rubicks00@gmail.com])
AC_LANG_PUSH([C++])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE
LT_PREREQ([2.4])
LT_INIT([dlopen])

# Checks for programs.
AX_CXX_COMPILE_STDCXX_11
AX_PROG_FLEX
AX_PROG_BISON

# Checks for libraries.
BOOST_REQUIRE([1.55])
dnl BOOST_THREAD

# Checks for header files.


# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
