#ifndef UIBUTTONSLINE_H
#define UIBUTTONSLINE_H

#include <QHBoxLayout>
#include "uibutton.h"

class UIButtonsLine : public QHBoxLayout
{
public:
    UIButtonsLine(QWidget* wdg = 0):QHBoxLayout(wdg) {
        this->setAlignment(Qt::AlignLeft);
        this->setSpacing(0);
        this->setContentsMargins(15, 8, 15, 0);
    }

    void addButton(UIButton* btn) {
        QSpacerItem *item = new QSpacerItem(8,1, QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->addSpacerItem(item);
        this->addWidget(btn);
    }

    void addSpace() {
        QSpacerItem *item = new QSpacerItem(50,1, QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->addSpacerItem(item);
    }
};

#endif // UIBUTTONSLINE_H
