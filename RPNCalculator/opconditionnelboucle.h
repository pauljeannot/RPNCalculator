#ifndef OPCONDITIONNELBOUCLE_H
#define OPCONDITIONNELBOUCLE_H
#include "operateur.h"

class OPConditionnelBoucle : public Operateur
{
public:
    OPConditionnelBoucle(QString val, int a):Operateur(val, a){}
    virtual OPConditionnelBoucle* getChild() {
        return dynamic_cast<OPConditionnelBoucle*>(this);
    }
    virtual Litterale* compute(Litterale* l) {}

};

class OPIft : public OPConditionnelBoucle
{
public:
    OPIft():OPConditionnelBoucle("IFT", 2){}
    virtual OPIft* getChild() {
        return dynamic_cast<OPIft*>(this);
    }
    virtual Litterale* compute(Litterale* l) {}

};
#endif // OPCONDITIONNELBOUCLE_H
