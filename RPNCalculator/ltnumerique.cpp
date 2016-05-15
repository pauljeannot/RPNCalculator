#include "ltnumerique.h"
#include "ltcomplexe.h"
#include "oplogique.h"
#include "ltnombre.h"

const LTEntier LTEntier::zero = LTEntier(0);
const LTRationnelle LTRationnelle::zero = LTRationnelle(0,1);
const LTReelle LTReelle::zero = LTReelle(0.0);

//===============================================================================================
//
//                              LTNumerique
//
//===============================================================================================


//======================================================
// Operator methods
//======================================================

bool operator== (LTNumerique& l1, LTNumerique& l2)
{
    LTEntier* e1 = dynamic_cast<LTEntier*>(&l1);
    LTEntier* e2 = dynamic_cast<LTEntier*>(&l2);
    // Si les deux entiers sont égaux
    if (e1 != nullptr && e2 != nullptr) {
        return (*e1 == *e2);
    }

    LTReelle* re1 = dynamic_cast<LTReelle*>(&l1);
    LTReelle* re2 = dynamic_cast<LTReelle*>(&l2);
    // Si les deux réels sont égaux
    if (re1 != nullptr && re2 != nullptr) {
        return (*re1 == *re2);
    }

    LTRationnelle* ra1 = dynamic_cast<LTRationnelle*>(&l1);
    LTRationnelle* ra2 = dynamic_cast<LTRationnelle*>(&l2);
    // Si les deux rationnels sont égaux
    if (ra1 != nullptr && ra2 != nullptr) {
        return (*ra1 == *ra2);
    }

    if (e1 != nullptr && re2 != nullptr) {
        return (*e1 == *re2);
    }
    if (e1 != nullptr && ra2 != nullptr) {
        return (*e1 == *ra2);
    }
    if (re1 != nullptr && e2 != nullptr) {
        return (*re1 == *e2);
    }
    if (re1 != nullptr && ra2 != nullptr) {
        return (*re1 == *ra2);
    }
    if (ra1 != nullptr && e2 != nullptr) {
        return (*ra1 == *e2);
    }
    if (ra1 != nullptr && re2 != nullptr) {
        return (*ra1 == *re2);
    }

    std::cout << "On ne devrait jamais voir ce message dans la console : erreur opérateur =" << std::endl;

    return OPLogique::falseValue.getValue();
}

// OPDifferent
bool operator!= (LTNumerique& l1, LTNumerique& l2)
{
    return !(l1 == l2);
}

bool operator< (LTNumerique& l1, LTNumerique& l2)
{
    LTEntier* e1 = dynamic_cast<LTEntier*>(&l1);
    LTEntier* e2 = dynamic_cast<LTEntier*>(&l2);
    // Si les deux entiers sont égaux
    if (e1 != nullptr && e2 != nullptr) {
        return (*e1 < *e2);
    }

    LTReelle* re1 = dynamic_cast<LTReelle*>(&l1);
    LTReelle* re2 = dynamic_cast<LTReelle*>(&l2);
    // Si les deux réels sont égaux
    if (re1 != nullptr && re2 != nullptr) {
        return (*re1 < *re2);
    }

    LTRationnelle* ra1 = dynamic_cast<LTRationnelle*>(&l1);
    LTRationnelle* ra2 = dynamic_cast<LTRationnelle*>(&l2);
    // Si les deux rationnels sont égaux
    if (ra1 != nullptr && ra2 != nullptr) {
        return (*ra1 < *ra2);
    }

    if (e1 != nullptr && re2 != nullptr) {
        return (*e1 < *re2);
    }
    if (e1 != nullptr && ra2 != nullptr) {
        return (*e1 < *ra2);
    }
    if (re1 != nullptr && e2 != nullptr) {
        return (*re1 < *e2);
    }
    if (re1 != nullptr && ra2 != nullptr) {
        return (*re1 < *ra2);
    }
    if (ra1 != nullptr && e2 != nullptr) {
        return (*ra1 < *e2);
    }
    if (ra1 != nullptr && re2 != nullptr) {
        return (*ra1 < *re2);
    }

    std::cout << "On ne devrait jamais voir ce message dans la console : erreur opérateur <" << std::endl;

    return OPLogique::falseValue.getValue();
}

