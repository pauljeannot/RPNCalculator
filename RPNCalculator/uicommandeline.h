#ifndef UICOMMANDELINE_H
#define UICOMMANDELINE_H

#include <QLineEdit>
#include <iostream>

class UICommandLine : public QLineEdit
{
public:
    UICommandLine():QLineEdit() {

    }

    void write(const QString text) {
        this->setText(this->text() + text);
    }

    void deleteLastCharacter() {
        QString newText = this->text().left(this->text().length()-1);
        this->setText(newText);
    }
};

#endif // UICOMMANDELINE_H
