#ifndef UIPILEVARVIEW_H
#define UIPILEVARVIEW_H


#include <QTableWidget>
#include <QHeaderView>
#include <QScrollBar>
#include "controller.h"

/*!
 * \brief Classe UIPileVarView
 */
class UIPileVarView : public QTableWidget
{
    /*!
     * \brief Liste d'items
     */
    QList<QTableWidgetItem*> items;
    /*!
     * \brief type de variable stockée dans la pile
     */
    QString type;
public:
    /*!
     * \brief Constructeur
     * \param type Type de variable à afficher
     */
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

    /*!
     * \brief Ajoute un item à la liste
     * \param item
     */
    void addItem(QTableWidgetItem* item);

    //! Destructeur
    //! Détruit tous les éléments de la liste
    ~UIPileVarView() {
        QList<QTableWidgetItem*>::iterator j;
        for (j = items.begin(); j != items.end(); ++j)
        {
            delete *j;
        }
    }

    /*!
     * \brief Met a jour la pile en fonction du type de variable et affiche la vue
     * \param type Type de variable à afficher
     */
    void reloadView(const QString& type);

    /*!
     * \brief Supprime tous les éléments de la liste
     */
    void clearAll();

    /*!
     * \brief Retourne le nombre d'éléments de type "type"
     *
     * \param M Tableau associatif des atomes et leurs contenus
     * \param type Type de variable à rechercher
     * \return
     */
    int getTailleVar(QMap<QString, LTAtome*> M, const QString& type);

private:
    /*!
     * \brief Met a jour les labels verticaux
     * \param type Type de variable à prendre en compte
     */
    void refreshHeaderLabels(const QString& type);

};

#endif // UIPILEVARVIEW_H
