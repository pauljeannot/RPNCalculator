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
    OPLogique();
};

class OPEgal : public OPLogique{
public:
    OPEgal();
};

class OPDifferent : public OPLogique{
public:
    OPDifferent();
};

class OPInferieurEgal: public OPLogique{
public:
    OPInferieurEgal();
};

class OPInferieur: public OPLogique{
public:
    OPInferieur();
};

class OPSuperieurEgal : public OPLogique{
public:
    OPSuperieurEgal();
};

class OPSuperieur : public OPLogique{
public:
    OPSuperieur();
};

class OPAnd : public OPLogique{
public:
    OPAnd();
};

class OPOr : public OPLogique{
public:
    OPOr();
};

class OPNot : public OPLogique{
public:
    OPNot();
};

#endif // OPLOGIQUE_H
