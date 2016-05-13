#include "ltnumerique.h"
#include "ltcomplexe.h"
#include "ltnombre.h"

//===============================================================================================
//
//                              LTNumerique
//
//===============================================================================================

//======================================================
// Virtual methods
//======================================================



//===============================================================================================
//
//                              LTEntier
//
//===============================================================================================

//======================================================
// Virtual methods
//======================================================

void LTEntier::afficher() const {
    std::cout << getText().toStdString() << std::endl;
}

QString LTEntier::getText() const {
    return QString::number(value);
}

//======================================================
// Operator methods
//======================================================

LTNumerique* LTEntier::operator+(LTNumerique* p) {

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        this->value = this->value + e->getValue();
        this->afficher();
        delete e;
        return this;
    }
    else if (re != nullptr) {
        return *(re) + this;
    }
    else if (ra != nullptr) {
        return *(ra) + this;
    }
}


LTComplexe* LTEntier::operator+(LTComplexe* p) {
    LTNombre* n = *(p) + this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

LTEntier* LTEntier::operator--() {
    this->value = -value;
    return this;
}

//===============================================================================================
//
//                              LTRationnelle
//
//===============================================================================================

//======================================================
// Virtual methods
//======================================================

void LTRationnelle::afficher() const {
    std::cout  <<getText().toStdString() << std::endl;
}

QString LTRationnelle::getText() const {
    return QString(QString::number(E1) + getSeparator() + QString::number(E2));
}

//======================================================
// Operator methods
//======================================================

LTRationnelle* LTRationnelle::operator--() {
    this->E1 = -E1;
    return this;
}

LTNumerique* LTRationnelle::operator+(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        this->E1 += e->getValue() * this->getE2();
        delete e;
        return this;
    }
    else if (re != nullptr) {
        return *(re) + this;
    }
    else if (ra != nullptr) {
        int tmp = this->getE2();
        this->E1 *= ra->getE2();
        this->E2 *= ra->getE2();
        ra->setE1(ra->getE1() * tmp);
        ra->setE2(ra->getE2() * tmp);

        this->E1 += ra->getE1();

        delete ra;
        return this;
    }
}

LTComplexe* LTRationnelle::operator+(LTComplexe* p) {
    LTNombre* n = *(p) + this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}


//===============================================================================================
//
//                              LTReelle
//
//===============================================================================================

//======================================================
// Virtual methods
//======================================================

void LTReelle::afficher() const {
    std::cout<< getText().toStdString() << std::endl;
}

QString LTReelle::getText() const {
    return QString::number(this->getValue());
}

//======================================================
// Operator methods
//======================================================

LTReelle* LTReelle::operator--() {
    this->value = -this->value;
    return this;
}

LTNumerique* LTReelle::operator+(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        this->value += e->getValue();
        delete e;
        return this;
    }
    else if (re != nullptr) {
        this->setValue(this->getValue() + re->getValue());

        delete re;
        return this;
    }
    else if (ra != nullptr) {
        LTReelle* r = new LTReelle(ra);
        delete ra;
        return *(this) + r;
    }
}

LTComplexe* LTReelle::operator+(LTComplexe* p) {
    LTNombre* n = *(p) + this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

