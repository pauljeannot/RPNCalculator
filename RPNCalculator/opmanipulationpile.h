#ifndef OPMANIPULATIONPILE_H
#define OPMANIPULATIONPILE_H
#include "operateur.h"

class OPManipulationPile : public Operateur
{
public:
    OPManipulationPile(QString val, int a):Operateur(val, a){}
    virtual OPManipulationPile* getChild() {return dynamic_cast<OPManipulationPile*>(this);}
};

class OPDup : public OPManipulationPile
{
public:
    OPDup():OPManipulationPile("DUP", 1){}
    virtual OPDup* getChild() {return dynamic_cast<OPDup*>(this);}
};

class OPDrop : public OPManipulationPile
{
public:
    OPDrop():OPManipulationPile("DROP", 1){}
    virtual OPDrop* getChild() {return dynamic_cast<OPDrop*>(this);}
};

class OPSwap : public OPManipulationPile
{
public:
    OPSwap():OPManipulationPile("SWAP", 2){}
    virtual OPSwap* getChild() {return dynamic_cast<OPSwap*>(this);}
};

class OPLastOp : public OPManipulationPile
{
public:
    OPLastOp():OPManipulationPile("LASTOP", 0){}
    virtual OPLastOp* getChild() {return dynamic_cast<OPLastOp*>(this);}
};

class OPLastArgs : public OPManipulationPile
{
public:
    OPLastArgs():OPManipulationPile("LASTARGS", 0){}
    virtual OPLastArgs* getChild() {return dynamic_cast<OPLastArgs*>(this);}
};

class OPUndo : public OPManipulationPile
{
public:
    OPUndo():OPManipulationPile("UNDO", 0){}
    virtual OPUndo* getChild() {return dynamic_cast<OPUndo*>(this);}
};

class OPRedo : public OPManipulationPile
{
public:
    OPRedo():OPManipulationPile("REDO", 0){}
    virtual OPRedo* getChild() {return dynamic_cast<OPRedo*>(this);}
};

class OPClear : public OPManipulationPile
{
public:
    OPClear():OPManipulationPile("CLEAR", 0){}
    virtual OPClear* getChild() {return dynamic_cast<OPClear*>(this);}
};

#endif // OPMANIPULATIONPILE_H
