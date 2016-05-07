#ifndef OPLOGIQUE_H
#define OPLOGIQUE_H
#include "operateur.h"
#include "ltnumerique.h"

//enum EnumType {EGAL, DIFFERENT, INFEGAL, SUPEGAL, INF, SUP, AND};

class OPLogique : public Operateur
{
    static const LTEntier vrai;
    static const LTEntier faux;
    //EnumType type;
public:
    OPLogique(QString val, int a):Operateur(val, a){}
    virtual OPLogique* getChild() {return dynamic_cast<OPLogique*>(this);}
};

class OPEgal : public OPLogique{
public:
    OPEgal():OPLogique("=", 2){}
    virtual OPEgal* getChild() {return dynamic_cast<OPEgal*>(this);}
};

class OPDifferent : public OPLogique{
public:
    OPDifferent():OPLogique("!=", 2){}
    virtual OPDifferent* getChild() {return dynamic_cast<OPDifferent*>(this);}
};

class OPInferieurEgal: public OPLogique{
public:
    OPInferieurEgal():OPLogique("<=", 2){}
    virtual OPInferieurEgal* getChild() {return dynamic_cast<OPInferieurEgal*>(this);}
};

class OPInferieur: public OPLogique{
public:
    OPInferieur():OPLogique("<", 2){}
    virtual OPInferieur* getChild() {return dynamic_cast<OPInferieur*>(this);}
};

class OPSuperieurEgal : public OPLogique{
public:
    OPSuperieurEgal():OPLogique(">=", 2){}
    virtual OPSuperieurEgal* getChild() {return dynamic_cast<OPSuperieurEgal*>(this);}
};

class OPSuperieur : public OPLogique{
public:
    OPSuperieur():OPLogique(">", 2){}
    virtual OPSuperieur* getChild() {return dynamic_cast<OPSuperieur*>(this);}
};

class OPAnd : public OPLogique{
public:
    OPAnd():OPLogique("AND", 2){}
    virtual OPAnd* getChild() {return dynamic_cast<OPAnd*>(this);}
};

class OPOr : public OPLogique{
public:
    OPOr():OPLogique("OR", 2){}
    virtual OPOr* getChild() {return dynamic_cast<OPOr*>(this);}
};

class OPNot : public OPLogique{
public:
    OPNot():OPLogique("NOT", 1){}
    virtual OPNot* getChild() {return dynamic_cast<OPNot*>(this);}
};

#endif // OPLOGIQUE_H
