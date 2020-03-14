#include(../defaults.pri)
QT += core gui

TARGET = pong
TEMPLATE = lib

#CONFIG += staticlib

# include freetype
LIBS += -LD:\ProjectsC++\library\freetype-2.3.5-1-lib\lib #-lfreetype

INCLUDEPATH += D:\ProjectsC++\library\freetype-2.3.5-1-lib\include
DEPENDPATH += D:\ProjectsC++\library\freetype-2.3.5-1-lib\include

INCLUDEPATH += D:\ProjectsC++\library\freetype-2.3.5-1-lib\include\freetype2
DEPENDPATH += D:\ProjectsC++\library\freetype-2.3.5-1-lib\include\freetype2

QT += opengl
LIBS += -lglu32 -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Helper.cpp \
    PBall.cpp \
    PConfig.cpp \
    PLayer.cpp \
    PLayerMenu.cpp \
    PLayerScene_1.cpp \
    PObject.cpp \
    PPlayer.cpp \
    PongCore.cpp \
    PEvents.cpp

HEADERS += \
    Helper.h \
    PBall.h \
    PConfig.h \
    PLayer.h \
    PLayerMenu.h \
    PLayerScene_1.h \
    PObject.h \
    PPlayer.h \
    PongCore.h \
    PEvents.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    firstShader.vert \
    frag.frag

RESOURCES += \
    fonts.qrc \
    shader.qrc
