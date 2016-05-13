#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "operande.h"
#include "litterale.h"
#include <QString>
#include <iostream>

class Operateur : virtual public Operande
{
    QString value;
    int arite;
public:
    Operateur(QString val, int a):value(val), arite(a){}
    virtual Operateur* getChild() {return dynamic_cast<Operateur*>(this);}
    virtual void afficher() const { std::cout << value.toStdString() << std::endl; }
    virtual Litterale* compute(Litterale* l) = 0;
    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;

    inline int getArite() { return arite; }
    virtual QString getText() const {
        return value;
    }
};

#endif // OPERATEUR_H
