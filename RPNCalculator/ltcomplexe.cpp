#include "ltcomplexe.h"
#include "oplogique.h"

void LTComplexe::afficher() const {
    std::cout << getText().toStdString() << std::endl;
}

QString LTComplexe::getText() const {
    return QString(Re->getText() + separateur + Im->getText());
}

LTComplexe* LTComplexe::clone() const {
    return new LTComplexe(*this);
}

//======================================================
// Operator methods
//======================================================

// OPAddition
LTNombre* LTComplexe::operator+(LTNumerique* p) {

    LTNumerique* num2 =  *(this->Re) + p;
    LTNumerique* im = Im;
    return new LTComplexe(num2, im);
}

LTComplexe* LTComplexe::operator+(LTComplexe* p) {
    LTComplexe* cpy = this->clone();
    cpy->Re = *(cpy->Re) + p->getRe();
    cpy->Im = *(cpy->Im) + p->getIm();
    return cpy;
}

// OPSoustraction
LTNombre* LTComplexe::operator-(LTNumerique* p) {
    LTComplexe* cpy = this->clone();
    LTNumerique* num2 =  *(cpy->Re) - p;
    LTNumerique* im = Im;
    return new LTComplexe(num2, im);
}

LTComplexe* LTComplexe::operator-(LTComplexe* p) {
    LTComplexe* cpy = this->clone();
    cpy->Re = *(cpy->Re) - p->getRe();
    cpy->Im = *(cpy->Im) - p->getIm();
    return cpy;
}

// OPMultiplier
LTNombre* LTComplexe::operator*(LTNumerique* p) {
    LTComplexe* cpy = this->clone();
    LTNumerique* num2 =  *(cpy->Re) * p;
    LTNumerique* num3 = *(cpy->Im) * p;

    return new LTComplexe(num2, num3);
}

LTComplexe* LTComplexe::operator*(LTComplexe* p) {
    LTComplexe* cpy = this->clone();
    LTNumerique* re2 = *(*(cpy->Re) * p->getRe()) - (*(cpy->Im) * p->getIm());
    LTNumerique* im2 = *(*(cpy->Re) * p->getIm()) + (*(cpy->Im) * p->getRe());

    cpy->setRe(re2);
    cpy->setIm(im2);
    return cpy;
}


// OPDiviser
LTNombre* LTComplexe::operator/(LTNumerique* p) {
    LTComplexe* cpy = this->clone();
    LTNumerique* num2 =  *(cpy->Re) / p;
    LTNumerique* num3 = *(cpy->Im) / p;
    return new LTComplexe(num2, num3);
}

LTComplexe* LTComplexe::operator/(LTComplexe* p) {
    LTComplexe* cpy = this->clone();
    LTNumerique* numA = *(*(cpy->Re) * p->getRe()) + (*(cpy->Im) * p->getIm());
    LTNumerique* numB = *(*(p->getRe()) * cpy->Im) - (*(cpy->Re) * p->getIm());
    LTNumerique* den = *(*(p->getRe()) * p->getRe()) + (*(p->getIm()) * p->getIm());
    LTNumerique* re = *numA / den;
    LTNumerique* im = *numB / den;
    return new LTComplexe(re, im);
}

// OPEgal
bool operator== (LTComplexe& l1, LTComplexe& l2)
{
    if(*(l1.getRe()) == *(l2.getRe()) && *(l1.getIm()) == *(l2.getIm()))
        return OPLogique::trueValue.getValue();
    else
        return OPLogique::falseValue.getValue();
}

bool operator== (LTComplexe& l1, LTNumerique& l2)
{
    if(*(l1.getRe()) == l2) {}
    else
        return OPLogique::falseValue.getValue();

    LTEntier* e = dynamic_cast<LTEntier*>(l1.getIm());
    LTReelle* re = dynamic_cast<LTReelle*>(l1.getIm());
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(l1.getIm());

    if (e != nullptr) {
        if (*e == *(LTEntier::zero.clone()))
            return OPLogique::trueValue.getValue();
    }
    else if (re != nullptr) {
        if (*re == *(LTReelle::zero.clone()))
            return OPLogique::trueValue.getValue();
    }
    else if (ra != nullptr) {
        if (*ra == *(LTRationnelle::zero.clone()))
            return OPLogique::trueValue.getValue();
    }
}

// OPDifferent
bool operator!= (LTComplexe& l1, LTComplexe& l2)
{
    return !(l1 == l2);
}

bool operator!= (LTComplexe& l1, LTNumerique& l2)
{
    return !(l1 == l2);
}