// OPInferieurEgal
bool operator<= (LTNumerique& l1, LTNumerique& l2)
{
    return ((l1 < l2) || (l1 == l2));
}

// OPSuperieur
bool operator> (LTNumerique& l1, LTNumerique& l2)
{
    return !(l1 <= l2);
}

// OPSuperieurEgal
bool operator>= (LTNumerique& l1, LTNumerique& l2)
{
    return !(l1 < l2);
}



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

// OPEgal
bool operator== (LTEntier& l1, LTEntier& l2)
{
    if(l1.value == l2.value)
        return OPLogique::trueValue.getValue();
    else
        return OPLogique::falseValue.getValue();
}

bool operator== (LTEntier& l1, LTReelle& l2) {
    LTReelle* re = new LTReelle(l1);
    return (*re == l2);
}

bool operator== (LTEntier& l1, LTRationnelle& l2) {
    LTRationnelle* ra = new LTRationnelle(l1);
    return (*ra == l2);
}

// OPInferieur
bool operator< (LTEntier& l1, LTEntier& l2)
{
    if(l1.getValue() < l2.getValue())
        return OPLogique::trueValue.getValue();
    else
        return OPLogique::falseValue.getValue();
}

bool operator< (LTEntier& l1, LTReelle& l2)
{
    LTReelle* re = new LTReelle(l1);
    return (*re < l2);
}


bool operator< (LTEntier& l1, LTRationnelle& l2)
{
    LTRationnelle* ra = new LTRationnelle(l1);
    return (*ra < l2);
}

//OPAnd
bool LTEntier::operator&&(LTEntier* p) const {
    if (this->getValue() != 0 && p->getValue() != 0) return true;
    else return false;
}

//OPOr
bool LTEntier::operator||(LTEntier* p) const {
    if (this->getValue() != 0 || p->getValue() != 0) return true;
    else return false;
}

//OPNot
bool LTEntier::operator!() const {
    if (this->getValue() != 0) return false;
    else return true;
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

// OPEgal
bool operator== (LTRationnelle& l1, LTRationnelle& l2) {
    LTReelle* re = new LTReelle(&l1);
    LTReelle* re2 = new LTReelle(&l2);

    return (*re == *re2);
}

bool operator== (LTRationnelle& l1, LTEntier& l2) {
    LTRationnelle* ra = new LTRationnelle(l2);
    return (l1 == *ra);
}

bool operator== (LTRationnelle& l1, LTReelle& l2) {
    LTReelle* re = new LTReelle(&l1);
    return (*re == l2);
}

// OPInferieur
bool operator< (LTRationnelle& l1, LTRationnelle& l2) {
    LTReelle* r1 = new LTReelle(&l1);
    LTReelle* r2 = new LTReelle(&l2);
    return (*r1 < *r2);
}

bool operator< (LTRationnelle& l1, LTEntier& l2) {
    LTReelle* r1 = new LTReelle(&l1);
    LTReelle* r2 = new LTReelle(l2);
    return (*r1 < *r2);
}

bool operator< (LTRationnelle& l1, LTReelle& l2) {
    LTReelle* r1 = new LTReelle(&l1);
    return (*r1 < l2);
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

// OPEgal
bool operator== (LTReelle& l1, LTReelle& l2)
{
    if(l1.getValue()== l2.getValue())
        return OPLogique::trueValue.getValue();
    else
        return OPLogique::falseValue.getValue();
}

bool operator== (LTReelle& l1, LTRationnelle& l2)
{
    LTReelle* r = new LTReelle(&l2);
    return (l1 == *r);
}

bool operator== (LTReelle& l1, LTEntier& l2) {
    LTReelle* re = new LTReelle(l2);
    return (l1 == *re);
}

// OPInferieur
bool operator< (LTReelle& l1, LTReelle& l2)
{
    if(l1.getValue() < l2.getValue())
        return OPLogique::trueValue.getValue();
    else
        return OPLogique::falseValue.getValue();
}

bool operator< (LTReelle& l1, LTRationnelle& l2)
{
    LTReelle* r = new LTReelle(&l2);
    return (l1 < *r);
}

bool operator< (LTReelle& l1, LTEntier& l2)
{
    LTReelle* r = new LTReelle(l2);
    return (l1 < *r);
}
