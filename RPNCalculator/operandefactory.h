#ifndef OPERANDEFACTORY_H
#define OPERANDEFACTORY_H
#include "operande.h"
#include "ltnumerique.h"
#include "opnum_ltsansexpression.h"
#include <QString>
#include <QStringList>

class OperandeFactory{
 public:
     static Operande* NewOperande(const QString& str);
     static OPNum_LTSansExpression* NewOPNum_LTSansExpression(const QString& str);
     static bool isOperator(QChar C);
     static bool isLitterale(const QString& symbol);
 };

#endif // OPERANDEFACTORY_H
