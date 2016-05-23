#ifndef OPLITERRALEEXPRESION_H
#define OPLITERRALEEXPRESION_H
#include "operateur.h"

class OPLiterraleExpresionProgramme : public Operateur
{
public:
    OPLiterraleExpresionProgramme(QString val, int a):Operateur(val, a){}

    virtual OPLiterraleExpresionProgramme* clone() const = 0;

    virtual Litterale* compute() = 0;

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;
};


class OPEval : public OPLiterraleExpresionProgramme
{
public:
    OPEval():OPLiterraleExpresionProgramme("EVAL", 1){}

    virtual OPEval* clone() const {
        return new OPEval();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

class OPEdit : public OPLiterraleExpresionProgramme
{
public:
    OPEdit():OPLiterraleExpresionProgramme("EDIT", 1){}

    virtual OPEdit* clone() const {
        return new OPEdit();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};
#endif // OPLITERRALEEXPRESION_H
