#include "ltnombre.h"
#include "ltcomplexe.h"
#include "oplogique.h"
#include "ltnumerique.h"


// OPAddition
LTNombre* LTNombre::operator+(LTNombre* p) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(p);
    LTNumerique* num = dynamic_cast<LTNumerique*>(p);

    if (c != nullptr) {
       return *(this) + c;
    }
    else if (num != nullptr) {
        return *(this) + num;
    }
}

// OPSoustraction
LTNombre* LTNombre::operator-(LTNombre* p) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(p);
    LTNumerique* num = dynamic_cast<LTNumerique*>(p);

    if (c != nullptr) {
       return *(this) - c;
    }
    else if (num != nullptr) {
        return *(this) - num;
    }
}

// OPMultiplication
LTNombre* LTNombre::operator*(LTNombre* p) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(p);
    LTNumerique* num = dynamic_cast<LTNumerique*>(p);

    if (c != nullptr) {
       return *(this) * c;
    }
    else if (num != nullptr) {
        return *(this) * num;
    }
}

// OPDivision
LTNombre* LTNombre::operator/(LTNombre* p) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(p);
    LTNumerique* num = dynamic_cast<LTNumerique*>(p);

    if (c != nullptr) {
       return *(this) / c;
    }
    else if (num != nullptr) {
        return *(this) / num;
    }
}

// OPEgal
bool operator== (LTNombre& l1, LTNombre& l2)
{
    LTComplexe* c1 = dynamic_cast<LTComplexe*>(&l1);
    LTComplexe* c2 = dynamic_cast<LTComplexe*>(&l2);
    // Si les deux entiers sont égaux
    if (c1 != nullptr && c2 != nullptr) {
        return (*c1 == *c2);
    }

    LTNumerique* n1 = dynamic_cast<LTNumerique*>(&l1);
    LTNumerique* n2 = dynamic_cast<LTNumerique*>(&l2);
    // Si les deux réels sont égaux
    if (n1 != nullptr && n2 != nullptr) {
        return (*n1 == *n2);
    }

    // Si 1 rationnel et un réel
    if (c1 != nullptr && n2 != nullptr) {
        return (*c1 == *n2);
    }
    if (c2 != nullptr && n1 != nullptr) {
        return (*c2 == *n1);
    }

    return OPLogique::falseValue.getValue();
}

// OPDifferent
bool operator!= (LTNombre& l1, LTNombre& l2)
{
    return !(l1 == l2);
}


// OPInferieur
bool operator<(LTNombre& l1, LTNombre& l2)
{
    LTComplexe* c1 = dynamic_cast<LTComplexe*>(&l1);
    LTComplexe* c2 = dynamic_cast<LTComplexe*>(&l2);
    // Si les deux entiers sont égaux
    if (c1 != nullptr && c2 != nullptr) {
        return (*c1 < *c2);
    }

    LTNumerique* n1 = dynamic_cast<LTNumerique*>(&l1);
    LTNumerique* n2 = dynamic_cast<LTNumerique*>(&l2);
    // Si les deux réels sont égaux
    if (n1 != nullptr && n2 != nullptr) {
        return (*n1 < *n2);
    }

    // Si 1 rationnel et un réel
    if (c1 != nullptr && n2 != nullptr) {
        return (*c1 < *n2);
    }
    if (c2 != nullptr && n1 != nullptr) {
//        return (*c2 >= *n1);
    }

    return OPLogique::falseValue.getValue();
}
