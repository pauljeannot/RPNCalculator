#include "ltatome.h"
#include "ltprogramme.h"

void LTAtome::setPointer(Litterale* l) {

    this->pointer = l;
    LTProgramme* p = dynamic_cast<LTProgramme*>(l);
    if (p != nullptr) {
        this->Nature = IDPROG;
    }

    LTExpression* e = dynamic_cast<LTExpression*>(l);
    if (e != nullptr) {
        this->Nature = IDEXP;
    }

    LTNombre* n = dynamic_cast<LTNombre*>(l);
    if (n != nullptr) {
        this->Nature = IDVAR;
    }
}

LTAtome::EnumNature LTAtome::getNature() const {
    return Nature;
}

Litterale* LTAtome::getPointer() const {
    return pointer;
}

