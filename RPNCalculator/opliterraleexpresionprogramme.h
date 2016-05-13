#ifndef OPLITERRALEEXPRESION_H
#define OPLITERRALEEXPRESION_H
#include "operateur.h"

class OPLiterraleExpresionProgramme : public Operateur
{
public:
    OPLiterraleExpresionProgramme(QString val, int a):Operateur(val, a){}
    virtual OPLiterraleExpresionProgramme* getChild() {return dynamic_cast<OPLiterraleExpresionProgramme*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est unaire et nécessite 1 seule litterale.");
    }
};


class OPEval : public OPLiterraleExpresionProgramme
{
public:
    OPEval():OPLiterraleExpresionProgramme("EVAL", 1){}
    virtual OPEval* getChild() {return dynamic_cast<OPEval*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est unaire et nécessite 1 seule litterale.");
    }
};

class OPEdit : public OPLiterraleExpresionProgramme
{
public:
    OPEdit():OPLiterraleExpresionProgramme("EDIT", 1){}
    virtual OPLiterraleExpresionProgramme* getChild() {return dynamic_cast<OPEdit*>(this);}

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est unaire et nécessite 1 seule litterale.");
    }
};
#endif // OPLITERRALEEXPRESION_H
