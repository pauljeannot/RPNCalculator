#ifndef LITTERALE_H
#define LITTERALE_H
#include "operande.h"
#include <QString>
#include <IOStream>
#include <QXmlStreamWriter>

class LTNumerique;

//! Classe mère de toutes les litterales (abstraite)
class Litterale : virtual public Operande
{
public:

    //======================================================
    // Basic methods
    //======================================================

    //! Constructeur
    Litterale() {}

    //! Destructeur
    virtual ~Litterale() {}

    //======================================================
    // Virtual methods
    //======================================================

    //! Fonction virtuelle renvoyant une copie de l'instance
    /*!
      \return Nouvelle litterale copiée
    */
    virtual Litterale* clone() const = 0;

    //! Fonction virtuelle simplifiant la litterale actuelle
    /*!
      \return Nouvelle litterale copiée
    */
    virtual Litterale* simplifier() = 0;

    //! Fonction virtuelle renvoyant la litterale sous forme de texte
    /*!
      \return Litterale sous forme de texte
    */
    virtual QString getText() const = 0;

    //! Fonction virtuelle affichant la litterale sur la sortie standart
    virtual void afficher() const = 0;

};

#endif // LITTERALE_H
