#ifndef OPLOGIQUE_H
#define OPLOGIQUE_H
#include "operateur.h"
#include "ltnumerique.h"

//=================================================================
//
//                        OPLogique
//
//=================================================================

class OPLogique : public Operateur
{

public:
    static const LTEntier trueValue;
    static const LTEntier falseValue;

    OPLogique(QString val, int a):Operateur(val, a){}

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;
};

//=================================================================
//
//                        OPEgal
//
//=================================================================

class OPEgal : public OPLogique{
public:
    OPEgal():OPLogique("=", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPDifferent
//
//=================================================================

class OPDifferent : public OPLogique{
public:
    OPDifferent():OPLogique("!=", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPInferieurEgal
//
//=================================================================

class OPInferieurEgal: public OPLogique{
public:
    OPInferieurEgal():OPLogique("<=", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPInferieur
//
//=================================================================

class OPInferieur: public OPLogique{
public:
    OPInferieur():OPLogique("<", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPSuperieurEgal
//
//=================================================================

class OPSuperieurEgal : public OPLogique{
public:
    OPSuperieurEgal():OPLogique(">=", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPSuperieur
//
//=================================================================

class OPSuperieur : public OPLogique{
public:
    OPSuperieur():OPLogique(">", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPAnd
//
//=================================================================

class OPAnd : public OPLogique{
public:
    OPAnd():OPLogique("AND", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPOr
//
//=================================================================

class OPOr : public OPLogique{
public:
    OPOr():OPLogique("OR", 2){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

//=================================================================
//
//                        OPNot
//
//=================================================================

class OPNot : public OPLogique{
public:
    OPNot():OPLogique("NOT", 1){}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

#endif // OPLOGIQUE_H
