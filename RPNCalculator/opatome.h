#ifndef OPATOME_H
#define OPATOME_H
#include "operateur.h"

class OPAtome : public Operateur
{
public:
    OPAtome(QString val, int a):Operateur(val, a){}
    virtual OPAtome* getChild() {return dynamic_cast<OPAtome*>(this);}
};


class OPForget : public OPAtome
{
public:
    OPForget():OPAtome("FORGET", 1){}
    virtual OPForget* getChild() {return dynamic_cast<OPForget*>(this);}
};

class OPSto : public OPAtome
{
public:
    OPSto():OPAtome("STO", 1){}
    virtual OPSto* getChild() {return dynamic_cast<OPSto*>(this);}
};

#endif // OPATOME_H
