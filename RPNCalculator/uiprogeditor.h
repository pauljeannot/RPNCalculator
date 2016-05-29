#ifndef UIPROGEDITOR_H
#define UIPROGEDITOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "uicommandeline.h"
#include "uimessageline.h"
#include "uipilevarview.h"
#include "uimenu.h"
#include <iostream>
#include <QList>

class UIProgEditor: public QMainWindow
{
    Q_OBJECT

    static UIProgEditor * instance;
    QWidget* body;
    UIMessageLine* message;
    UIPileVarView * pile;
    QHBoxLayout* horizontalMainLayout;

    explicit UIProgEditor(QWidget *parent = 0);

    ~UIProgEditor() {
        delete message;
        delete pile;
        delete horizontalMainLayout;
    }

    UIProgEditor(const UIProgEditor& utc);

public:

    static UIProgEditor& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UIProgEditor(parent);
        return *instance;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

    void refreshStackView();

    void updateMessage(const QString& text) {
        this->message->updateMessage(text);
    }

    void reloadAndShow(){
        pile->reloadView("IDPROG");
        this->show();
    }

public slots:
    void clearAll();
    void createVar();
    void editVar();
    void deleteVar();
};

#endif // UIPROGEDITOR_H
