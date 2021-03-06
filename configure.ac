# Copyright © 2003  Noah Levitt
# Copyright © 2007, 2008, 2009 Christian Persch
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335 USA

m4_define([gucharmap_version_major],[11])
m4_define([gucharmap_version_minor],[0])
m4_define([gucharmap_version_micro],[4])
m4_define([gucharmap_version_extra],[])
m4_define([gucharmap_version],[gucharmap_version_major.gucharmap_version_minor.gucharmap_version_micro()gucharmap_version_extra])

# Before making a release, the libtool version should be modified.
# The string is of the form C:R:A.
# - If interfaces have been changed or added, but binary compatibility has
#   been preserved, change to C+1:0:A+1
# - If binary compatibility has been broken (eg removed or changed interfaces)
#   change to C+1:0:0
# - If the interface is the same as the previous version, change to C:R+1:A
m4_define([gucharmap_lt_current],[7])
m4_define([gucharmap_lt_revision],[0])
m4_define([gucharmap_lt_age],[0])
m4_define([gucharmap_lt_version_info],[gucharmap_lt_current:gucharmap_lt_revision:gucharmap_lt_age])
m4_define([gucharmap_lt_current_minus_age],[m4_eval(gucharmap_lt_current - gucharmap_lt_age)])

AC_PREREQ([2.56])

AC_INIT([GNOME Character Map],[gucharmap_version],[http://bugzilla.gnome.org/enter_bug.cgi?product=gucharmap],[gucharmap])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([gucharmap/gucharmap.h.in])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11 foreign dist-bzip2 no-dist-gzip])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE([enable])

# checks for progs

GNOME_DEBUG_CHECK

AC_PROG_CC
AC_USE_SYSTEM_EXTENSIONS

AC_DISABLE_STATIC
AC_PROG_LIBTOOL
IT_PROG_INTLTOOL([0.40.0])

AM_PROG_CC_C_O

# User documentation
YELP_HELP_INIT([no-lc-media-links no-lc-dist])

GLIB_REQUIRED=2.32.0
GIO_REQUIRED=2.32.0

# check for win32
case "$host" in
  *-*-mingw*) os_win32="yes" ;; 
  *) os_win32="no" ;; 
esac

if test "x$os_win32" = "xyes"
then
    CFLAGS="$CFLAGS -mms-bitfields -mwindows"
fi
AM_CONDITIONAL(OS_WIN32, test "x$os_win32" = "xyes")

# Which gtk+ API version to compile against

AC_MSG_CHECKING([which gtk+ version to compile against])
AC_ARG_WITH([gtk],
  [AS_HELP_STRING([--with-gtk=3.0],[which gtk+ version to compile against (default: 3.0)])],
  [case "$with_gtk" in
     3.0) ;;
     2.0) AC_MSG_ERROR([unsupported gtk version $with_gtk specified]) ;;
     *) AC_MSG_ERROR([invalid gtk version $with_gtk specified]) ;;
   esac],
  [with_gtk=3.0])
AC_MSG_RESULT([$with_gtk])

case "$with_gtk" in
  3.0) GTK_API_VERSION=3.0
       GTK_REQUIRED=3.4.0
       GUCHARMAP_API_VERSION=2.90
       GUCHARMAP_API_MAJOR_VERSION=2
       GUCHARMAP_API_MINOR_VERSION=90
       GUCHARMAP_API_PC_VERSION=2.90
       GUCHARMAP_LIBRARY_SUFFIX="-$GUCHARMAP_API_VERSION"
       ;;
esac

AC_SUBST([GTK_API_VERSION])
AC_SUBST([GUCHARMAP_API_VERSION])
AC_SUBST([GUCHARMAP_API_VERSION_U],[AS_TR_SH([$GUCHARMAP_API_VERSION])])
AC_SUBST([GUCHARMAP_API_MAJOR_VERSION])
AC_SUBST([GUCHARMAP_API_MINOR_VERSION])
AC_SUBST([GUCHARMAP_API_PC_VERSION])
AC_SUBST([GUCHARMAP_LIBRARY_SUFFIX_U],[AS_TR_SH([$GUCHARMAP_LIBRARY_SUFFIX])])

AM_CONDITIONAL([HAVE_GTK_2],[test "$with_gtk" = "2.0"])
AM_CONDITIONAL([HAVE_GTK_3],[test "$with_gtk" = "3.0"])


PKG_CHECK_MODULES([GTK],[
  glib-2.0 >= $GLIB_REQUIRED
  gio-2.0 >= $GIO_REQUIRED
  gtk+-$GTK_API_VERSION >= $GTK_REQUIRED
  freetype2
])

