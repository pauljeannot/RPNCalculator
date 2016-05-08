#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "operande.h"
#include <QString>
#include <iostream>

class Operateur : virtual public Operande
{
    QString value;
    int arite;
public:
    Operateur(QString val, int a):value(val), arite(a){}
    virtual Operateur* getChild() {return dynamic_cast<Operateur*>(this);}
    virtual void afficher() { std::cout << value.toStdString() << std::endl; }
};

#endif // OPERATEUR_H
