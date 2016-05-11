#ifndef LITTERALE_H
#define LITTERALE_H
#include "operande.h"
#include <QString>

class Litterale : virtual public Operande
{
public:
    Litterale();
    virtual Litterale* getChild(){return dynamic_cast<Litterale*>(this);}
    virtual ~Litterale() {}
    virtual const QString getText() const {}
};

#endif // LITTERALE_H
