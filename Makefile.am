# calc/Makefile.am

ACLOCAL_AMFLAGS = -I m4 -I build-aux


# BUILT_SOURCES =		\
# 	parser.cc	\
# 	parser.hh	\
# 	lexer.cc	\
# 	lexer.hh


# lib_LTLIBRARIES = libcalc.la
# libcalc_la_SOURCES = calc.hpp calc.cpp parser.yy lexer.ll yyctx.hpp yyctx.cpp


# bin_PROGRAMS = calc nicetry
bin_PROGRAMS = nicetry

# calc_SOURCES = main.cpp
# calc_CPPFLAGS = $(BOOST_CPPFLAGS)
# # calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
# # calc_LDADD = $(BOOST_THREAD_LIBS)
# # calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
# calc_LDADD = libcalc.la


nicetry_SOURCES = \
  where.hpp       \
  ntl.ll          \
  nty.yy          \
  ntctx.hpp       \
  ntctx.cpp       \
  ntmain.cpp


BUILT_SOURCES = nty.hh nty.cc ntl.hh ntl.cc

nty.hh nty.cc : nty.yy
	bison $^

ntl.hh ntl.cc : ntl.ll
	flex $^

CLEANFILES = $(BUILT_SOURCES)

# nt.yy.hh nt.yy.cc : nt.yy
# 	bison $^

# nt.ll.hh nt.ll.cc : nt.ll
# 	flex $^
