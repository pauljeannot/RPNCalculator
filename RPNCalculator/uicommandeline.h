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

    void clear() {
        this->setText("");
    }
};

#endif // UICOMMANDELINE_H
