#ifndef UTCOMPUTER_H
#define UTCOMPUTER_H

#include <QMainWindow>
#include "uicommandeline.h"
#include "uimessageline.h"
#include "uiclavier.h"
#include "uipileview.h"
#include "uimenu.h"
#include <iostream>

class UTComputer : public QMainWindow
{
    Q_OBJECT

    static UTComputer * instance;
    UICommandLine *cmd;
    UIMessageLine* message;
    UIKeyboard *clavier;
    UIPileView * pile;
    QHBoxLayout* horizontalMainLayout;
    UIMenu* menu;

    explicit UTComputer(QWidget *parent = 0);

    ~UTComputer() {
        delete cmd;
        delete message;
        delete clavier;
        delete pile;
        delete menu;
        delete horizontalMainLayout;
    }

    UTComputer(const UTComputer& utc);

public:

    static UTComputer& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UTComputer(parent);
        return *instance;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

    void writeInCommandeLine(const QString& text);

    void showKeyboard() {
        if(!horizontalMainLayout->children().contains(clavier)) {
            this->setFixedSize(800, 500);
            horizontalMainLayout->addWidget(clavier);
           }
    }

    void hideKeyboard() {
            horizontalMainLayout->removeWidget(clavier);
            this->setFixedSize(330, 500);
    }

    void refreshUIWithNewSetting(unsigned int nbLines, bool playS, bool showK);

    void updateMessage(const QString& text) {
        this->message->updateMessage(text);
    }

signals:

public slots:
    void commandeLineChanged(const QString text);
    void commandeLineEnterPressed();
};

#endif // UTCOMPUTER_H
