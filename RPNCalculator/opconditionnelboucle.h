#ifndef OPCONDITIONNELBOUCLE_H
#define OPCONDITIONNELBOUCLE_H
#include "operateur.h"

class OPConditionnelBoucle : public Operateur
{
public:
    OPConditionnelBoucle();
};

class OPIft : public OPConditionnelBoucle
{
public:
    OPIft();
};

#endif // OPCONDITIONNELBOUCLE_H
