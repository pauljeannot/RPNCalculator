#include "ltnumerique.h"
#include "ltnombre.h"

//===============================================================================================
//
//                              LTNumerique
//
//===============================================================================================

//======================================================
// Virtual methods
//======================================================

void LTNumerique::afficher() const {

}

QString LTNumerique::getText() const {

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
    std::cout << "entier" << value << std::endl;
    return QString::number(value);
}

//======================================================
// Operator methods
//======================================================

LTNombre* LTEntier::operator+(LTNombre* p) {
std::cout << "LTEntier" << std::endl;

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        this->value += e->getValue();
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
    std::cout << "ra "<< QString(QString::number(E1) + getSeparator() + QString::number(E2)).toStdString() << std::endl;
    return QString(QString::number(E1) + getSeparator() + QString::number(E2));
}

//======================================================
// Operator methods
//======================================================

LTRationnelle* LTRationnelle::operator--() {
    this->E1 = -E1;
    return this;
}

LTNombre* LTRationnelle::operator+(LTNombre* p) {
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
    std::cout  << "reel" << value << std::endl;
    return QString::number(this->getValue());
}

//======================================================
// Operator methods
//======================================================

LTReelle* LTReelle::operator--() {
    this->value = -this->value;
    return this;
}

LTNombre* LTReelle::operator+(LTNombre* p) {
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
