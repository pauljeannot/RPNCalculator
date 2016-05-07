#ifndef UIPILEVIEW_H
#define UIPILEVIEW_H


#include <QTableWidget>
#include <QHeaderView>
#include <QScrollBar>
#include "controller.h"

class UIPileView : public QTableWidget
{
    QList<QTableWidgetItem*> items;

public:
    UIPileView():QTableWidget(0,1) {
        this->horizontalHeader()->setStretchLastSection(true);
        this->horizontalHeader()->setSectionHidden(0, false);
        this->verticalHeader()->setStretchLastSection(false);
        this->verticalScrollBar()->setDisabled(false);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        this->setEditTriggers(QAbstractItemView::NoEditTriggers);

        QHeaderView* header = this->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);

        // Rendre invisible le header horizontal :
        this->horizontalHeader()->setVisible(false);

        Controller& ctl = Controller::getInstance();

        for(unsigned int i=0; i < ctl.settingNbLines(); i++)
        {
            this->addItem(new QTableWidgetItem(QString::number(i)));
        }
    }

    void addItem(QTableWidgetItem* item);

    ~UIPileView() {
        QList<QTableWidgetItem*>::iterator j;
        for (j = items.begin(); j != items.end(); ++j)
        {
            delete *j;
        }
    }
};

#endif // UIPILEVIEW_H


