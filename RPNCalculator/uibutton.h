#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QPushButton>
#include <math.h>


class UIButton : public QPushButton
{
    QString value;

public:
    UIButton(QString text, float width = 1, QString v = "");
    QString getValue() const { return value; }

public slots:
   void hasBeenClicked();

};

#endif // UIBUTTON_H
