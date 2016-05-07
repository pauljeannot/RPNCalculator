#ifndef UISETTINGWINDOW_H
#define UISETTINGWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>

class UISettingWindow : public QMainWindow
{
    Q_OBJECT

    static UISettingWindow * instance;
    explicit UISettingWindow(QWidget *parent = 0);
    ~UISettingWindow() {    }
    UISettingWindow(const UISettingWindow& utc);

    QWidget* body;
    QVBoxLayout* layout;


public:
    static UISettingWindow& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UISettingWindow(parent);
        return *instance;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }


signals:

public slots:
};

#endif // UISETTINGWINDOW_H
