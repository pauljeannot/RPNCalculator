#ifndef UIPILEVIEW_H
#define UIPILEVIEW_H


#include <QTableWidget>
#include <QHeaderView>
#include <QScrollBar>

class UIPileView : public QTableWidget
{
    QList<QTableWidgetItem*> items;

public:
    UIPileView():QTableWidget(40,1) {
        this->horizontalHeader()->setStretchLastSection(true);
        this->horizontalHeader()->setSectionHidden(0, false);
        this->verticalHeader()->setStretchLastSection(true);
        this->verticalScrollBar()->setDisabled(false);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        this->setEditTriggers(QAbstractItemView::NoEditTriggers);

        QHeaderView* header = this->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);

        // Rendre invisible le header horizontal :
        this->horizontalHeader()->setVisible(false);

        //Allouer les items :
        for(unsigned int i=0; i < 40; i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem("");
            items.append(item);
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            this->setItem(i, 0, item);
        }
        QStringList liste;
        for(unsigned int i=40; i > 0 ; i--)
        {
            QString str = QString::number(i);
            str+= " :";

            liste << str;
        }
        this->setVerticalHeaderLabels(liste);
    }

//    void addItem(QTableWidgetItem* item) {
//        item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
//        this->setItem(items.count(), 0, item);
//        items.append(item);

//        QStringList liste;
//        for(unsigned int i=items.count(); i > 0 ; i--)
//        {
//            QString str = QString::number(i);
//            str+= " :";

//            liste << str;
//        }
//        this->setVerticalHeaderLabels(liste);
//    }

    ~UIPileView() {
        QList<QTableWidgetItem*>::iterator j;
        for (j = items.begin(); j != items.end(); ++j)
        {
            delete *j;
        }
    }
};

#endif // UIPILEVIEW_H
