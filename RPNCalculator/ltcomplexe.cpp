#include "ltcomplexe.h"

//======================================================
// Operator methods
//======================================================

LTNombre* LTComplexe::operator+(LTNumerique* p) {

        LTNumerique* num2 =  *(this->Re) + p;
        LTNumerique* im = Im;
        delete this;
        return new LTComplexe(num2, im);
}

LTComplexe* LTComplexe::operator+(LTComplexe* p) {
    this->Re = *(this->Re) + p->getRe();
    this->Im = *(this->Im) + p->getIm();
    delete p;
    return this;
}
