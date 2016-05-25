#ifndef UITEXTEDITOR_H
#define UITEXTEDITOR_H

#include "ltatome.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>


class UITextEditor : public QMainWindow
{
    Q_OBJECT

    static UITextEditor * instance;
    explicit UITextEditor(QString texte, LTAtome* atome = nullptr, QWidget* parent = 0);
    UITextEditor(const UITextEditor& utc);
    ~UITextEditor() {}

    QWidget* body;
    QVBoxLayout* layout;
    QTextEdit* editor;
    QString message;
    LTAtome* atomeRef;

public:
    static UITextEditor& getInstance(QString texte, LTAtome* atome = 0, QWidget* parent = 0) {
        if (!instance) {
            instance = new UITextEditor(texte, atome, parent);
        }
        else{
            instance->setEditor(texte);
            instance->setatomeRef(atome);
        }
        return *instance;
    }

    void setEditor(QString& t){
        editor->setPlainText(t);
    }

    void setatomeRef(LTAtome* a){
        atomeRef = a;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

signals:

public slots:
    void saveChange();
    void closeWindow();
};

#endif // UITEXTEDITOR_H
