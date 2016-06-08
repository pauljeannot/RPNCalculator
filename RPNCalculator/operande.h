#ifndef OPERANDE_H
#define OPERANDE_H

#include <QString>
#include "exception.h"

/*!
 * \brief Classe opérande abstraite
 */
class Operande
{
public:

    //======================================================
    // Basic methods
    //======================================================

    /*!
     * \brief Constructeur
     */
    Operande() {

    }

    /*!
     * \brief Destructeur
     */
    virtual ~Operande() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    //! Fonction virtuelle renvoyant une copie de l'instance
    /*!
      \return Nouvelle litterale copiée
    */
    virtual Operande* clone() const = 0;

    //! Fonction virtuelle renvoyant la litterale sous forme de texte
    /*!
      \return Litterale sous forme de texte
    */
    virtual QString getText() const = 0;

    //! Fonction virtuelle affichant la litterale sur la sortie standart
    virtual void afficher() const = 0;
};

#endif // OPERANDE_H
