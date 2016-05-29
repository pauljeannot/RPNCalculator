#ifndef UIPILEVARVIEW_H
#define UIPILEVARVIEW_H


#include <QTableWidget>
#include <QHeaderView>
#include <QScrollBar>
#include "controller.h"

class UIPileVarView : public QTableWidget
{
    QList<QTableWidgetItem*> items;
    QString type;
public:
    UIPileVarView(const QString& type):QTableWidget(0,1), type(type) {
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

        reloadView(type);
    }

    void addItem(QTableWidgetItem* item);

    ~UIPileVarView() {
        QList<QTableWidgetItem*>::iterator j;
        for (j = items.begin(); j != items.end(); ++j)
        {
            delete *j;
        }
    }
    void reloadView(const QString& type);
    void clearAll();
    int getTailleVar(QMap<QString, LTAtome*> M, const QString& type);
    //void setValue(QString Value);

private:
    void refreshHeaderLabels(const QString& type);

};

#endif // UIPILEVARVIEW_H
