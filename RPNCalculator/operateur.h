#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "operande.h"
#include "litterale.h"
#include <QString>
#include <iostream>

class Operateur : virtual public Operande
{
protected:
    QString value;
    int arite;
public:
    Operateur(QString val, int a):value(val), arite(a){}
    virtual void afficher() const { std::cout << value.toStdString() << std::endl; }
    virtual Litterale* compute() = 0;
    virtual Litterale* compute(Litterale* l) = 0;
    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;

    inline int getArite() { return arite; }
    virtual QString getText() const { return value; }
    virtual Operateur* clone() const = 0;
};

#endif // OPERATEUR_H
