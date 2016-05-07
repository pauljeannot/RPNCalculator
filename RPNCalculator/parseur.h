#ifndef PARSEUR_H
#define PARSEUR_H
#include "operande.h"
#include <QList>


class Parseur
{
    Parseur();
public:
    static QList<Operande*> NewListOperande(const QString& chaine);
};

#endif // PARSEUR_H
