#include "parseur.h"
#include "operandefactory.h"
#include <QList>

Parseur::Parseur()
{

}

QList<Operande *> Parseur::NewListOperande(const QString& chaine){
    // Liste contenant les types à renvoyer
    QList<Operande*> listeResultat;
    // Séparation des différentes chaines
    QStringList listOperande = chaine.split(" ");

    // Parcours de chaque chaine
    foreach (const QString& str, listOperande) {
        listeResultat.push_back(OperandeFactory::NewOperande(str));
     }
    return listeResultat;
}
