#ifndef UIBUTTONSLINE_H
#define UIBUTTONSLINE_H

#include <QHBoxLayout>
#include "uibutton.h"

/*!
 * Ligne personnalisée de UIButton
 * \brief Classe UIButtonsLine
 */
class UIButtonsLine : public QHBoxLayout
{    
    //! Liste de UIButton
    QList<UIButton*> buttons;

    //! Liste de séparateurs d'items
    QList<QSpacerItem*> spacers;

public:

    //! Constructeur, règle l'alignement, l'espace entre les boutons et les marges
    /*!
        \param wdg Widget parent
    */
    UIButtonsLine(QWidget* wdg = 0):QHBoxLayout(wdg) {
        this->setAlignment(Qt::AlignLeft);
        this->setSpacing(0);
        this->setContentsMargins(15, 8, 15, 0);
    }

    //! Ajoute un bouton dans la ligne
    /*!
        \param btn Le bouton à insérer
    */
    void addButton(UIButton* btn) {
        QSpacerItem *item = new QSpacerItem(8,1, QSizePolicy::Fixed, QSizePolicy::Fixed);
        buttons.append(btn);
        spacers.append(item);

        this->addSpacerItem(item);
        this->addWidget(btn);
    }

    //! Ajoute un espace dans la ligne
    void addSpace() {
        QSpacerItem *item = new QSpacerItem(50,1, QSizePolicy::Fixed, QSizePolicy::Fixed);
        spacers.append(item);
        this->addSpacerItem(item);
    }

    //! Détruit les éléments de la ligne
    ~UIButtonsLine() {
        QList<UIButton*>::iterator j;
        for (j = buttons.begin(); j != buttons.end(); ++j)
        {
            delete *j;
        }
    }
};

#endif // UIBUTTONSLINE_H
