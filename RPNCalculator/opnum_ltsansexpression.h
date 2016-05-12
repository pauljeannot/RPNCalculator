#ifndef OPNUM_LTSANSEXPRESSION_H
#define OPNUM_LTSANSEXPRESSION_H
#include "operande.h"
#include "litterale.h"

class OPNum_LTSansExpression : virtual public Operande
{
public:
    OPNum_LTSansExpression();
    virtual Litterale* compute(Litterale* l) {}
};

#endif // OPNUM_LTSANSEXPRESSION_H
