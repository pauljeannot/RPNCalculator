#include "uibutton.h"
#include "utcomputer.h"

UIButton::UIButton(QString text, float width, QString v):QPushButton(), value(v) {
    if (value == "") {
        value = text;
    }
    this->setText(text);

    int w = floor(width);
    float additionalSpace = 0;
    if (w > 1) {
        additionalSpace = w -1;
    }

    QSize size = QSize(width*40 + 8*additionalSpace, 40);
    this->setFixedSize(size);
    this->setFixedWidth(width*40 + 8*additionalSpace);
    this->setFixedHeight(40);
    this->setFlat(true);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, QColor(255,255,255));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();

    connect(this, &UIButton::clicked, this, &UIButton::hasBeenClicked);
}

void UIButton::hasBeenClicked() {
    UTComputer& utc = UTComputer::getInstance();
    utc.writeInCommandeLine(this->value);
    utc.updateMessage("bonjour");
}
