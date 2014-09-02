# calc/Makefile.am

ACLOCAL_AMFLAGS = -I m4 -I build-aux

#AM_CPPFLAGS = -DYYDEBUG


BUILT_SOURCES = \
	nty.hh nty.cc ntl.hh ntl.cc \
	dumbyy.cc dumbyy.hh dumbll.cc dumbll.hh

dumbyy.cc dumbyy.hh : dumbyy.yy
	bison $^

dumbll.cc dumbll.hh : dumbll.ll
	flex $^

nty.hh nty.cc : nty.yy
	bison $^

ntl.hh ntl.cc : ntl.ll
	flex $^

CLEANFILES = $(BUILT_SOURCES)



# lib_LTLIBRARIES = libcalc.la
# libcalc_la_SOURCES = calc.hpp calc.cpp parser.yy lexer.ll yyctx.hpp yyctx.cpp

noinst_LTLIBRARIES = libdumb.la libnt.la


libdumb_la_SOURCES = \
  dumbctx.cc         \
  dumbctx.hh         \
  dumbll.ll          \
  dumbll.hh          \
  dumbll.cc          \
  dumbyy.yy          \
  dumbyy.hh          \
  dumbyy.cc


libnt_la_SOURCES = \
  ntctx.cpp        \
  ntctx.hpp        \
  ntl.cc           \
  ntl.hh           \
  ntl.ll           \
  nty.cc           \
  nty.hh           \
  nty.yy           \
  util.cc          \
  util.hh



# calc_SOURCES = main.cpp
# calc_CPPFLAGS = $(BOOST_CPPFLAGS)
# # calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
# # calc_LDADD = $(BOOST_THREAD_LIBS)
# # calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
# calc_LDADD = libcalc.la

bin_PROGRAMS = nicetry
nicetry_SOURCES = \
  where.hpp       \
  ntmain.cpp
nicetry_LDADD = libnt.la



check_PROGRAMS	     = test_scanner test_dumb # test_parse

test_scanner_SOURCES = test/scanner.cc
# test_parse_SOURCES   = test/parse.cc

test_scanner_LDADD   = libnt.la
# test_parse_LDADD     = libnt.la

test_dumb_SOURCES    = test/dumb.cc
test_dumb_LDADD      = libdumb.la



TESTS = $(check_PROGRAMS)



