#ifndef LTNOMBRE_H
#define LTNOMBRE_H
#include "ltsansexpression.h"


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

    virtual LTNombre* operator+(LTNombre* p) = 0;

};

#endif // LTNOMBRE_H
