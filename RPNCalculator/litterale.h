#ifndef LITTERALE_H
#define LITTERALE_H
#include "operande.h"
#include <QString>
#include <IOStream>

class Litterale : virtual public Operande
{
public:

    //======================================================
    // Basic methods
    //======================================================

    Litterale() {

    }

    virtual ~Litterale() {

    }

    //======================================================
    // Virtual methods
    //======================================================

};

#endif // LITTERALE_H
