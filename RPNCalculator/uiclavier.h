#ifndef UICLAVIER_H
#define UICLAVIER_H

#include <QVBoxLayout>
#include <QList>
#include "uibuttonsline.h"
#include <iostream>

/*!
 * \brief Classe UIKeyboardLayout représentant le layout du clavier de la calculatrice
 */
class UIKeyboardLayout : public QVBoxLayout
{
    //! Liste de lignes de boutons
    QList<UIButtonsLine*> lines;
    //! Liste de séparateurs de ligne
    QList<QSpacerItem*> spacers;

public:

    //! Constructeur, règle l'alignement, l'espace entre les boutons et les marges
    /*!
        \param wdg Widget parent
    */
    UIKeyboardLayout(QWidget* parent = 0):QVBoxLayout(parent) {
        this->setAlignment(Qt::AlignLeft);
        this->setSpacing(0);
        this->setContentsMargins(0, 0, 0, 10);
    }

    //! Ajoute une ligne de boutons dans la ligne
    /*!
        \param line la liste de boutons à insérer
    */
    void addLine(UIButtonsLine* line) {
        lines.append(line);
        this->addLayout(line);
    }

    //! Ajoute un espace sur le clavier
    void addSpace() {
        QSpacerItem *item = new QSpacerItem(1,50, QSizePolicy::Fixed, QSizePolicy::Fixed);
        spacers.append(item);
        this->addSpacerItem(item);
    }

    //! Construit un clavier par défaut
    void constructDefaultKeyboardLayout();

    //! Détruit tous les éléments du clavier
    ~UIKeyboardLayout() {
        QList<UIButtonsLine*>::iterator j;
        for (j = lines.begin(); j != lines.end(); ++j)
        {
            delete (*j);
        }
    }
};

/*!
 * \brief Clavier de la calculatrice
 */
class UIKeyboard : public QWidget
{
public:
    //! Layout du clavier
    UIKeyboardLayout *layout;

    //! Constructeur, initialise le clavier
    /*!
        \param parent Widget parent
    */
    UIKeyboard(QWidget* parent = 0):QWidget(parent), layout(new UIKeyboardLayout()) {
        this->initKeyboard();
    }

    //! Détruit le clavier et son layout
    ~UIKeyboard() {
        delete layout;
    }

    //! Initialise le clavier et le layout
    void initKeyboard() {
        layout->constructDefaultKeyboardLayout();
        this->setLayout(layout);
    }
};


#endif // UICLAVIER_H
