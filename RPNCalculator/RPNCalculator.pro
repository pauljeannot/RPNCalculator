#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T01:51:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPNCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    operande.cpp \
    litterale.cpp \
    ltsansexpression.cpp \
    opnum_ltsansexpression.cpp \
    ltnombre.cpp \
    ltcomplexe.cpp \
    ltnumerique.cpp \
    operateur.cpp \
    opnumerique.cpp \
    oplogique.cpp \
    opmanipulationpile.cpp \
    opconditionnelboucle.cpp \
    opliterraleexpresion.cpp \
    ltatome.cpp \
    ltexpression.cpp \
    ltprogramme.cpp \
    operandefactory.cpp

HEADERS  += mainwindow.h \
    operande.h \
    litterale.h \
    ltsansexpression.h \
    opnum_ltsansexpression.h \
    ltnombre.h \
    ltcomplexe.h \
    ltnumerique.h \
    operateur.h \
    opnumerique.h \
    oplogique.h \
    opmanipulationpile.h \
    opconditionnelboucle.h \
    ltprogramme.h \
    ltexpression.h \
    ltatome.h \
    opliterraleexpresion.h \
    operandefactory.h

FORMS    += mainwindow.ui
