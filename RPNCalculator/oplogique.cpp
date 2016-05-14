#include "oplogique.h"

const LTEntier OPLogique::trueValue = LTEntier(1);
const LTEntier OPLogique::falseValue= LTEntier(0);

//=================================================================
//
//                        OPEgal
//
//=================================================================

Litterale* OPEgal::compute(Litterale* l1, Litterale* l2) {
    LTNombre* e1 = dynamic_cast<LTNombre*>(l1);
    LTNombre* e2 = dynamic_cast<LTNombre*>(l2);

    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) == *(e2));

        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
    }

    return OPLogique::falseValue.clone();
}

//=================================================================
//
//                        OPDifferent
//
//=================================================================

Litterale* OPDifferent::compute(Litterale* l1, Litterale* l2) {
    LTNombre* e1 = dynamic_cast<LTNombre*>(l1);
    LTNombre* e2 = dynamic_cast<LTNombre*>(l2);

    // Si ils sont égaux, on renvoie faux
    // On s'appuie sur l'opérateur OPEgal
    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) == *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::falseValue.clone();
    }

    return OPLogique::trueValue.clone();
}
