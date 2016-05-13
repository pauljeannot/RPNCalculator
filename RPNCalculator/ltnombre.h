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

    virtual LTNombre* getChild() {
        return dynamic_cast<LTNombre*>(this);
    }

    virtual const LTNombre* zero() const = 0;

    virtual LTNombre* operator+(LTNombre* p) {
        std::cout << "nombre" << std::endl;
    }

};

#endif // LTNOMBRE_H
