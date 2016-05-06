#ifndef UICLAVIER_H
#define UICLAVIER_H

#include <QVBoxLayout>
#include "uibuttonsline.h"

class UIClavier : public QVBoxLayout
{
public:
    UIClavier(QWidget* parent):QVBoxLayout(parent) {
        this->setAlignment(Qt::AlignLeft);
        this->setSpacing(0);
        this->setContentsMargins(0, 0, 0, 10);
    }

    void addLine(UIButtonsLine* line) {
        this->addLayout(line);
    }

    void addSpace() {
        QSpacerItem *item = new QSpacerItem(1,50, QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->addSpacerItem(item);
    }

};

#endif // UICLAVIER_H
