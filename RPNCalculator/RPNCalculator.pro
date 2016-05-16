#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T01:51:54
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

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
    uisettingwindow.cpp \
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
    ltatome.cpp \
    ltexpression.cpp \
    ltprogramme.cpp \
    operandefactory.cpp \
    parseur.cpp \
    opliterraleexpresionprogramme.cpp \
    opatome.cpp \
    memento.cpp


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
    uisettingwindow.h \
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
    operandefactory.h \
    parseur.h \
    opliterraleexpresionprogramme.h \
    opatome.h \
    exception.h \
    memento.h


RESOURCES += \
    ressources.qrc
