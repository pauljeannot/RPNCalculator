#include "uimenu.h"
#include "utcomputer.h"
#include <QPushButton>
#include <iostream>

UIMenu::UIMenu(QWidget *parent) : QWidget(parent), layout(new QVBoxLayout()), settingButton(new QPushButton(this)), settingWindow(UISettingWindow::getInstance())
{
    this->setFixedWidth(40);
    this->setMaximumWidth(40);
    this->setMinimumWidth(40);

    QSize size = QSize(40, 40);
    settingButton->setFixedSize(size);
    settingButton->setFixedWidth(40);
    settingButton->setFixedHeight(40);
    settingButton->setFlat(true);

    QPixmap pixmap(":/ressources/ressources/settingsIcon.png");
    QIcon ButtonIcon(pixmap);
    settingButton->setIcon(ButtonIcon);
    settingButton->setIconSize(QSize(25,25));

    QPalette pal = settingButton->palette();
    pal.setColor(QPalette::Button, QColor(255,255,255));
    settingButton->setAutoFillBackground(true);
    settingButton->setPalette(pal);
    settingButton->update();
    this->layout->addWidget(settingButton);

    QObject::connect(this->settingButton, SIGNAL(clicked(bool)), this, SLOT(openSetting()));
}

void UIMenu::openSetting() {
    settingWindow.show();
}
