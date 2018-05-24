bin_PROGRAMS = dtiger

dtiger_SOURCES = driver.cc
dtiger_CXXFLAGS = -pedantic -Wall @LLVM_CPPFLAGS@ -fexceptions
dtiger_LDADD = ../ast/libast.a ../parser/libparser.a ../utils/libutils.a
AM_LDFLAGS = $(BOOST_LDFLAGS) $(BOOST_PROGRAM_OPTIONS_LIB) @LLVM_LDFLAGS@
CLEANFILES=
