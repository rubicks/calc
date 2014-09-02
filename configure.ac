# calc/configure.ac

AC_PREREQ([2.68])
AC_INIT([calc],[0.1.0-snapshot],[rubicks00@gmail.com])
AC_LANG_PUSH([C++])
AC_CONFIG_SRCDIR([ntmain.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([subdir-objects])
LT_PREREQ([2.4])
LT_INIT([dlopen])


# Checks for programs.

AX_CXX_COMPILE_STDCXX_11

AX_PROG_BISON([],[AC_MSG_ERROR([bison executable missing])])

AX_PROG_FLEX([],[AC_MSG_ERROR([flex executable missing])])


# Checks for libraries.
BOOST_REQUIRE([1.55])
dnl BOOST_THREAD

# Checks for header files.


# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
