#ifndef OPLITERRALEEXPRESION_H
#define OPLITERRALEEXPRESION_H
#include "operateur.h"

class OPLiterraleExpresion : public Operateur
{
public:
    OPLiterraleExpresion();
};


class OPEval : public OPLiterraleExpresion
{
public:
    OPEval();
};
#endif // OPLITERRALEEXPRESION_H
