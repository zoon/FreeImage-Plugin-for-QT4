#! /bin/sh

CC=cl.exe
RC=rc.exe
NAME=qfreeimage4
BNAME=${NAME}.dll
INC='/IE:/Qt/4.5.3/include'
INC+=' /IE:/Qt/4.5.3/include/qtmain'
INC+=' /IE:/Qt/4.5.3/include/QtCore'
INC+=' /IE:/Qt/4.5.3/include/QtGui'
INC+=' /IE:/Src/FreeImage'
LIBS='perforce/QTCoreP44.lib perforce/QTGuiP44.lib'
LIBS+=' E:/Src/FreeImage/FreeImage.lib'
DEFINES="/D QT_LARGEFILE_SUPPORT /D QT_DLL /D QT_CORE_LIB /D QT_GUI_LIB /D QT_THREAD_SUPPORT"
DEFINES+=" /D QT_PLUGIN"
DEFINES+=" /D QT_NO_DEBUG /D NDEBUG /D UNICODE /D WIN32"
DEFINES+=" /D VERSION=4.3"
OPTS="/FD /EHsc /MD /GS- /Zc:wchar_t-"


$RC qfreeimage_resource.rc
$CC /O2 /LD $OPTS /Fe${NAME} $INC $LIBS $DEFINES *.cpp qfreeimage_resource.res
mt -manifest ${BNAME}.manifest /outputresource:"${BNAME};#2";

rm *.obj *.manifest *.exp *.RES *.res *.idb ${NAME}.lib
