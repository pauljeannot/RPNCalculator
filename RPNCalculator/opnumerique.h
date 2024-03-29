#ifndef OPNUMERIQUE_H
#define OPNUMERIQUE_H
#include "operateur.h"
#include "ltnumerique.h"
#include "ltcomplexe.h"
#include "ltexpression.h"
#include "opnum_ltsansexpression.h"

//=================================================================
//
//                        OPNumerique
//
//=================================================================

/*!
 * \brief Classe OPNumerique
 */
class OPNumerique : public Operateur, public OPNum_LTSansExpression
{
public:
    /*!
     * \brief Construteur
     * \param val
     * \param a
     */
    OPNumerique(QString val, int a):Operateur(val, a){}

    virtual OPNumerique* clone() const = 0;

    virtual Litterale* compute() = 0;

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;
};

//=================================================================
//
//                        OPAddition
//
//=================================================================

/*!
 * \brief Classe OPAddition
 */
class OPAddition : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPAddition():OPNumerique("+", 2){}

    //=================================================================
    //                        Méthodes virtuelles
    //=================================================================

    virtual OPAddition* clone() const {
        return new OPAddition();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '+' est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPSoustraction
//
//=================================================================
/*!
 * \brief Classe OPSoustraction
 */
class OPSoustraction : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPSoustraction():OPNumerique("-", 2){}

    virtual OPSoustraction* clone() const {
        return new OPSoustraction();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPMultiplication
//
//=================================================================

/*!
 * \brief Classe OPMultiplication
 */
class OPMultiplication : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPMultiplication():OPNumerique("*", 2){}

    virtual OPMultiplication* clone() const {
        return new OPMultiplication();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPDivision
//
//=================================================================
/*!
 * \brief Classe OPDivision
 */
class OPDivision : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPDivision():OPNumerique("/", 2){}

    virtual OPDivision* clone() const {
        return new OPDivision();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPNumerateur
//
//=================================================================
/*!
 * \brief Classe OPNumerateur
 */
class OPNumerateur : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPNumerateur():OPNumerique("NUM", 1){}

    virtual OPNumerateur* clone() const {
        return new OPNumerateur();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPDenominateur
//
//=================================================================
/*!
 * \brief Classe OPDenominateur
 */
class OPDenominateur : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPDenominateur():OPNumerique("DEN", 1){}

    virtual OPDenominateur* clone() const {
        return new OPDenominateur();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPDivisionEntiere
//
//=================================================================
/*!
 * \brief Classe OPDivisionEntiere
 */
class OPDivisionEntiere : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPDivisionEntiere():OPNumerique("DIV", 2){}

    virtual OPDivisionEntiere* clone() const {
        return new OPDivisionEntiere();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPModulo
//
//=================================================================
/*!
 * \brief Classe OPModulo
 */
class OPModulo : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPModulo():OPNumerique("MOD", 2){}

    virtual OPModulo* clone() const {
        return new OPModulo();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPPartieImaginaireComplexe
//
//=================================================================
/*!
 * \brief Classe OPPartieImaginaireComplexe
 */
class OPPartieImaginaireComplexe : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPPartieImaginaireComplexe():OPNumerique("IM", 1){}

    virtual OPPartieImaginaireComplexe* clone() const {
        return new OPPartieImaginaireComplexe();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPPartieReelleComplexe
//
//=================================================================
/*!
 * \brief Classe OPPartieReelleComplexe
 */
class OPPartieReelleComplexe : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPPartieReelleComplexe():OPNumerique("RE", 1){}

    virtual OPPartieReelleComplexe* clone() const {
        return new OPPartieReelleComplexe();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPNegation
//
//=================================================================
/*!
 * \brief Classe OPNegation
 */
class OPNegation : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPNegation():OPNumerique("NEG", 1){}

    //=================================================================
    //                        Méthodes virtuelles
    //=================================================================

    virtual OPNegation* clone() const {
        return new OPNegation();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        LTNumerique* num = dynamic_cast<LTNumerique*>(l);
        // Si c'est un LTNumérique, on applique l'opérateur, sinon on lève une exception
        if (num != nullptr) {
            return --*(num);
        }
        else {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Impossible d'appliquer l'opérateur DIV sur cette litterale");
        }
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }

};

//=================================================================
//
//                        OPComplexe
//
//=================================================================
/*!
 * \brief Classe OPComplexe
 */
class OPComplexe : public OPNumerique {
public:
    /*!
     * \brief Constructeur
     */
    OPComplexe():OPNumerique("$", 2){}

    virtual OPComplexe* clone() const {
        return new OPComplexe();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }

    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};
#endif // OPNUMERIQUE_H
