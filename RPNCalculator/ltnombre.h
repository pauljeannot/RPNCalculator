#ifndef LTNOMBRE_H
#define LTNOMBRE_H
#include "ltsansexpression.h"

class LTComplexe;
class LTNumerique;
class LTEntier;

//! Classe LTNombre abstraite
class LTNombre : public LTSansExpression
{
public:

    //======================================================
    // Basic methods
    //======================================================
    //! Constructeur
    LTNombre() {

    }
    //! Destructeur
    virtual ~LTNombre() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual QString getText() const = 0;

    virtual void afficher() const = 0;

    virtual LTNombre* clone() const = 0;

    virtual LTNombre* simplifier() = 0;

    // OPAddition
    //! Addition entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator+(LTNumerique* p) = 0;
    //! Addition entre un LTComplexe et un LTComplexe
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator+(LTComplexe* p)  = 0;

    //! Addition entre un LTNombre et un LTNombre
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    virtual LTNombre* operator+(LTNombre* p);



    // OPSoustraction
    //! Soustraction entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator-(LTNumerique* p) = 0;
    //! Soustraction entre un LTComplexe et un LTComplexe
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator-(LTComplexe* p) = 0;

    //! Soustraction entre un LTNombre et un LTNombre
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    virtual LTNombre* operator-(LTNombre* p);


    // OPMultiplication
    //! Multiplication entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator*(LTNumerique* p) = 0;
    //! Multiplication entre un LTComplexe et un LTComplexe
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator*(LTComplexe* p) = 0;

    //! Multiplication entre un LTNombre et un LTNombre
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    virtual LTNombre* operator*(LTNombre* p);


    // OPDivision
    //! Division entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator/(LTNumerique* p) = 0;
    //! Division entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator/(LTComplexe* p) = 0;

    //! Division entre un LTNombre et un LTNombre
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
     virtual LTNombre* operator/(LTNombre* p);


    // OPEgal
    //! Egalité entre un LTComplexe et un LTComplexe
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    friend bool operator==(LTComplexe& l1, LTComplexe& l2);
    //! Egalité entre un LTComplexe et un LTNumerique
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    friend bool operator==(LTComplexe& l1, LTNumerique& l2);

    //! Egalité entre un LTNombre et un LTNombre
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    friend bool operator==(LTNombre& l1, LTNombre& l2);



    // OPDifferent
    //! Différence entre un LTComplexe et un LTComplexe
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    friend bool operator!=(LTComplexe& l1, LTComplexe& l2);
    //! Différence entre un LTComplexe et un LTNumerique
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    friend bool operator!=(LTComplexe& l1, LTNumerique& l2);

    //! Différence entre un LTNombre et un LTNombre
    /*!
      \param l1 Premier paramètre, qui sera modifié
      \param l2 Second paramètre qui sera ajouté au premier
      \return Booléen de confirmation pour la création
    */
    friend bool operator!=(LTNombre& l1, LTNombre& l2);

};


#endif // LTNOMBRE_H
