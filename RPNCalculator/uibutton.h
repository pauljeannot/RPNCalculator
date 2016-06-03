#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QPushButton>
#include <math.h>

/*!
 * \brief Classe UIButton permettant de définir les touches du clavier de la calculatrice.
 */
class UIButton : public QPushButton
{
    //! QString représentant le texte à afficher sur le bouton.
    QString value;

public:
    //! Constructeur
    /*!
          \param text Le texte à afficher.
          \param width La largeur du bouton qui est, par défaut, éguale à 1.
          \param v QString vide par défaut.
        */
    UIButton(QString text, float width = 1, QString v = "");

    //! Fonction permettant de retourner la valeur du bouton.
    /*!
          \param text Le texte à afficher.
          \param width La largeur du bouton qui est, par défaut, éguale à 1.
          \return Une QString
    */
    QString getValue() const { return value; }

public slots:
    //! Permet d'écrire la valeur du bouton dans la ligne de commande lors du clique.
   void hasBeenClicked();

};

#endif // UIBUTTON_H
