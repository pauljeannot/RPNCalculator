#ifndef PARSEUR_H
#define PARSEUR_H
#include "exception.h"
#include "operande.h"
#include "opnum_ltsansexpression.h"
#include <QList>


class Parseur
{
    Parseur();
public:
    static QList<Operande*> NewListOperande(const QString& chaine);
    static QList<OPNum_LTSansExpression*> NewListOPNum_LTSansExpression(const QString& chaine);
};

#endif // PARSEUR_H
