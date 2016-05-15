#ifndef LTSANSEXPRESSION_H
#define LTSANSEXPRESSION_H
#include "litterale.h"
#include "opnum_ltsansexpression.h"

class LTSansExpression : public OPNum_LTSansExpression, public Litterale
{
public:

    //======================================================
    // Basic methods
    //======================================================

    LTSansExpression() {

    }

    virtual ~LTSansExpression() {

    }

    //======================================================
    // Virtual methods
    //======================================================

};

#endif // LTSANSEXPRESSION_H
