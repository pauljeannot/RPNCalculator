#ifndef LITTERALE_H
#define LITTERALE_H
#include "operande.h"

class Litterale : public Operande
{
public:
    Litterale();
    virtual Litterale* getChild() = 0;
};

#endif // LITTERALE_H
