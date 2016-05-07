#include "operandefactory.h"
#include "operande.h"
#include "opnumerique.h"
#include "oplogique.h"
#include "opmanipulationpile.h"
#include "opconditionnelboucle.h"
#include "opliterraleexpresion.h"


Operande *OperandeFactory::NewOperande(const QString& str){

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
         else return (new LTEntier(str));
    return nullptr;
}
