#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T01:51:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPNCalculator
TEMPLATE = app
CONFIG+=c++11

SOURCES += main.cpp \
    utcomputer.cpp \
    uibutton.cpp \
    uibuttonsline.cpp \
    uiclavier.cpp \
    uicommandeline.cpp \
    uipileview.cpp \
    uimessageline.cpp \
    controller.cpp \
    computer.cpp \
    stack.cpp \
    uimenu.cpp \
    uisettingwindow.cpp

HEADERS  += \
    utcomputer.h \
    uibutton.h \
    uibuttonsline.h \
    uiclavier.h \
    uicommandeline.h \
    uipileview.h \
    uimessageline.h \
    controller.h \
    computer.h \
    stack.h \
    uimenu.h \
    uisettingwindow.h

FORMS    +=

DISTFILES +=

RESOURCES += \
    ressources.qrc
