# calc/Makefile.am

ACLOCAL_AMFLAGS = -I m4 -I build-aux


BUILT_SOURCES =		\
	parser.cc	\
	parser.hh	\
	lexer.cc	\
	lexer.hh	\
	nt.yy.cc	\
	nt.yy.hh	\
	nt.ll.cc	\
	nt.ll.hh

lib_LTLIBRARIES = libcalc.la
libcalc_la_SOURCES = calc.hpp calc.cpp parser.yy lexer.ll yyctx.hpp yyctx.cpp


bin_PROGRAMS = calc nicetry

calc_SOURCES = main.cpp
calc_CPPFLAGS = $(BOOST_CPPFLAGS)
# calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
# calc_LDADD = $(BOOST_THREAD_LIBS)
# calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
calc_LDADD = libcalc.la


nicetry_SOURCES =	\
	ntmain.cpp	\
	nt.yy.hh	\
	nt.yy.cc	\
	nt.ll.hh	\
	nt.ll.cc	\
	ntctx.hpp	\
	ntctx.cpp

nt.yy.hh nt.yy.cc : nt.yy
	bison $^

nt.ll.hh nt.ll.cc : nt.ll
	flex $^
