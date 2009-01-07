#############################################################################
# Makefile for building: tabletest
# Generated by qmake (2.01a) (Qt 4.4.0) on: Tue Jan 6 23:11:34 2009
# Project:  FermentableTableWidget.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile FermentableTableWidget.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,--no-undefined
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = FermentableTableWidget.cpp \
		tabletest.cpp \
		FermentableTableModel.cpp \
		fermentable.cpp \
		observable.cpp \
		observer.cpp \
		xmlnode.cpp \
		stringparsing.cpp \
		xml.cpp \
		xmltree.cpp moc_FermentableTableWidget.cpp \
		moc_FermentableTableModel.cpp
OBJECTS       = FermentableTableWidget.o \
		tabletest.o \
		FermentableTableModel.o \
		fermentable.o \
		observable.o \
		observer.o \
		xmlnode.o \
		stringparsing.o \
		xml.o \
		xmltree.o \
		moc_FermentableTableWidget.o \
		moc_FermentableTableModel.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		FermentableTableWidget.pro
QMAKE_TARGET  = tabletest
DESTDIR       = 
TARGET        = tabletest

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: FermentableTableWidget.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile FermentableTableWidget.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile FermentableTableWidget.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/tabletest1.0.0 || $(MKDIR) .tmp/tabletest1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/tabletest1.0.0/ && $(COPY_FILE) --parents FermentableTableWidget.h FermentableTableModel.h fermentable.h observable.h xmlnode.h stringparsing.h xml.h xmltree.h .tmp/tabletest1.0.0/ && $(COPY_FILE) --parents FermentableTableWidget.cpp tabletest.cpp FermentableTableModel.cpp fermentable.cpp observable.cpp observer.cpp xmlnode.cpp stringparsing.cpp xml.cpp xmltree.cpp .tmp/tabletest1.0.0/ && (cd `dirname .tmp/tabletest1.0.0` && $(TAR) tabletest1.0.0.tar tabletest1.0.0 && $(COMPRESS) tabletest1.0.0.tar) && $(MOVE) `dirname .tmp/tabletest1.0.0`/tabletest1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/tabletest1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_FermentableTableWidget.cpp moc_FermentableTableModel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_FermentableTableWidget.cpp moc_FermentableTableModel.cpp
moc_FermentableTableWidget.cpp: FermentableTableModel.h \
		fermentable.h \
		xmlnode.h \
		observable.h \
		FermentableTableWidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) FermentableTableWidget.h -o moc_FermentableTableWidget.cpp

moc_FermentableTableModel.cpp: fermentable.h \
		xmlnode.h \
		observable.h \
		FermentableTableModel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) FermentableTableModel.h -o moc_FermentableTableModel.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

FermentableTableWidget.o: FermentableTableWidget.cpp FermentableTableModel.h \
		fermentable.h \
		xmlnode.h \
		observable.h \
		FermentableTableWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FermentableTableWidget.o FermentableTableWidget.cpp

tabletest.o: tabletest.cpp FermentableTableWidget.h \
		FermentableTableModel.h \
		fermentable.h \
		xmlnode.h \
		observable.h \
		xmltree.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tabletest.o tabletest.cpp

FermentableTableModel.o: FermentableTableModel.cpp observable.h \
		fermentable.h \
		xmlnode.h \
		FermentableTableModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FermentableTableModel.o FermentableTableModel.cpp

fermentable.o: fermentable.cpp fermentable.h \
		xmlnode.h \
		observable.h \
		stringparsing.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fermentable.o fermentable.cpp

observable.o: observable.cpp observable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o observable.o observable.cpp

observer.o: observer.cpp observable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o observer.o observer.cpp

xmlnode.o: xmlnode.cpp xmlnode.h \
		xml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xmlnode.o xmlnode.cpp

stringparsing.o: stringparsing.cpp stringparsing.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stringparsing.o stringparsing.cpp

xml.o: xml.cpp xml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xml.o xml.cpp

xmltree.o: xmltree.cpp xmlnode.h \
		xmltree.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xmltree.o xmltree.cpp

moc_FermentableTableWidget.o: moc_FermentableTableWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_FermentableTableWidget.o moc_FermentableTableWidget.cpp

moc_FermentableTableModel.o: moc_FermentableTableModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_FermentableTableModel.o moc_FermentableTableModel.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

