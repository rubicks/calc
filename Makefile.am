# calc/Makefile.am

ACLOCAL_AMFLAGS = -I m4 -I build-aux




bin_PROGRAMS = calc
calc_SOURCES = main.cpp
calc_CPPFLAGS = $(BOOST_CPPFLAGS)
calc_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
calc_LDADD = $(BOOST_THREAD_LIBS)

ALL :
	@echo boost_cppflags == $(BOOST_CPPFLAGS)
