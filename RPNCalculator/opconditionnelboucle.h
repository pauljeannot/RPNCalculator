#ifndef OPCONDITIONNELBOUCLE_H
#define OPCONDITIONNELBOUCLE_H
#include "operateur.h"

/*!
 * \brief Opérateur conditionnel boucle
 */
class OPConditionnelBoucle : public Operateur
{
public:
    /*!
     * \brief OPConditionnelBoucle
     * \param val Valeur textuelle de l'opérateur
     * \param a Arité
     */
    OPConditionnelBoucle(QString val, int a):Operateur(val, a){}

    virtual OPConditionnelBoucle* clone() const = 0;

    virtual Litterale* compute() = 0;

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;

};

/*!
 * \brief Opérateur IFT
 */
class OPIft : public OPConditionnelBoucle
{
public:
    /*!
     * \brief Constructeur
     */
    OPIft():OPConditionnelBoucle("IFT", 2){}

    virtual OPIft* clone() const {
        return new OPIft();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};
#endif // OPCONDITIONNELBOUCLE_H
