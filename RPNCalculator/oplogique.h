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

    virtual OPLogique* clone() const = 0;

    virtual Litterale* compute() = 0;

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

    virtual OPEgal* clone() const {
        return new OPEgal();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
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

    virtual OPDifferent* clone() const {
        return new OPDifferent();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPInferieurEgal
//
//=================================================================

class OPInferieurEgal: public OPLogique{
public:
    OPInferieurEgal():OPLogique("<=", 2){}

    virtual OPInferieurEgal* clone() const {
        return new OPInferieurEgal();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPInferieur
//
//=================================================================

class OPInferieur: public OPLogique{
public:
    OPInferieur():OPLogique("<", 2){}

    virtual OPInferieur* clone() const {
        return new OPInferieur();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPSuperieurEgal
//
//=================================================================

class OPSuperieurEgal : public OPLogique{
public:
    OPSuperieurEgal():OPLogique(">=", 2){}

    virtual OPSuperieurEgal* clone() const {
        return new OPSuperieurEgal();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPSuperieur
//
//=================================================================

class OPSuperieur : public OPLogique{
public:
    OPSuperieur():OPLogique(">", 2){}

    virtual OPSuperieur* clone() const {
        return new OPSuperieur();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPAnd
//
//=================================================================

class OPAnd : public OPLogique{
public:
    OPAnd():OPLogique("AND", 2){}

    virtual OPAnd* clone() const {
        return new OPAnd();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPOr
//
//=================================================================

class OPOr : public OPLogique{
public:
    OPOr():OPLogique("OR", 2){}

    virtual OPOr* clone() const {
        return new OPOr();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

//=================================================================
//
//                        OPNot
//
//=================================================================

class OPNot : public OPLogique{
public:
    OPNot():OPLogique("NOT", 1){}

    virtual OPNot* clone() const {
        return new OPNot();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

#endif // OPLOGIQUE_H
