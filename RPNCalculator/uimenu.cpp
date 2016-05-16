#include "uimenu.h"
#include "utcomputer.h"
#include <QPushButton>
#include <iostream>

UIMenu::UIMenu(QWidget *parent) : QWidget(parent), layout(new QVBoxLayout()), settingButton(new QPushButton(this)), undoButton(new QPushButton(this)), redoButton(new QPushButton(this)), settingWindow(UISettingWindow::getInstance())
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

    QObject::connect(this->settingButton, SIGNAL(clicked(bool)), this, SLOT(openSetting()));

    undoButton->setFixedSize(size);
    undoButton->setFixedWidth(40);
    undoButton->setFixedHeight(40);
    undoButton->setFlat(true);

    QPixmap undo(":/ressources/ressources/undo.png");
    QIcon ButtonIcon2(undo);
    undoButton->setIcon(ButtonIcon2);
    undoButton->setIconSize(QSize(25,25));

    QPalette pal2 = undoButton->palette();
    pal2.setColor(QPalette::Button, QColor(255,255,255));
    undoButton->setAutoFillBackground(true);
    undoButton->setPalette(pal2);
    undoButton->update();

    QObject::connect(this->undoButton, SIGNAL(clicked(bool)), this, SLOT(undoFunction()));

    //---
    redoButton->setFixedSize(size);
    redoButton->setFixedWidth(40);
    redoButton->setFixedHeight(40);
    redoButton->setFlat(true);

    QPixmap redo(":/ressources/ressources/redo.png");
    QIcon ButtonIcon3(redo);
    redoButton->setIcon(ButtonIcon3);
    redoButton->setIconSize(QSize(25,25));

    QPalette pal3 = redoButton->palette();
    pal3.setColor(QPalette::Button, QColor(255,255,255));
    redoButton->setAutoFillBackground(true);
    redoButton->setPalette(pal3);
    redoButton->update();

    QObject::connect(this->redoButton, SIGNAL(clicked(bool)), this, SLOT(redoFunction()));


    this->layout->addWidget(undoButton);
    this->layout->addWidget(redoButton);
    this->layout->addWidget(settingButton);

    this->layout->setAlignment(Qt::AlignLeft);
    this->layout->setSpacing(5);
    this->layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);
}

void UIMenu::openSetting() {
    settingWindow.show();
}

void UIMenu::undoFunction() {
    try {
       Controller::getInstance().undoFunction();
    }
    catch (ExceptionMemento e) {
        UTComputer::getInstance().updateMessage("Impossible de revenir en arrière");
    }
}

void UIMenu::redoFunction() {
    try {
       Controller::getInstance().redoFunction();
    }
    catch (ExceptionMemento e) {
        UTComputer::getInstance().updateMessage("Impossible de revenir en avant");
    }
}

