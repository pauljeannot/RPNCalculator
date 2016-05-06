#ifndef UTCOMPUTER_H
#define UTCOMPUTER_H

#include <QMainWindow>
#include "uicommandeline.h"
#include "uimessageline.h"
#include "uiclavier.h"
#include "uipileview.h"

class UTComputer : public QMainWindow
{
    Q_OBJECT

    UICommandLine *cmd;
    UIMessageLine* message;
    UIKeyboard *clavier;
    UIPileView * pile;

public:
    explicit UTComputer(QWidget *parent = 0);

    ~UTComputer() {
        delete cmd;
        delete message;
        delete clavier;
        delete pile;
    }


signals:

public slots:
};

#endif // UTCOMPUTER_H
