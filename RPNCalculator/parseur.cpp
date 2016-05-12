#include "parseur.h"
#include "operandefactory.h"
#include <QList>

Parseur::Parseur()
{

}

QList<Operande *> Parseur::NewListOperande(const QString& chaine) throw (ExceptionRationnelle){
    // Liste contenant les types à renvoyer
    QList<Operande*> listeResultat;
    // Séparation des différentes chaines
    QRegExp rx("(\\ )");
    QStringList listOperande = chaine.split(rx,  QString::SkipEmptyParts);

    // Parcours de chaque chaine
    try {
        foreach (const QString& str, listOperande) {
            listeResultat.push_back(OperandeFactory::NewOperande(str));
        }
    }
    catch (ExceptionRationnelle e) {
        if (e.errorType() == ExceptionRationnelle::Type::CANNOT_HAVE_DENUM_ZERO) {
            throw;
        }
        else if (e.errorType() == ExceptionRationnelle::Type::UNKNOWN_SEPARATOR) {
            throw;
        }

    }

    return listeResultat;
}

QList<OPNum_LTSansExpression*> Parseur::NewListOPNum_LTSansExpression(const QString& chaine){
    // Liste contenant les types à renvoyer
    QList<OPNum_LTSansExpression*> listeResultat;

    // Séparation des différentes chaines
    QRegExp rx("(\\ )");
    QStringList listOPNum_LTSansExpression = chaine.split(rx,  QString::SkipEmptyParts);

    // Parcours de chaque chaine
    foreach (const QString& str, listOPNum_LTSansExpression) {
        listeResultat.push_back(OperandeFactory::NewOPNum_LTSansExpression(str));
     }
    return listeResultat;
}
