#ifndef UICLAVIER_H
#define UICLAVIER_H

#include <QVBoxLayout>
#include <QList>
#include "uibuttonsline.h"
#include <iostream>

class UIKeyboardLayout : public QVBoxLayout
{
    QList<UIButtonsLine*> lines;
    QList<QSpacerItem*> spacers;

public:
    UIKeyboardLayout(QWidget* parent = 0):QVBoxLayout(parent) {
        this->setAlignment(Qt::AlignLeft);
        this->setSpacing(0);
        this->setContentsMargins(0, 0, 0, 10);
    }

    void addLine(UIButtonsLine* line) {
        lines.append(line);
        this->addLayout(line);
    }

    void addSpace() {
        QSpacerItem *item = new QSpacerItem(1,50, QSizePolicy::Fixed, QSizePolicy::Fixed);
        spacers.append(item);
        this->addSpacerItem(item);
    }

    void constructDefaultKeyboardLayout();

    ~UIKeyboardLayout() {
        QList<UIButtonsLine*>::iterator j;
        for (j = lines.begin(); j != lines.end(); ++j)
        {
            delete (*j);
        }

//        qDeleteAll(spacers);
    }
};


class UIKeyboard : public QWidget
{
public:

    UIKeyboardLayout *layout;

    UIKeyboard(QWidget* parent = 0):QWidget(parent), layout(new UIKeyboardLayout()) {
        this->initKeyboard();
    }

    ~UIKeyboard() {
        delete layout;
    }

    void initKeyboard() {
        layout->constructDefaultKeyboardLayout();
        this->setLayout(layout);
    }
};


#endif // UICLAVIER_H
