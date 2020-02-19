include(../defaults.pri)
TEMPLATE = app
#CONFIG -= qt
#CONFIG -= app_bundle
CONFIG += console

QT += core gui

isEmpty(BOOST_INCLUDE_DIR): BOOST_INCLUDE_DIR=$$(BOOST_INCLUDE_DIR)
!isEmpty(BOOST_INCLUDE_DIR): INCLUDEPATH *= $${BOOST_INCLUDE_DIR}

isEmpty(BOOST_INCLUDE_DIR): {
    #message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
}

INCLUDEPATH += D:\ProjectsC++\library\boost_1_72_0
LIBS += "-LD:\ProjectsC++\library\boost_1_72_0\libs"

SOURCES += \
    main.cpp
