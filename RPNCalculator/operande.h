#ifndef OPERANDE_H
#define OPERANDE_H

#include <QString>
#include "exception.h"

class Operande
{
public:

    //======================================================
    // Basic methods
    //======================================================

    Operande() {

    }

    virtual ~Operande() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const = 0;

    virtual QString getText() const = 0;
};

#endif // OPERANDE_H
