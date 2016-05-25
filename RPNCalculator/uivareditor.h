#ifndef UIVAREDITOR_H
#define UIVAREDITOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "uicommandeline.h"
#include "uimessageline.h"
#include "uipileview.h"
#include "uimenu.h"
#include <iostream>
#include <QList>

class UIVarEditor: public QMainWindow
{
    Q_OBJECT

    static UIVarEditor * instance;
    QWidget* body;
    UIMessageLine* message;
    UIPileView * pile;
    QHBoxLayout* horizontalMainLayout;

    explicit UIVarEditor(QWidget *parent = 0);

    ~UIVarEditor() {
        delete message;
        delete pile;
        delete horizontalMainLayout;
    }

    UIVarEditor(const UIVarEditor& utc);

public:

    static UIVarEditor& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UIVarEditor(parent);
        return *instance;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

    void refreshStackView();

    void updateMessage(const QString& text) {
        this->message->updateMessage(text);
    }
};


#endif // UIVAREDITOR_H
