#ifndef OPCONDITIONNELBOUCLE_H
#define OPCONDITIONNELBOUCLE_H
#include "operateur.h"

class OPConditionnelBoucle : public Operateur
{
public:
    OPConditionnelBoucle(QString val, int a):Operateur(val, a){}

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;

};

class OPIft : public OPConditionnelBoucle
{
public:
    OPIft():OPConditionnelBoucle("IFT", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }

};
#endif // OPCONDITIONNELBOUCLE_H
