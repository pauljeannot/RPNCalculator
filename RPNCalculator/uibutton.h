#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QPushButton>
#include <math.h>

class UIButton : public QPushButton
{
    QString value;

public:
    UIButton(QString text, float width = 1, QString value = ""):QPushButton(), value(value) {
        if (value == "") { value = text; }
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
    }

    QString getValue() const { return value; }
};

#endif // UIBUTTON_H
