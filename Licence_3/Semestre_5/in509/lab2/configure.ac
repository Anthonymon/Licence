AC_INIT([dragon-tiger], [0.0.1], [])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall subdir-objects foreign])
AM_SILENT_RULES([yes])
AC_CONFIG_HEADERS([config.h])
AC_PROG_BISON([2.7])
AC_PROG_YACC
AC_PROG_LEX
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AC_PROG_RANLIB
AM_PROG_AR

AX_BOOST_BASE([1.48],, [AC_MSG_ERROR([dragon-tiger needs Boost, but it was not found in your system])])
AX_BOOST_PROGRAM_OPTIONS

AX_LLVM([3.8],[4.1.0],[all])

AC_SUBST(LLVM_CPPFLAGS, $LLVM_CPPFLAGS)
AC_SUBST(LLVM_LDFLAGS, $LLVM_LDFLAGS)

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/ast/Makefile
                 src/driver/Makefile
                 src/parser/Makefile
                 src/utils/Makefile
                ])
AC_OUTPUT
