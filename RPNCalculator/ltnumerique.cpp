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

LTEntier* LTEntier::clone() const {
    return new LTEntier(*this);
}

//======================================================
// Operator methods
//======================================================

// OPNeg
LTEntier* LTEntier::operator--() {
    LTEntier* cpy = this->clone();
    cpy->value = -cpy->value;
    return cpy;
}

//OPAddition
LTNumerique* LTEntier::operator+(LTNumerique* p) {

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTEntier* cpy = this->clone();
        cpy->value = cpy->value + e->getValue();
        return cpy;
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

// OPSoustraction
LTNumerique* LTEntier::operator-(LTNumerique* p) {

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTEntier* cpy = this->clone();
        cpy->value = cpy->value - e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        return *(--*(re)) + this;
    }
    else if (ra != nullptr) {
        return *(--*(ra)) + this;
    }
}


LTComplexe* LTEntier::operator-(LTComplexe* p) {
    LTNombre* n = *(p) - this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

//OPMultiplication
LTNumerique* LTEntier::operator*(LTNumerique* p) {

    std::cout << "operator*" << std::endl;
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTEntier* cpy = this->clone();
        cpy->value = cpy->value * e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        return *(re) * this;
    }
    else if (ra != nullptr) {
        return *(ra) * this;
    }
}


LTComplexe* LTEntier::operator*(LTComplexe* p) {
    LTNombre* n = *(p) * this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

//OPDivsion
LTNumerique* LTEntier::operator/(LTNumerique* p) {

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTRationnelle* res = new LTRationnelle(this->value, e->value);
        return res;
    }
    else if (re != nullptr) {
        return *(re) / this;
    }
    else if (ra != nullptr) {
        return *(ra) / this;
    }
}

LTComplexe* LTEntier::operator/(LTComplexe* p) {
    LTNombre* n = *(p) / this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
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

LTRationnelle* LTRationnelle::clone() const {
    return new LTRationnelle(*this);
}

//======================================================
// Operator methods
//======================================================

// OPNeg
LTRationnelle* LTRationnelle::operator--() {
    LTRationnelle* cpy = this->clone();
    cpy->E1 = -E1;
    return cpy;
}

// OPAddition
LTNumerique* LTRationnelle::operator+(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTRationnelle* cpy = this->clone();
        cpy->E1 += e->getValue() * cpy->getE2();
        return cpy;
    }
    else if (re != nullptr) {
        return *(re) + this;
    }
    else if (ra != nullptr) {
        LTRationnelle* cpy = this->clone();
        int tmp = cpy->getE2();
        cpy->E1 *= ra->getE2();
        cpy->E2 *= ra->getE2();
        ra->setE1(ra->getE1() * tmp);
        ra->setE2(ra->getE2() * tmp);
        cpy->E1 += ra->getE1();
        return cpy;
    }
}

LTComplexe* LTRationnelle::operator+(LTComplexe* p) {
    LTNombre* n = *(p) + this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

// OPSoustraction
LTNumerique* LTRationnelle::operator-(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTRationnelle* cpy = this->clone();
        cpy->E1 -= e->getValue() * cpy->getE2();
        return cpy;
    }
    else if (re != nullptr) {
        return *(--*(re)) + this;
    }
    else if (ra != nullptr) {
        LTRationnelle* cpy = this->clone();
        int tmp = cpy->getE2();
        cpy->E1 *= ra->getE2();
        cpy->E2 *= ra->getE2();
        ra->setE1(ra->getE1() * tmp);
        ra->setE2(ra->getE2() * tmp);

        cpy->E1 -= ra->getE1();

        return cpy;
    }
}

LTComplexe* LTRationnelle::operator-(LTComplexe* p) {
    LTNombre* n = *(p) - this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

// OPMultiplication
LTNumerique* LTRationnelle::operator*(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTRationnelle* cpy = this->clone();
        cpy->E1 *= e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        return *(re) * this;
    }
    else if (ra != nullptr) {
        LTRationnelle* cpy = this->clone();
        cpy->setE1(ra->getE1() * cpy->getE1());
        cpy->setE2(ra->getE2() * cpy->getE2());
        return cpy;
    }
}

LTComplexe* LTRationnelle::operator*(LTComplexe* p) {
    LTNombre* n = *(p) * this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

 //OPDivision
LTNumerique* LTRationnelle::operator/(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTRationnelle* cpy = this->clone();
        cpy->E2 *= e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        return *(LTEntier(1) / re) * this;
    }
    else if (ra != nullptr) {
        LTRationnelle* cpy = this->clone();
        int tmp = ra->getE2();
        ra->setE2(ra->getE1());
        ra->setE1(tmp);

        return *(cpy) * ra;
    }
}

LTComplexe* LTRationnelle::operator/(LTComplexe* p) {
    LTNombre* n = *(p) * this;
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

LTReelle* LTReelle::clone() const {
    return new LTReelle(*this);
}

//======================================================
// Operator methods
//======================================================

LTReelle* LTReelle::operator--() {
    LTReelle* cpy = this->clone();
    cpy->value = -cpy->value;
    return cpy;
}

// OPAddition
LTNumerique* LTReelle::operator+(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->value += e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->setValue(cpy->getValue() + re->getValue());
        return cpy;
    }
    else if (ra != nullptr) {
        LTReelle* r = new LTReelle(ra);
        return *(this) + r;
    }
}

LTComplexe* LTReelle::operator+(LTComplexe* p) {
    LTNombre* n = *(p) + this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

// OPSoustraction
LTNumerique* LTReelle::operator-(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->value -= e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->setValue(cpy->getValue() - re->getValue());
        return cpy;
    }
    else if (ra != nullptr) {
        LTReelle* r = new LTReelle(ra);
        return *(--*(this)) + r;
    }
}

LTComplexe* LTReelle::operator-(LTComplexe* p) {
    LTNombre* n = *(p) - this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

// OPMultiplication
LTNumerique* LTReelle::operator*(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->value *= (float)e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->setValue(cpy->getValue() * re->getValue());

        return cpy;
    }
    else if (ra != nullptr) {
        LTReelle* r = new LTReelle(ra);
        return *(this) * r;
    }
}

LTComplexe* LTReelle::operator*(LTComplexe* p) {
    LTNombre* n = *(p) * this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}

 //OPDivision
LTNumerique* LTReelle::operator/(LTNumerique* p) {
    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->value /= (float)e->getValue();
        return cpy;
    }
    else if (re != nullptr) {
        LTReelle* cpy = this->clone();
        cpy->setValue(cpy->getValue() / re->getValue());
        return cpy;
    }
    else if (ra != nullptr) {
        LTReelle* r = new LTReelle(ra);
        return *(this) / r;
    }
}

LTComplexe* LTReelle::operator/(LTComplexe* p) {
    LTNombre* n = *(p) * this;
    LTComplexe* c = dynamic_cast<LTComplexe*>(n);
    return c;
}


