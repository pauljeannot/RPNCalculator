#ifndef OPATOME_H
#define OPATOME_H
#include "operateur.h"

/*!
 * \brief Classe des opérateurs pour les atomes
 */
class OPAtome : public Operateur
{
public:

    /*!
     * \brief Constructeur
     * \param val Valeur textuelle de l'opérateur
     * \param a Arité
     */
    OPAtome(QString val, int a):Operateur(val, a){}

    virtual OPAtome* clone() const = 0;

    virtual Litterale* compute() = 0;

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;
};


/*!
 * \brief Opérateur FORGET
 */
class OPForget : public OPAtome
{
public:
    /*!
     * \brief Constructeur
     */
    OPForget():OPAtome("FORGET", 1){}

    virtual OPForget* clone() const {
        return new OPForget();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

/*!
 * \brief Opérateur STO
 */
class OPSto : public OPAtome
{
public:
    /*!
     * \brief Constructeur
     */
    OPSto():OPAtome("STO", 2){}

    virtual OPSto* clone() const {
        return new OPSto();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2);

};

#endif // OPATOME_H
