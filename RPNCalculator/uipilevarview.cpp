#include "uipilevarview.h"

#include "ltprogramme.h"
#include "ltexpression.h"
#include "ltatomemanager.h"

void UIPileVarView::addItem(QTableWidgetItem* item) {

    int newRow = this->rowCount();
    this->insertRow(newRow);

    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    this->setItem(newRow, 0, item);
    items.append(item);
    this->refreshHeaderLabels(type);
}

void UIPileVarView::reloadView(const QString &type) {

    LTAtomeManager& ctl = LTAtomeManager::getInstance();
    QMap<QString, LTAtome*> map = ctl.getDictionnary();

    int nbLines = getTailleVar(map, type);

    while(this->rowCount() > 0)
        this->removeRow(0);
    items.clear();

    int j = 0;

    QMapIterator<QString, LTAtome*> i(map);
    while(i.hasNext()) {
            i.next();

            std::cout << i.value()->getEnumString().toStdString() << std::endl;
            if (i.value()->getEnumString() == type) {
                this->addItem(new QTableWidgetItem(i.value()->getPointer()->getText()));
                j++;
            }
    }
    this->refreshHeaderLabels(type);
}

void UIPileVarView::refreshHeaderLabels(const QString& type) {
    QStringList liste;

    LTAtomeManager& ctl = LTAtomeManager::getInstance();
    QMap<QString, LTAtome*> map = ctl.getDictionnary();

    QMapIterator<QString, LTAtome*> i(map);
    QString str;
    while(i.hasNext()) {
       i.next();
       if (i.value()->getEnumString() == type) {
                str = i.key();

                liste << str;
            }
    }
    this->setVerticalHeaderLabels(liste);
}

void UIPileVarView::clearAll(){
    LTAtomeManager::getInstance().removeAllFromDictionnary();
    while(this->rowCount() > 0)
        this->removeRow(0);
    items.clear();
    XMLManager::getInstance().saveXMLFileAtomeManager();
}

int UIPileVarView::getTailleVar(QMap<QString, LTAtome*> M, const QString& type){
    QMapIterator<QString, LTAtome*> i(M);
    int taille = 0;
    while(i.hasNext()) {
            i.next();
            if (i.value()->getEnumString() == type) {
                taille++;
            }
    }

    return taille;
}
