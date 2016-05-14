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
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur = n'est pas utilisable avec ce type de litterales.");
    }
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
        int res = ((*e1) != *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur != n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPInferieur
//
//=================================================================

Litterale* OPInferieur::compute(Litterale* l1, Litterale* l2) {
    LTNumerique* e1 = dynamic_cast<LTNumerique*>(l1);
    LTNumerique* e2 = dynamic_cast<LTNumerique*>(l2);

    // Si ils sont égaux, on renvoie faux
    // On s'appuie sur l'opérateur OPEgal
    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) < *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur < n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPInferieurEgal
//
//=================================================================

Litterale* OPInferieurEgal::compute(Litterale* l1, Litterale* l2) {
    LTNumerique* e1 = dynamic_cast<LTNumerique*>(l1);
    LTNumerique* e2 = dynamic_cast<LTNumerique*>(l2);

    // Si ils sont égaux, on renvoie faux
    // On s'appuie sur l'opérateur OPEgal
    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) <= *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur <= n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPSuperieur
//
//=================================================================

Litterale* OPSuperieur::compute(Litterale* l1, Litterale* l2) {
    LTNumerique* e1 = dynamic_cast<LTNumerique*>(l1);
    LTNumerique* e2 = dynamic_cast<LTNumerique*>(l2);

    // Si ils sont égaux, on renvoie faux
    // On s'appuie sur l'opérateur OPEgal
    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) > *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur > n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPSuperieurEgal
//
//=================================================================

Litterale* OPSuperieurEgal::compute(Litterale* l1, Litterale* l2) {
    LTNumerique* e1 = dynamic_cast<LTNumerique*>(l1);
    LTNumerique* e2 = dynamic_cast<LTNumerique*>(l2);

    // Si ils sont égaux, on renvoie faux
    // On s'appuie sur l'opérateur OPEgal
    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) >= *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur >= n'est pas utilisable avec ce type de litterales.");
    }
}
