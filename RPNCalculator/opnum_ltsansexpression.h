#ifndef OPNUM_LTSANSEXPRESSION_H
#define OPNUM_LTSANSEXPRESSION_H
#include "operande.h"
#include "litterale.h"

class OPNum_LTSansExpression : virtual public Operande
{
public:
    OPNum_LTSansExpression();

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur '' est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur '' est unaire et nécessite 1 seule litterale.");
    }
};

#endif // OPNUM_LTSANSEXPRESSION_H
