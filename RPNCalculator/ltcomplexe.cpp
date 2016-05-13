#include "ltcomplexe.h"

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
