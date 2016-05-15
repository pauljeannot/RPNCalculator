#include "opnumerique.h"

//=================================================================
//
//                        OPAddition
//
//=================================================================

Litterale* OPAddition::compute(Litterale* l1, Litterale* l2) {

    LTNombre* num1 = dynamic_cast<LTNombre*>(l1);
    LTNombre* num2 = dynamic_cast<LTNombre*>(l2);

    // Si c'est un LTNombre, on applique l'opérateur, sinon on lève une exception
    if (num1 != nullptr && num2 != nullptr) {
        return *(num1) + num2;
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR);
    }
}

//=================================================================
//
//                        OPSoustraction
//
//=================================================================

Litterale* OPSoustraction::compute(Litterale* l1, Litterale* l2) {

    LTNombre* num1 = dynamic_cast<LTNombre*>(l1);
    LTNombre* num2 = dynamic_cast<LTNombre*>(l2);

    // Si c'est un LTNombre, on applique l'opérateur, sinon on lève une exception
    if (num1 != nullptr && num2 != nullptr) {
        return *(num1) - num2;
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR);
    }
}

//=================================================================
//
//                        OPMultiplication
//
//=================================================================

Litterale* OPMultiplication::compute(Litterale* l1, Litterale* l2) {

    LTNombre* num1 = dynamic_cast<LTNombre*>(l1);
    LTNombre* num2 = dynamic_cast<LTNombre*>(l2);

    // Si c'est un LTNombre, on applique l'opérateur, sinon on lève une exception
    if (num1 != nullptr && num2 != nullptr) {
        return *(num1) * num2;
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR);
    }
}

//=================================================================
//
//                        OPDivision
//
//=================================================================

Litterale* OPDivision::compute(Litterale* l1, Litterale* l2) {

    LTNombre* num1 = dynamic_cast<LTNombre*>(l1);
    LTNombre* num2 = dynamic_cast<LTNombre*>(l2);

    // Si c'est un LTNombre, on applique l'opérateur, sinon on lève une exception
    if (num1 != nullptr && num2 != nullptr) {
        return *(num1) / num2;
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR);
    }
}


//=================================================================
//
//                        OPNumerateur
//
//=================================================================

Litterale* OPNumerateur::compute(Litterale* l) {
    LTEntier* e = dynamic_cast<LTEntier*>(l);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(l);

    if (e != nullptr) {
        return l;
    }
    else if (ra != nullptr) {
        return new LTEntier(ra->getE1());
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Impossible de renvoyer le numérateur pour ce type de littérale.");
    }
}

//=================================================================
//
//                        OPDenomerateur
//
//=================================================================

Litterale* OPDenominateur::compute(Litterale* l) {
    LTEntier* e = dynamic_cast<LTEntier*>(l);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(l);

    if (e != nullptr) {
        return new LTEntier(1);
    }
    else if (ra != nullptr) {
        return new LTEntier(ra->getE2());
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Impossible de renvoyer le dénominateur pour ce type de littérale.");
    }
}

//=================================================================
//
//                        OPDivisionEntiere
//
//=================================================================

Litterale* OPDivisionEntiere::compute(Litterale* l1, Litterale* l2) {
    LTEntier* e1 = dynamic_cast<LTEntier*>(l1);
    LTEntier* e2 = dynamic_cast<LTEntier*>(l2);

    if (e1 != nullptr && e2 != nullptr) {
        int res = (int)((float)e1->getValue() / (float)e2->getValue());
        return new LTEntier(res);
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Une division entière ne peut se calculer qu'avec des litterales entières.");
    }
}

//=================================================================
//
//                        OPModulo
//
//=================================================================

Litterale* OPModulo::compute(Litterale* l1, Litterale* l2) {
    LTEntier* e1 = dynamic_cast<LTEntier*>(l1);
    LTEntier* e2 = dynamic_cast<LTEntier*>(l2);

    if (e1 != nullptr && e2 != nullptr) {
        int res = e1->getValue() % e2->getValue();
        return new LTEntier(res);
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Le reste de la division entière ne peut se calculer qu'avec des litterales entières.");
    }
}

//=================================================================
//
//                        OPPartieImaginaireComplexe
//
//=================================================================

Litterale* OPPartieImaginaireComplexe::compute(Litterale* l) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(l);
    LTNumerique* num = dynamic_cast<LTNumerique*>(l);

    if (c != nullptr) {
        return c->getIm()->clone();
    }
    else if (num != nullptr) {
        return new LTEntier(0);
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Impossible de renvoyer la partie imaginaire de ce type de littérale.");
    }
}

//=================================================================
//
//                        OPPartieReelleComplexe
//
//=================================================================

Litterale* OPPartieReelleComplexe::compute(Litterale* l) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(l);
    LTNumerique* num = dynamic_cast<LTNumerique*>(l);

    if (c != nullptr) {
        return c->getRe()->clone();
    }
    else if (num != nullptr) {
        return num;
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Impossible de renvoyer la partie réelle de ce type de littérale.");
    }
}


//=================================================================
//
//                        OPComplexe
//
//=================================================================

    Litterale* OPComplexe::compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    Litterale* OPComplexe::compute(Litterale* l1, Litterale* l2) {
        LTNumerique* num1 = dynamic_cast<LTNumerique*>(l1);
        LTNumerique* num2 = dynamic_cast<LTNumerique*>(l2);
        // Si c'est un LTNumérique, on applique l'opérateur, sinon on lève une exception
        if (num1 != nullptr && num2!= nullptr) {
            return new LTComplexe(num1, num2);
        }
        else {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Un complexe ne peut être créé qu'à partir d'une litterale numérique.");
        }
    }
