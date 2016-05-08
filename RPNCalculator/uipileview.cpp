#include "uipileview.h"

void UIPileView::addItem(QTableWidgetItem* item) {

    int newRow = this->rowCount();
    this->insertRow(newRow);

    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    this->setItem(newRow, 0, item);
    items.append(item);
    this->refreshHeaderLabels();
}

void UIPileView::reloadView(int nbLines) {
    if(nbLines < this->rowCount()) {
        for(int i = this->rowCount()-1; i >= nbLines; i--) {
            this->removeRow(i);
            items.removeAt(i);
        }
    }
    else {
        for(int i = this->rowCount(); i < nbLines; i++) {
            this->addItem(new QTableWidgetItem(QString::number(i)));
        }
    }
    this->refreshHeaderLabels();

}

void UIPileView::refreshHeaderLabels() {
    QStringList liste;
    for(unsigned int i=items.count(); i > 0 ; i--)
    {
        QString str = QString::number(i);
        str+= " :";

        liste << str;
    }
    this->setVerticalHeaderLabels(liste);
}
