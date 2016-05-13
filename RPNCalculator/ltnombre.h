#ifndef LTNOMBRE_H
#define LTNOMBRE_H
#include "ltsansexpression.h"

class LTComplexe;
class LTNumerique;

class LTNombre : public LTSansExpression
{
public:

    //======================================================
    // Basic methods
    //======================================================

    LTNombre() {

    }

    virtual ~LTNombre() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual LTNombre* operator+(LTNumerique* p) = 0;

    virtual LTComplexe* operator+(LTComplexe* p) = 0;

    virtual LTNombre* operator+(LTNombre* p);

};

#endif // LTNOMBRE_H
