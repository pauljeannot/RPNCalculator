#include "operandefactory.h"
#include "operande.h"
#include "opnumerique.h"
#include "oplogique.h"
#include "opmanipulationpile.h"
#include "opconditionnelboucle.h"
#include "opliterraleexpresionprogramme.h"
#include "ltatome.h"
#include "ltexpression.h"
#include "ltprogramme.h"
#include "ltatome.h"
#include "opatome.h"
#include "parseur.h"
#include <QChar>
#include <QString>
#include <QStack>


Operande *OperandeFactory::NewOperande(const QString& str){

    if(OperandeFactory::isLitterale("1X")) std::cout << "C'est une litterale" <<std::endl;
    else std::cout << "Ce n'est pas une litterale" <<std::endl;

    // Si c'est un opérateur numérique
    if(str == "+") return new OPAddition();
    if(str == "-") return new OPSoustraction();
    if(str == "*") return new OPMultiplication();
    if(str == "/") return new OPDivision();
    if(str == "DIV") return new OPDivisionEntiere();
    if(str == "NUM") return new OPNumerateur();
    if(str == "DEN") return new OPDenominateur();
    if(str == "MOD") return new OPModulo();
    if(str == "IM") return new OPPartieImaginaireComplexe();
    if(str == "RE") return new OPPartieReelleComplexe();
    if(str == "NEG") return new OPNegation();
    if(str == "$") return new OPComplexe();

    // Si c'est un opérateur logique
    if(str == "=") return new OPEgal();
    if(str == "!=") return new OPDifferent();
    if(str == "<=") return new OPInferieurEgal();
    if(str == "<") return new OPInferieur();
    if(str == ">=") return new OPSuperieurEgal();
    if(str == ">") return new OPSuperieur();
    if(str == "AND") return new OPAnd();
    if(str == "OR") return new OPOr();
    if(str == "NOT") return new OPNot();

    //  Si c'est un opérateur de manipulation de pile
    if(str == "DUP") return new OPDup();
    if(str == "DROP") return new OPDrop();
    if(str == "SWAP") return new OPSwap();
    if(str == "LASTOP") return new OPLastOp();
    if(str == "LASTARGS") return new OPLastArgs();
    if(str == "UNDO") return new OPUndo();
    if(str == "REDO") return new OPRedo();
    if(str == "CLEAR") return new OPClear();

    // Si c'est un opérateur conditionnel de boucle
    if(str == "IFT") return new OPIft();

    // Si c'est un opérateur de litterale expression
    if(str == "EVAL") return new OPEval();
    if(str == "EDIT") return new OPEdit();

    // Si c'est un opérateur de litterale atome
    if(str == "FORGET") return new OPForget();
    if(str == "STO") return new OPSto();

    // Si c'est une expression
    /*if(str.contains("'")){
        QString clean = str.remove(0, str.length()-1);
        return (new LTExpression())
    }*/

    // Si c'est un Atome
    if (str[0] >= QChar('A') && str[str.length()-1] <= QChar('Z')){
        return (new LTAtome(str));
    }

    // C'est une littérale numérique
    if (str.contains(".")){
        QStringList Reelle = str.split(".");
        return (new LTReelle(LTEntier(Reelle[0]), LTEntier(Reelle[1]), "."));
     }
     else
        if (str.contains("/")){
            QStringList Rationnelle = str.split("/");
            return (new LTRationnelle(LTEntier(Rationnelle[0]), LTEntier(Rationnelle[1]), "/"));
         }
         else return (new LTEntier(str)); // Problème ici, renvoit toujours un nombre, il faut trouver un moyen de renvoyer autre chose.

    return nullptr;
}


/* ========================================================
 *  Fonctions pour convertir une string infixe en postfixe
 * =======================================================*/

// Fonction permettant de dire si un caractère est un opérateur dans le cas d'une notation infixe
bool OperandeFactory::isOperator(QChar C){
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$') return true;
    return false;
}

bool OperandeFactory::isLitterale(const QString& symbol) {
    bool isNumber = false;
    bool isAtome = false;
    // On regarde si c'est un nombre
    for(unsigned int i = 0; i < symbol.length(); i++){
       std::cout << QString(symbol[i]).toStdString();
       symbol[i].isNumber() ? isNumber = true : isNumber = false;
    }
    std::cout << std::endl;
    // On test si c'est un atome, c-a-d que le premier caractère est une lettre et la suite un nombre ou une string
    if(symbol[0].isLetter()){
        for(unsigned int i = 1; i < symbol.length(); i++){
             std::cout << QString(symbol[i]).toStdString();
             symbol[i].isLetterOrNumber() ? isAtome = true : isAtome = false;
        }
    }

    return (isNumber || isAtome);
}


OPNum_LTSansExpression* OperandeFactory::NewOPNum_LTSansExpression(const QString& str){


    // Si c'est un opérateur numérique
    if(str == "+") return new OPAddition();
    if(str == "-") return new OPSoustraction();
    if(str == "*") return new OPMultiplication();
    if(str == "/") return new OPDivision();
    if(str == "DIV") return new OPDivisionEntiere();
    if(str == "NUM") return new OPNumerateur();
    if(str == "DEN") return new OPDenominateur();
    if(str == "MOD") return new OPModulo();
    if(str == "IM") return new OPPartieImaginaireComplexe();
    if(str == "RE") return new OPPartieReelleComplexe();
    if(str == "NEG") return new OPNegation();
    if(str == "$") return new OPComplexe();


    return nullptr;
}



