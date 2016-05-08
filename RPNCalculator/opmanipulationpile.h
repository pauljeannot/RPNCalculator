#ifndef OPMANIPULATIONPILE_H
#define OPMANIPULATIONPILE_H
#include "operateur.h"

class OPManipulationPile : public Operateur
{
public:
    OPManipulationPile();
};

class OPDup : public OPManipulationPile
{
public:
    OPDup();
};

class OPDrop : public OPManipulationPile
{
public:
    OPDrop();
};

class OPSwap : public OPManipulationPile
{
public:
    OPSwap();
};

class OPLastOp : public OPManipulationPile
{
public:
    OPLastOp();
};

class OPLastArgs : public OPManipulationPile
{
public:
    OPLastArgs();
};

class OPUndo : public OPManipulationPile
{
public:
    OPUndo();
};

class OPRedo : public OPManipulationPile
{
public:
    OPRedo();
};

class OPClear : public OPManipulationPile
{
public:
    OPClear();
};

#endif // OPMANIPULATIONPILE_H
