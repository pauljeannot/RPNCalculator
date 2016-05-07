#include "uipileview.h"

void UIPileView::addItem(QTableWidgetItem* item) {

    int newRow = this->rowCount();
    this->insertRow(newRow);

    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    this->setItem(newRow, 0, item);
    items.append(item);

    QStringList liste;
    for(unsigned int i=items.count(); i > 0 ; i--)
    {
        QString str = QString::number(i);
        str+= " :";

        liste << str;
    }
    this->setVerticalHeaderLabels(liste);
}
