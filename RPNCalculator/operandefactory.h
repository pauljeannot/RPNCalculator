#ifndef OPERANDEFACTORY_H
#define OPERANDEFACTORY_H
#include "operande.h"
#include "ltnumerique.h"
#include "opnum_ltsansexpression.h"
#include <QString>

class OperandeFactory{
 public:
     static Operande* NewOperande(const QString& str);
     static OPNum_LTSansExpression* NewOPNum_LTSansExpression(const QString& str);
     static bool isOperator(QString C);
     static bool isLitterale(const QString& symbol);
     static int operatorWeight(QString arg);
     static int operateurPrioritaire(QString a, QString b);
     static QString infixToPostfix(QString expr);
     static QString addSpace(QString str);
 };

#endif // OPERANDEFACTORY_H
