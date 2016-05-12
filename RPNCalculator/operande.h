#ifndef OPERANDE_H
#define OPERANDE_H

#include <QString>

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

    virtual Operande* getChild() = 0;

    virtual void afficher() const = 0;

    virtual QString getText() const = 0;
};

#endif // OPERANDE_H
