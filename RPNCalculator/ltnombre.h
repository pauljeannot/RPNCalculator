#ifndef LTNOMBRE_H
#define LTNOMBRE_H
#include "ltsansexpression.h"

class LTComplexe;
class LTNumerique;
class LTEntier;

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

    virtual LTNombre* clone() const = 0;

    // OPAddition
    virtual LTNombre* operator+(LTNumerique* p) = 0;

    virtual LTComplexe* operator+(LTComplexe* p) = 0;

    virtual LTNombre* operator+(LTNombre* p);

    // OPSoustraction
    virtual LTNombre* operator-(LTNumerique* p) = 0;

    virtual LTComplexe* operator-(LTComplexe* p) = 0;

    virtual LTNombre* operator-(LTNombre* p);

    // OPMultiplication
    virtual LTNombre* operator*(LTNumerique* p) = 0;

    virtual LTComplexe* operator*(LTComplexe* p) = 0;

    virtual LTNombre* operator*(LTNombre* p);

    // OPDivision
    virtual LTNombre* operator/(LTNumerique* p) = 0;

    virtual LTComplexe* operator/(LTComplexe* p) = 0;

    virtual LTNombre* operator/(LTNombre* p);

    // OPEgal
    friend bool operator==(LTNombre& l1, LTNombre& l2);
};


#endif // LTNOMBRE_H