sv_LIBS="$LIBS"
LIBS=
AC_SEARCH_LIBS([dlsym],[dl])
LIBDL="$LIBS"
LIBS="$sv_LIBS"
AC_SUBST([LIBDL])

GLIB_GENMARSHAL="$($PKG_CONFIG --variable=glib_genmarshal glib-2.0)"
AC_SUBST([GLIB_GENMARSHAL])
GLIB_MKENUMS="$($PKG_CONFIG --variable=glib_mkenums glib-2.0)"
AC_SUBST([GLIB_MKENUMS])

GLIB_GSETTINGS

AC_MSG_CHECKING([whether to build the charmap programme])
AC_ARG_ENABLE([charmap],
  [AS_HELP_STRING([--disable-charmap],[disable building the charmap programme])],
  [],[enable_charmap=yes])
AC_MSG_RESULT([$enable_charmap])

AM_CONDITIONAL([ENABLE_CHARMAP],[test "$enable_charmap" = "yes"])

# checks for funcs 
AC_CHECK_FUNCS([bind_textdomain_codeset])

AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

# Some utilities
AC_PROG_LN_S
AC_PROG_SED

AC_ARG_VAR([GLIB_COMPILE_RESOURCES],[the glib-compile-resources programme])
if test -z "$GLIB_COMPILE_RESOURCES"; then
  AC_PATH_PROG([GLIB_COMPILE_RESOURCES],[glib-compile-resources],[false])
  if test "$GLIB_COMPILE_RESOURCES" = "false"; then
      AC_MSG_ERROR([glib-compile-resources not found])
  fi
fi

AC_ARG_VAR([XMLLINT],[the xmllint programme])
if test -z "$XMLLINT"; then
  AC_PATH_PROG([XMLLINT],[xmllint],[false])
  if test "$XMLLINT" = "false"; then
    AC_MSG_ERROR([xmllint not found])
  fi
fi

AC_ARG_VAR([DESKTOP_FILE_VALIDATE],[the desktop-file-validate programme])
if test -z "$DESKTOP_FILE_VALIDATE"; then
  AC_PATH_PROG([DESKTOP_FILE_VALIDATE],[desktop-file-validate],[])
  if test -z "$DESKTOP_FILE_VALIDATE"; then
    AC_MSG_ERROR([desktop-file-validate not found])
  fi
fi

# Unicode data

AC_MSG_CHECKING([for Unicode data])
AC_ARG_WITH([unicode-data],
        [AS_HELP_STRING([--with-unicode-data=PATH],[Specify absolute directory where the Unicode data files reside. If 'download', downloads the files to the build directory.])],
        [case "$withval" in
           download) unicodedatadir='${builddir}'
                     with_provided_unicode_data="download"
                     ;;
	   yes|no) AC_MSG_ERROR([You need to specify the path to the unicode data files with --with-unicode-data=PATH, or use
--with-unicode-data=download to download the data files during the build process.])
                   ;;
           *) unicodedatadir="$(readlink -f $withval)"
              with_provided_unicode_data="yes (from $unicodedatadir)"
              ;;
         esac],
        [AC_MSG_ERROR([You need to specify the path to the unicode data files with --with-unicode-data=PATH, or use
--with-unicode-data=download to download the data files during the build process.])])
AC_MSG_RESULT([$with_provided_unicode_data])

AM_CONDITIONAL([WITH_UNICODE_DATA],[test "$with_provided_unicode_data" != "download"])
AC_SUBST([unicodedatadir])

# If we don't have a directory where we can find Unicode data in, we need to download it.
# For that, we need some utilities

# Note! Not using UNZIP as variable name here since unzip itself
# uses the UNZIP env var and interprets it as its options.
AC_ARG_VAR([PROG_UNZIP],[the unzip programme])
if test -z "$PROG_UNZIP"; then
  AC_PATH_PROG([PROG_UNZIP],[unzip],[false])
  if test "$PROG_UNZIP" = "false"; then
      AC_MSG_ERROR([unzip not found])
  fi
fi

AC_ARG_VAR([WGET],[the wget programme])
if test -z "$WGET"; then
  AC_PATH_PROG([WGET],[wget],[false])
  if test "$with_provided_unicode_data" = "download" -a "$WGET" = "false"; then
      AC_MSG_ERROR([wget not found])
  fi
fi

AC_ARG_VAR([SHA512SUM],[the sha512sum programme])
if test -z "$SHA512SUM"; then
  AC_PATH_PROGS([SHA512SUM],[gsha512sum sha512sum],[false])
  if test "$with_provided_unicode_data" = "download" -a "$WGET" = "false"; then
    AC_MSG_ERROR([sha512sum not found])
  fi
fi

# ****
# i18n
# ****

