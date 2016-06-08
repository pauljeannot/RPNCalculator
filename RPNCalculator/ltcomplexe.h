#ifndef LTCOMPLEXE_H
#define LTCOMPLEXE_H
#include "ltnombre.h"
#include "ltnumerique.h"
#include <QString>


//! Classe gérant les nombres complexes
class LTComplexe : public LTNombre
{
    LTNumerique* Re;
    LTNumerique* Im;
    QString separateur;

public:

    //======================================================
    // Basics methods
    //======================================================

    //! Constructeur
    /*!
      \param r Partie réelle
      \param i Partie imaginaire
    */
    LTComplexe(LTNumerique* r, LTNumerique* i): Re(r), Im(i), separateur("$") {

    }

    //! Constructeur par recopie
    /*!
      \param c Complexe
    */
    LTComplexe(const LTComplexe& c):Re(0), Im(0), separateur("$") {

        LTNumerique* re = c.getRe()->clone();
        LTNumerique* im = c.getIm()->clone();

        this->setRe(re);
        this->setIm(im);
    }

    //! Destructeur
    virtual ~LTComplexe() {

    }

    //======================================================
    // Getters/setters
    //======================================================



    //! Setter pour la partie réelle
    /*!
      \param v LTNumerique représentation la partie réeelle
    */
    void setRe(LTNumerique* v) {
        if(Re != 0) delete(this->Re);
        this->Re = v;
    }

    //! Setter pour la partie imaginaire
    /*!
      \param v LTNumerique représentation la partie imaginaire
    */
    void setIm(LTNumerique* v) {
        if (Im != 0) delete(this->Im);
        this->Im = v;
    }

    //! Getter pour la partie réelle
    /*!
      \return Litterale numérique représentant la partie réelle
    */
    LTNumerique* getRe() const {
        return Re;
    }

    //! Getter pour la partie imaginaire
    /*!
      \return Litterale numérique représentant la partie imaginaire
    */
    LTNumerique* getIm() const {
        return Im;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    virtual LTComplexe* clone() const;

    virtual LTComplexe* simplifier() {
        this->Re = this->Re->simplifier();
        this->Im = this->Im->simplifier();
        return this;
    }

    //======================================================
    // Operator methods
    //======================================================

    // OPAddition
    //! Addition entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator+(LTNumerique* p);
    //! Addition entre un LTComplexe et un LTComplexe
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator+(LTComplexe* p);

    // OPSoustraction
    //! Soustraction entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator-(LTNumerique* p);
    //! Soustraction entre un LTComplexe et un LTComplexe
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator-(LTComplexe* p);

    // OPMultiplication
    //! Multiplication entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator*(LTNumerique* p);
    //! Multiplication entre un LTComplexe et un LTComplexe
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator*(LTComplexe* p);

    // OPDivision
    //! Division entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTNombre créé
    */
    virtual LTNombre * operator/(LTNumerique* p);
    //! Division entre un LTComplexe et un LTNumerique
    /*!
      \param p Variable à ajouter
      \return LTComplexe créé
    */
    virtual LTComplexe* operator/(LTComplexe* p);

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

};

#endif // LTCOMPLEXE_H
