#ifndef OPNUMERIQUE_H
#define OPNUMERIQUE_H
#include "operateur.h"
#include "opnum_ltsansexpression.h"


class OPNumerique : public Operateur, public OPNum_LTSansExpression
{
public:
    OPNumerique(QString val, int a):Operateur(val, a){}
    virtual OPNumerique* getChild() {return dynamic_cast<OPNumerique*>(this);}
};

class OPAddition : public OPNumerique {
public:
    OPAddition():OPNumerique("+", 2){}
    virtual OPAddition* getChild() {return dynamic_cast<OPAddition*>(this);}
};

class OPSoustraction : public OPNumerique {
public:
    OPSoustraction():OPNumerique("-", 2){}
    virtual OPSoustraction* getChild() {return dynamic_cast<OPSoustraction*>(this);}
};

class OPMultiplication : public OPNumerique {
public:
    OPMultiplication():OPNumerique("*", 2){}
    virtual OPMultiplication* getChild() {return dynamic_cast<OPMultiplication*>(this);}
};

class OPDivision : public OPNumerique {
public:
    OPDivision():OPNumerique("/", 2){}
    virtual OPDivision* getChild() {return dynamic_cast<OPDivision*>(this);}
};

class OPNumerateur : public OPNumerique {
public:
    OPNumerateur():OPNumerique("NUM", 1){}
    virtual OPNumerateur* getChild() {return dynamic_cast<OPNumerateur*>(this);}
};

class OPDenominateur : public OPNumerique {
public:
    OPDenominateur():OPNumerique("DEN", 1){}
    virtual OPDenominateur* getChild() {return dynamic_cast<OPDenominateur*>(this);}
};

class OPDivisionEntiere : public OPNumerique {
public:
    OPDivisionEntiere():OPNumerique("DIV", 2){}
    virtual OPDivisionEntiere* getChild() {return dynamic_cast<OPDivisionEntiere*>(this);}
};

class OPModulo : public OPNumerique {
public:
    OPModulo():OPNumerique("MOD", 2){}
    virtual OPModulo* getChild() {return dynamic_cast<OPModulo*>(this);}
};

class OPPartieImaginaireComplexe : public OPNumerique {
public:
    OPPartieImaginaireComplexe():OPNumerique("IM", 1){}
    virtual OPPartieImaginaireComplexe* getChild() {return dynamic_cast<OPPartieImaginaireComplexe*>(this);}
};

class OPPartieReelleComplexe : public OPNumerique {
public:
    OPPartieReelleComplexe():OPNumerique("RE", 1){}
    virtual OPPartieReelleComplexe* getChild() {return dynamic_cast<OPPartieReelleComplexe*>(this);}
};

class OPNegation : public OPNumerique {
public:
    OPNegation():OPNumerique("NEG", 1){}
    virtual OPNegation* getChild() {return dynamic_cast<OPNegation*>(this);}
};

class OPComplexe : public OPNumerique {
public:
    OPComplexe():OPNumerique("$", 2){}
    virtual OPComplexe* getChild() {return dynamic_cast<OPComplexe*>(this);}
};
#endif // OPNUMERIQUE_H
