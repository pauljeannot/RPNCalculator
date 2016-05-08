#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "operande.h"
#include <QString>

class Operateur : public Operande
{
    QString value;
    int arite;
public:
    Operateur(QString val, int a):value(val), arite(a){}
};

#endif // OPERATEUR_H
