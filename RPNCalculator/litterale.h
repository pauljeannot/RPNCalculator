#ifndef LITTERALE_H
#define LITTERALE_H
#include "operande.h"

class Litterale : virtual public Operande
{
public:
    Litterale();
    virtual Litterale* getChild(){return nullptr;}
    virtual ~Litterale() {}
};

#endif // LITTERALE_H
