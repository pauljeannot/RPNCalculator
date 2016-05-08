#ifndef OPLITERRALEEXPRESION_H
#define OPLITERRALEEXPRESION_H
#include "operateur.h"

class OPLiterraleExpresionProgramme : public Operateur
{
public:
    OPLiterraleExpresionProgramme(QString val, int a):Operateur(val, a){}
    virtual OPLiterraleExpresionProgramme* getChild() {return dynamic_cast<OPLiterraleExpresionProgramme*>(this);}
};


class OPEval : public OPLiterraleExpresionProgramme
{
public:
    OPEval():OPLiterraleExpresionProgramme("EVAL", 1){}
    virtual OPEval* getChild() {return dynamic_cast<OPEval*>(this);}
};

class OPEdit : public OPLiterraleExpresionProgramme
{
public:
    OPEdit():OPLiterraleExpresionProgramme("EDIT", 1){}
    virtual OPLiterraleExpresionProgramme* getChild() {return dynamic_cast<OPEdit*>(this);}
};
#endif // OPLITERRALEEXPRESION_H
