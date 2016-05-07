#ifndef OPLITERRALEEXPRESION_H
#define OPLITERRALEEXPRESION_H
#include "operateur.h"

class OPLiterraleExpresion : public Operateur
{
public:
    OPLiterraleExpresion(QString val, int a):Operateur(val, a){}
    virtual OPLiterraleExpresion* getChild() {return dynamic_cast<OPLiterraleExpresion*>(this);}
};


class OPEval : public OPLiterraleExpresion
{
public:
    OPEval():OPLiterraleExpresion("EVAL", 1){}
    virtual OPEval* getChild() {return dynamic_cast<OPEval*>(this);}
};
#endif // OPLITERRALEEXPRESION_H
