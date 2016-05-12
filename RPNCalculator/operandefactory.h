#ifndef OPERANDEFACTORY_H
#define OPERANDEFACTORY_H
#include "operande.h"
#include "ltnumerique.h"
#include "opnum_ltsansexpression.h"
#include <QString>
#include <QStringList>

class OperandeFactory{
 public:
     static Operande* NewOperande(const QString& str) throw (ExceptionRationnelle);
     static OPNum_LTSansExpression* NewOPNum_LTSansExpression(const QString& str);
     static bool isOperator(QString C);
     static bool isLitterale(const QString& symbol);
     static int operatorWeight(QString arg);
     static int operateurPrioritaire(QString a, QString b);
     static QString infixToPostfix(QString expr);
     static QString infixToPostfix2(QString S);
 };

#endif // OPERANDEFACTORY_H
