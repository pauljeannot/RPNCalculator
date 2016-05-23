#include "uipileview.h"
#include "ltprogramme.h"
#include "ltexpression.h"

void UIPileView::addItem(QTableWidgetItem* item) {

    int newRow = this->rowCount();
    this->insertRow(newRow);

    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    this->setItem(newRow, 0, item);
    items.append(item);
    this->refreshHeaderLabels();
}

void UIPileView::reloadView(int nbLines) {

    if(nbLines == -1) nbLines = items.size();

    if(nbLines < this->rowCount()) {
        for(int i = this->rowCount()-1; i >= nbLines; i--) {
            this->removeRow(i);
            items.removeAt(i);
        }
    }
    else {        
        for(int i = this->rowCount(); i < nbLines; i++) {
            this->addItem(new QTableWidgetItem(""));
        }
    }

    Controller& ctl = Controller::getInstance();
    QList<const Litterale*> list = ctl.getNFirstLitteralsOnTheStack((unsigned int)nbLines);

    int nb = 0;
    for(unsigned int i=items.size(); i > 0 ; i--)
    {
        if ( nb < list.size()) {

            QString text = list[nb]->getText();
            if (text.size() >= 25) {
                QString finalText = text.left(24) + "...";
                const LTProgramme* prog = dynamic_cast<const LTProgramme*>(list[nb]);
                if (prog != nullptr) finalText += "]";
                const LTExpression* e = dynamic_cast<const LTExpression*>(list[nb]);
                if (e != nullptr) finalText += "'";
                items[i-1]->setText(finalText);
            }
            else {
                items[i-1]->setText(text);
            }
        }
        else {
            items[i-1]->setText("");
        }
        nb++;
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
