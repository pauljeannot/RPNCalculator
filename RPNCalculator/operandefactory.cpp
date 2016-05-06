#include "operandefactory.h"
#include "ltnumerique.h"
#include <QList>


QList<LTNumerique*> OperandeFactory::NewOperande(const QString& description){
    QList<LTNumerique*> listeResultat;

    QStringList listOperande = description.split(" ");

    foreach (const QString& str, listOperande) {
            if (str.contains(".")){
                QStringList Reelle = description.split(".");
                 listeResultat.push_back(new LTReelle(LTEntier(Reelle[0]), LTEntier(Reelle[1]), "."));
            }
            else
                if (str.contains("/")){
                    QStringList Rationnelle = description.split("/");
                     listeResultat.push_back(new LTRationnelle(LTEntier(Rationnelle[0]), LTEntier(Rationnelle[1]), "/"));
                }
                else {
                    listeResultat.push_back(new LTEntier(str));
                }
        }
    return listeResultat;
}
