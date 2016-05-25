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
    int openPar = 0, closenPar = 0;
    // Parcours de chaque chaine
    try {
        for(unsigned int i = 0; i < listOperande.length(); i++){
            // Si c'est un programme
            if(listOperande[i] == "["){
                openPar++;
                QString Programme = "";
                while(openPar != closenPar && i < listOperande.length()-1){
                    std::cout << "i : " << QString(listOperande[i]).toStdString() << std::endl;
                    if(listOperande[i] == "]") closenPar++;
                    // Stocker dans une liste les opérandes du programme
                    Programme += listOperande[i] + " ";
                    i++;
                }
                if(listOperande[i] == "]") closenPar++;
                std::cout << "i : " << QString(listOperande[i]).toStdString() << std::endl;

                Programme += listOperande[i];

                if(openPar == closenPar){
                    listeResultat.push_back(OperandeFactory::NewOperande(Programme));
                }
                else if(openPar > closenPar){
                    std::cout << "open : " << openPar << " // close : " << closenPar << std::endl;
                    std::cout << Programme.toStdString() << std::endl;
                    throw ExceptionSyntaxte(ExceptionSyntaxte::SYNTAX_ERROR, "Vous avez oublié de fermer un crochet.");
                }
                else if(openPar < closenPar)
                    throw ExceptionSyntaxte(ExceptionSyntaxte::SYNTAX_ERROR, "Vous avez ajouter un ou plusieurs crochets en trop.");
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
