#ifndef OPNUMERIQUE_H
#define OPNUMERIQUE_H
#include "operateur.h"
#include "opnum_ltsansexpression.h"


class OPNumerique : public Operateur, public OPNum_LTSansExpression
{
public:
    OPNumerique();
};

class OPAddition : public OPNumerique {
public:
    OPAddition();
};

class OPSoustraction : public OPNumerique {
public:
    OPSoustraction();
};

class OPMultiplication : public OPNumerique {
public:
    OPMultiplication();
};

class OPDivision : public OPNumerique {
public:
    OPDivision();
};

class OPNumerateur : public OPNumerique {
public:
    OPNumerateur();
};

class OPDenominateur : public OPNumerique {
public:
    OPDenominateur();
};

class OPDivisionEntiere : public OPNumerique {
public:
    OPDivisionEntiere();
};

class OPModulo : public OPNumerique {
public:
    OPModulo();
};

class OPPartieImaginaireComplexe : public OPNumerique {
public:
    OPPartieImaginaireComplexe();
};

class OPPartieReelleComplexe : public OPNumerique {
public:
    OPPartieReelleComplexe();
};

class OPNegation : public OPNumerique {
public:
    OPNegation();
};

class OPComplexe : public OPNumerique {
public:
    OPComplexe();
};
#endif // OPNUMERIQUE_H
