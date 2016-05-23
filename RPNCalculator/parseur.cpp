#include "parseur.h"
#include "operandefactory.h"
#include "ltprogramme.h"
#include "opliterraleexpresionprogramme.h"
#include <QList>

Parseur::Parseur()
{

}

QList<Operande *> Parseur::NewListOperande(const QString& chaine) {
    // Liste contenant les types à renvoyer
    QList<Operande*> listeResultat;
    // Séparation des différentes chaines
    QRegExp rx("(\\ )");
    QStringList listOperande = chaine.split(rx,  QString::SkipEmptyParts);

    // Parcours de chaque chaine
    try {
        for(unsigned int i = 0; i < listOperande.length(); i++){
            if(listOperande[i] == "["){
                std::cout << i << " : " << listOperande[i].toStdString() << std::endl;
                QString Programme = "";
                while(listOperande[i] != "]"){
                    // Stocker dans une liste les opérandes du programme
                    Programme += listOperande[i] + " ";
                    // Ajouter créer un LTProgramme avec cette liste
                    // Ajouter le LTProgramme a la listeResultat
                    i++;
                }
                Programme += listOperande[i];
                std::cout << "Programme : " <<Programme.toStdString() << std::endl;
                listeResultat.push_back(OperandeFactory::NewOperande(Programme));
                i++;
            }

            // Si on trouve un programme à partir de la ligne du dessous, c'est que c'était un atome transformé donc on rajoute EVAL après le programme

            else {
                Operande* op = OperandeFactory::NewOperande(listOperande[i]);
                listeResultat.push_back(op);

                LTProgramme* prog = dynamic_cast<LTProgramme*>(op);
                if (prog != nullptr) {
                    listeResultat.push_back(new OPEval());
                }
            }
        }
        //foreach (const QString& str, listOperande) {
          //  listeResultat.push_back(OperandeFactory::NewOperande(str));
        //}
    }
    catch (ExceptionWrongTypeOperande e) {
        throw;
    }
    catch (ExceptionRationnelle e) {
        throw;
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
