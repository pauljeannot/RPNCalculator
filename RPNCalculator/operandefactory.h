#ifndef OPERANDEFACTORY_H
#define OPERANDEFACTORY_H
#include "operande.h"
#include "ltnumerique.h"
#include <QString>
#include <QStringList>

class OperandeFactory{
 public:
     static Operande* NewOperande(const QString& str);
 };

#endif // OPERANDEFACTORY_H
