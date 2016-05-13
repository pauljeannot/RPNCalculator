#ifndef OPNUMERIQUE_H
#define OPNUMERIQUE_H
#include "operateur.h"
#include "ltnumerique.h"
#include "ltcomplexe.h"
#include "ltexpression.h"
#include "opnum_ltsansexpression.h"

//=================================================================
//
//                        OPNumerique
//
//=================================================================

class OPNumerique : public Operateur, public OPNum_LTSansExpression
{
public:
    OPNumerique(QString val, int a):Operateur(val, a){}
    virtual OPNumerique* getChild() {return dynamic_cast<OPNumerique*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

//=================================================================
//
//                        OPAddition
//
//=================================================================

class OPAddition : public OPNumerique {
public:
    OPAddition():OPNumerique("+", 2){}

    //=================================================================
    //                        Méthodes virtuelles
    //=================================================================

    virtual OPAddition* getChild() {
        return dynamic_cast<OPAddition*>(this);
    }

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '+' est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPSoustraction
//
//=================================================================

class OPSoustraction : public OPNumerique {
public:

    OPSoustraction():OPNumerique("-", 2){}

    virtual OPSoustraction* getChild() {return dynamic_cast<OPSoustraction*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPMultiplication
//
//=================================================================

class OPMultiplication : public OPNumerique {
public:
    OPMultiplication():OPNumerique("*", 2){}
    virtual OPMultiplication* getChild() {return dynamic_cast<OPMultiplication*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPDivision
//
//=================================================================

class OPDivision : public OPNumerique {
public:
    OPDivision():OPNumerique("/", 2){}
    virtual OPDivision* getChild() {return dynamic_cast<OPDivision*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPNumerateur
//
//=================================================================

class OPNumerateur : public OPNumerique {
public:
    OPNumerateur():OPNumerique("NUM", 1){}
    virtual OPNumerateur* getChild() {return dynamic_cast<OPNumerateur*>(this);}

    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPDenominateur
//
//=================================================================

class OPDenominateur : public OPNumerique {
public:
    OPDenominateur():OPNumerique("DEN", 1){}
    virtual OPDenominateur* getChild() {return dynamic_cast<OPDenominateur*>(this);}

    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPDivisionEntiere
//
//=================================================================

class OPDivisionEntiere : public OPNumerique {
public:
    OPDivisionEntiere():OPNumerique("DIV", 2){}
    virtual OPDivisionEntiere* getChild() {return dynamic_cast<OPDivisionEntiere*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPModulo
//
//=================================================================

class OPModulo : public OPNumerique {
public:
    OPModulo():OPNumerique("MOD", 2){}
    virtual OPModulo* getChild() {return dynamic_cast<OPModulo*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPPartieImaginaireComplexe
//
//=================================================================

class OPPartieImaginaireComplexe : public OPNumerique {
public:
    OPPartieImaginaireComplexe():OPNumerique("IM", 1){}
    virtual OPPartieImaginaireComplexe* getChild() {return dynamic_cast<OPPartieImaginaireComplexe*>(this);}

    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPPartieReelleComplexe
//
//=================================================================

class OPPartieReelleComplexe : public OPNumerique {
public:
    OPPartieReelleComplexe():OPNumerique("RE", 1){}
    virtual OPPartieReelleComplexe* getChild() {return dynamic_cast<OPPartieReelleComplexe*>(this);}

    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPNegation
//
//=================================================================

class OPNegation : public OPNumerique {
public:

    OPNegation():OPNumerique("NEG", 1){}

    //=================================================================
    //                        Méthodes virtuelles
    //=================================================================

    virtual OPNegation* getChild() {
        return dynamic_cast<OPNegation*>(this);
    }

    virtual Litterale* compute(Litterale* l) {
        LTNumerique* num = dynamic_cast<LTNumerique*>(l);
        // Si c'est un LTNumérique, on applique l'opérateur, sinon on lève une exception
        if (num != nullptr) {
            return --*(num);
        }
        else {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Impossible d'appliquer l'opérateur DIV sur cette litterale");
        }
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }

};

//=================================================================
//
//                        OPComplexe
//
//=================================================================

class OPComplexe : public OPNumerique {
public:
    OPComplexe():OPNumerique("$", 2){}

    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};
#endif // OPNUMERIQUE_H
