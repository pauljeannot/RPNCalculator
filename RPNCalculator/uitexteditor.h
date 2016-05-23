#ifndef UITEXTEDITOR_H
#define UITEXTEDITOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>


class UITextEditor : public QMainWindow
{
    Q_OBJECT

    static UITextEditor * instance;
    explicit UITextEditor(QString texte, QWidget* parent = 0);
    UITextEditor(const UITextEditor& utc);
    ~UITextEditor() {}

    QWidget* body;
    QVBoxLayout* layout;
    QTextEdit* editor;
    QString message;

public:
    static UITextEditor& getInstance(QString texte, QWidget* parent = 0) {
        if (!instance) instance = new UITextEditor(texte, parent);
        return *instance;
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
