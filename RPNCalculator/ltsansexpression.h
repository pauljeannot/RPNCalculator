#ifndef LTSANSEXPRESSION_H
#define LTSANSEXPRESSION_H
#include "litterale.h"
#include "opnum_ltsansexpression.h"

class LTSansExpression : public OPNum_LTSansExpression, public Litterale
{
public:
    LTSansExpression();
    virtual LTSansExpression* getChild()=0;
};

#endif // LTSANSEXPRESSION_H
