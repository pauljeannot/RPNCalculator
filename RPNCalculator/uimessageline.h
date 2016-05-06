#ifndef UIMESSAGELINE_H
#define UIMESSAGELINE_H

#include <QLineEdit>

class UIMessageLine : public QLineEdit
{
public:
    UIMessageLine():QLineEdit() {
        this->setStyleSheet("background: black; color:white");
    }
};

#endif // UIMESSAGELINE_H
