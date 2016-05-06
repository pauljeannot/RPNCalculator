#ifndef OPERANDEFACTORY_H
#define OPERANDEFACTORY_H
#include "operande.h"
#include "ltnumerique.h"
#include <QString>

class OperandeFactory{
 public:
     static QList<LTNumerique*> NewOperande(const QString& description);
 };

#endif // OPERANDEFACTORY_H
