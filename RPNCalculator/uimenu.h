#ifndef UIMENU_H
#define UIMENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "uisettingwindow.h"

class UIMenu : public QWidget
{
    Q_OBJECT

    QVBoxLayout* layout;
    QPushButton* settingButton;
    QPushButton* undoButton;
    QPushButton* redoButton;
    UISettingWindow& settingWindow;

public:
    explicit UIMenu(QWidget *parent = 0);

    ~UIMenu() {
        UISettingWindow::freeInstance();
    }

signals:

public slots:
    void openSetting();
    void undoFunction();
    void redoFunction();

};

#endif // UIMENU_H
