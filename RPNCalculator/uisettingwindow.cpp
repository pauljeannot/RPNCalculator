#include "uisettingwindow.h"
#include "controller.h"

#include <iostream>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QLabel>
#include <QSpinBox>
#include <QHBoxLayout>

UISettingWindow * UISettingWindow::instance = 0;

UISettingWindow::UISettingWindow(QWidget *parent) : QMainWindow(parent), body(new QWidget(this)), layout(new QVBoxLayout(body))
{
    this->setFixedSize(250, 200);

    Controller& ctl = Controller::getInstance();

    QLabel* label = new QLabel(body);
    label->setText("Nombre de lignes dans la pile :");
    label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    this->layout->addWidget(label);

    QHBoxLayout* hlay = new QHBoxLayout();

    QSlider* slider = new QSlider(Qt::Horizontal, body);
    slider->setRange(1,100);
    QSpinBox* box = new QSpinBox(body);
    box->setRange(1,100);

    std::cout << ctl.settingNbLines() << std::endl;

    slider->setValue(ctl.settingNbLines());
    box->setValue(ctl.settingNbLines());

    hlay->addWidget(box);
    hlay->addWidget(slider);

    this->layout->addLayout(hlay);

    QObject::connect(slider, SIGNAL(valueChanged(int)), box, SLOT(setValue(int)));
    QObject::connect(box, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));


    QHBoxLayout* hlay2 = new QHBoxLayout();
    hlay2->setAlignment(Qt::AlignLeft);
    hlay2->setSpacing(9);
    hlay2->setContentsMargins(0,00,0,0);

    QLabel* labelCheckBox = new QLabel(body);
    labelCheckBox->setText("Afficher le clavier");
    labelCheckBox->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    QCheckBox* showKeyboardBox = new QCheckBox(body);
    if (ctl.settingShowKeyboard()) {
        showKeyboardBox->setCheckState(Qt::CheckState::Checked);
    }
    else {
        showKeyboardBox->setCheckState(Qt::CheckState::Unchecked);
    }
    hlay2->addWidget(showKeyboardBox);
    hlay2->addWidget(labelCheckBox);
    this->layout->addLayout(hlay2);

    QHBoxLayout* hlay3 = new QHBoxLayout();
    hlay3->setAlignment(Qt::AlignLeft);
    hlay3->setSpacing(9);
    hlay3->setContentsMargins(0,00,0,0);

    QLabel* labelSound = new QLabel(body);
    labelSound->setText("Activer le son (pour les messages)");
    labelSound->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    QCheckBox* playSoundBox = new QCheckBox(body);
    if (ctl.settingPlaySound()) {
        playSoundBox->setCheckState(Qt::CheckState::Checked);
    }
    else {
        playSoundBox->setCheckState(Qt::CheckState::Unchecked);
    }
    hlay3->addWidget(playSoundBox);
    hlay3->addWidget(labelSound);
    this->layout->addLayout(hlay3);

    QPushButton* btn = new QPushButton("Appliquer", body);
    btn->setFixedHeight(40);
    btn->setFlat(true);

    QPalette pal = btn->palette();
    pal.setColor(QPalette::Button, QColor(255,255,255));
    btn->setAutoFillBackground(true);
    btn->setPalette(pal);
    btn->update();
    this->layout->addWidget(btn);

    body->setLayout(layout);
    setCentralWidget(body);
}
