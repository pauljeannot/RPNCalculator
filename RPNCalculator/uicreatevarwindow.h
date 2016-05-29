#ifndef UICREATEVARWINDOW_H
#define UICREATEVARWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>


class UICreateVarWindow : public QMainWindow
{
    Q_OBJECT

    static UICreateVarWindow * instance;
    //explicit UICreateVarWindow(QWidget* parent = 0);
    explicit UICreateVarWindow(QWidget* parent = 0, QString name = "", QString content = "", QString type = "");
    UICreateVarWindow(const UICreateVarWindow& utc);
    ~UICreateVarWindow() {}

    QWidget* body;
    QVBoxLayout* layout;
    QLineEdit* varName;
    QLineEdit* varContent;
    QString message;
    QString type;

public:
    static UICreateVarWindow& getInstance(QWidget* parent = 0, QString name = "", QString content = "", QString type = "") {
        if (!instance) {
            instance = new UICreateVarWindow(parent, name, content, type);
        }
        return *instance;
    }

    void setVarName(QString& t){
        varName->setText(t);
    }

    void setVarContent(QString& t){
        varContent->setText(t);
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

    void reloadAndShow(QString type){
        this->type = type;
        varName->clear();
        varContent->clear();
        this->show();
    }

    void reloadAndShow(QString name, QString content, QString type){
        this->type = type;
        varName->setText(name);
        varContent->setText(content);
        this->show();
    }

signals:

public slots:
    void saveChange();
    void closeWindow();
};


#endif // UICREATEVARWINDOW_H
