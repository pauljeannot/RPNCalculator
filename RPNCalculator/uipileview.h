#ifndef UIPILEVIEW_H
#define UIPILEVIEW_H


#include <QTableWidget>
#include <QHeaderView>
#include <QScrollBar>
#include <QMap>
#include "ltatome.h"
#include "controller.h"
#include "ltatomemanager.h"

/*!
 * \brief Classe UIPileView
 */
class UIPileView : public QTableWidget
{
    /*!
     * \brief Liste d'items
     */
    QList<QTableWidgetItem*> items;

public:
    /*!
     * \brief Constructeur
     */
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
            this->addItem(new QTableWidgetItem(""));
        }

        reloadView();
    }
    /*!
     * \brief Ajoute un item a la liste
     * \param item
     */
    void addItem(QTableWidgetItem* item);

    /*!
     * \brief Destructeur
     */
    ~UIPileView() {
        QList<QTableWidgetItem*>::iterator j;
        for (j = items.begin(); j != items.end(); ++j)
        {
            delete *j;
        }
    }

    /*!
     * \brief Met a jour la liste
     */
    void reloadView(int nbLines = -1);

private:
    /*!
     * \brief Met a jour les labels verticaux
     */
    void refreshHeaderLabels();

};

#endif // UIPILEVIEW_H


