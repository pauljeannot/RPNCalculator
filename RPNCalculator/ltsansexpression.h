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

    virtual LTSansExpression* clone() const = 0;

};

#endif // LTSANSEXPRESSION_H
