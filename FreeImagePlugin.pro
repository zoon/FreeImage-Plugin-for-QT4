TARGET = qfreeimage
TEMPLATE = lib
CONFIG += qt plugin

VERSION=$${QT_MAJOR_VERSION}.$${QT_MINOR_VERSION}.$${QT_PATCH_VERSION}

OTHER_FILES += README
HEADERS += freeimageplugin_global.h \
           FreeImageHandler.h
SOURCES += main.cpp \
           FreeImageHandler.cpp
INCLUDEPATH += .
INCLUDEPATH += FreeImage
LIBS += -L./FreeImage -lFreeImage


target.path += $$[QT_INSTALL_PLUGINS]/imageformats
INSTALLS += target
