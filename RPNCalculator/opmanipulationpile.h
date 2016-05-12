#ifndef OPMANIPULATIONPILE_H
#define OPMANIPULATIONPILE_H
#include "operateur.h"

class OPManipulationPile : public Operateur
{
public:
    OPManipulationPile(QString val, int a):Operateur(val, a){}
    virtual OPManipulationPile* getChild() {return dynamic_cast<OPManipulationPile*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPDup : public OPManipulationPile
{
public:
    OPDup():OPManipulationPile("DUP", 1){}
    virtual OPDup* getChild() {return dynamic_cast<OPDup*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPDrop : public OPManipulationPile
{
public:
    OPDrop():OPManipulationPile("DROP", 1){}
    virtual OPDrop* getChild() {return dynamic_cast<OPDrop*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPSwap : public OPManipulationPile
{
public:
    OPSwap():OPManipulationPile("SWAP", 2){}
    virtual OPSwap* getChild() {return dynamic_cast<OPSwap*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPLastOp : public OPManipulationPile
{
public:
    OPLastOp():OPManipulationPile("LASTOP", 0){}
    virtual OPLastOp* getChild() {return dynamic_cast<OPLastOp*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPLastArgs : public OPManipulationPile
{
public:
    OPLastArgs():OPManipulationPile("LASTARGS", 0){}
    virtual OPLastArgs* getChild() {return dynamic_cast<OPLastArgs*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPUndo : public OPManipulationPile
{
public:
    OPUndo():OPManipulationPile("UNDO", 0){}
    virtual OPUndo* getChild() {return dynamic_cast<OPUndo*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPRedo : public OPManipulationPile
{
public:
    OPRedo():OPManipulationPile("REDO", 0){}
    virtual OPRedo* getChild() {return dynamic_cast<OPRedo*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

class OPClear : public OPManipulationPile
{
public:
    OPClear():OPManipulationPile("CLEAR", 0){}
    virtual OPClear* getChild() {return dynamic_cast<OPClear*>(this);}
    virtual Litterale* compute(Litterale* l) {}
};

#endif // OPMANIPULATIONPILE_H