GETTEXT_PACKAGE=gucharmap
AC_SUBST([GETTEXT_PACKAGE])
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE],["$GETTEXT_PACKAGE"],[The gucharmap gettext domain])
AM_GLIB_GNU_GETTEXT

##########################################################
# Check for -Bsymbolic-functions linker flag used to avoid
# intra-library PLT jumps, if available.
##########################################################

AC_ARG_ENABLE([Bsymbolic],
  [AS_HELP_STRING([--disable-Bsymbolic],
                  [disable linking with -Bsymbolic])],
  [],[enable_Bsymbolic=yes])

BSYMBOLIC_LDFLAG=
if test "$enable_Bsymbolic" != "no"; then
  CC_CHECK_LDFLAGS(["-Wl,-Bsymbolic-functions"],
    [BSYMBOLIC_LDFLAG="-Wl,-Bsymbolic-functions"],
    [if test "$enable_Bsymbolic" = "auto"; then
       AC_MSG_WARN([-Bsymbolic not supported by ld; disabling])
       enable_Bsymbolic=no
     else
       AC_MSG_ERROR([-Bsymbolic requested but not supported by ld. Use --disable-Bsymbolic to disable])
     fi])
fi

AC_SUBST([BSYMBOLIC_LDFLAG])

# ***********
# Compilation
# ***********

CC_CHECK_CFLAGS_APPEND([ \
  -Wall -Wextra \
  -Wformat-nonliteral -Werror=format-security \
  -Wsign-compare -Werror=implicit-function-declaration \
  -Wpointer-arith -Wwrite-strings -Wstrict-prototypes \
  -Waggregate-return -Wcast-align -Wimplicit -Wuninitialized \
  -Wmissing-prototypes -Wmissing-declarations -Wnested-externs \
  -Wpacked -Wmissing-format-attribute -Wshadow \
  -Wstrict-aliasing=2 -Winit-self -Wunsafe-loop-optimizations \
  -Wdeclaration-after-statement -Wold-style-definition \
  -Wno-missing-field-initializers -Wno-unused-parameter \
  -Wformat-signedness \
  -fno-common -fno-strict-aliasing -Wno-switch-enum])

# ********
# Bindings
# ********

# No automagic please!
if test -z "$enable_introspection"; then
  enable_introspection=yes
fi

GOBJECT_INTROSPECTION_CHECK([0.9.0])

# No automagic please!
if test -z "$enable_vala"; then
  enable_vala=no
fi
m4_ifdef([VAPIGEN_CHECK],
  [VAPIGEN_CHECK([0.16])],
  [AM_CONDITIONAL([ENABLE_VAPIGEN],[false])])

case "$with_gtk" in
  3.0) GUCHARMAP_GIR_VERSION=$GUCHARMAP_API_VERSION
       GUCHARMAP_VAPI_VERSION=$GUCHARMAP_API_VERSION
       ;;
esac

AC_SUBST([GUCHARMAP_GIR_VERSION])
AC_SUBST([GUCHARMAP_GIR_VERSION_U],[AS_TR_SH([$GUCHARMAP_GIR_VERSION])])
AC_SUBST([GUCHARMAP_VAPI_VERSION])
AC_SUBST([GUCHARMAP_VAPI_VERSION_U],[AS_TR_SH([$GUCHARMAP_VAPI_VERSION])])

# ***************
# API & User Docs
# ***************

GTK_DOC_CHECK([1.0])

# *****************************************************************************

AC_SUBST([GUCHARMAP_VERSION_MAJOR],[gucharmap_version_major])
AC_SUBST([GUCHARMAP_VERSION_MINOR],[gucharmap_version_minor])
AC_SUBST([GUCHARMAP_VERSION_MICRO],[gucharmap_version_micro])
AC_SUBST([LIBGUCHARMAP_LT_VERSION],[gucharmap_lt_version_info])
AC_SUBST([LIBGUCHARMAP_LT_CURRENT_MINUS_AGE],[gucharmap_lt_current_minus_age])

AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_LDFLAGS])

AC_CONFIG_FILES([
Makefile
gucharmap.desktop.in
gucharmap.nsi
gucharmap.spec
data/Makefile
docs/Makefile
docs/reference/Makefile
gucharmap/Makefile
gucharmap/gucharmap.gresource.xml
gucharmap/gucharmap.h
help/Makefile
pixmaps/Makefile
po/Makefile.in
])

AC_CONFIG_FILES([gucharmap-${GUCHARMAP_API_PC_VERSION}.pc:gucharmap.pc.in],[GUCHARMAP_API_PC_VERSION=$GUCHARMAP_API_PC_VERSION])

AC_OUTPUT
