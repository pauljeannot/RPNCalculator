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

    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) >= *(e2));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur >= n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPAnd
//
//=================================================================

Litterale* OPAnd::compute(Litterale* l1, Litterale* l2) {

    LTEntier* e1 = dynamic_cast<LTEntier*>(l1);
    LTEntier* e2 = dynamic_cast<LTEntier*>(l2);

    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) && e2);
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur AND n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPOr
//
//=================================================================

Litterale* OPOr::compute(Litterale* l1, Litterale* l2) {

    LTEntier* e1 = dynamic_cast<LTEntier*>(l1);
    LTEntier* e2 = dynamic_cast<LTEntier*>(l2);

    if (e1 != nullptr && e2 != nullptr) {
        int res = ((*e1) || e2);
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur AND n'est pas utilisable avec ce type de litterales.");
    }
}

//=================================================================
//
//                        OPNot
//
//=================================================================

Litterale* OPNot::compute(Litterale* l) {
    LTEntier* e = dynamic_cast<LTEntier*>(l);

    if (e != nullptr) {
        int res = (!(*e));
        if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
        else return OPLogique::falseValue.clone();
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur AND n'est pas utilisable avec ce type de litterales.");
    }
}
