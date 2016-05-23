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

    virtual Litterale* simplifier() = 0;

    virtual void write(QXmlStreamWriter& xmlWriter) const = 0;

    virtual LTSansExpression* read(QXmlStreamReader& xmlReader) = 0;

};

#endif // LTSANSEXPRESSION_H
