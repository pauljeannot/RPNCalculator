#include "operandefactory.h"
#include "operande.h"
#include "opnumerique.h"
#include "oplogique.h"
#include "opmanipulationpile.h"
#include "opconditionnelboucle.h"
#include "opliterraleexpresionprogramme.h"
#include "ltexpression.h"
#include "ltprogramme.h"
#include "ltatome.h"
#include "ltatomemanager.h"
#include "opatome.h"
#include "parseur.h"
#include <QChar>
#include <QString>
#include <QStack>


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

    // Si c'est un opérateur de litterale expression ou programme
    if(str == "EVAL") return new OPEval();
    if(str == "EDIT") return new OPEdit();

    // Si c'est un opérateur de litterale atome
    if(str == "FORGET") return new OPForget();
    if(str == "STO") return new OPSto();

    // Si c'est une expression
    if(str.contains("'")){
        return (new LTExpression(Parseur::NewListOPNum_LTSansExpression(OperandeFactory::infixToPostfix(str))));
    }

    // Si c'est un programme
    if(str.contains("[")){
        // Remplacement des retours chariots et tabulations par des espaces
        QRegExp retourLigne("(\\n)");
        QRegExp tab("(\\t)");
        QString temp = str;

        // On remplace les retours à la ligne par des espaces
        if(str.contains(retourLigne))
            temp = temp.replace(retourLigne, QString(" "));

        // On remplace les tabulations par des espaces aussi
        if(str.contains(tab))
            temp = temp.replace(tab, QString(" "));

        // On enlève les crochets
        temp = temp.remove('[');
        temp = temp.remove(']');

        return (new LTProgramme(Parseur::NewListOperande(temp)));
    }

    // Si c'est un Atome
    if (str[0] >= QChar('A') && str[str.length()-1] <= QChar('Z')){
//        return (new LTAtome(str));
        LTAtomeManager& am = LTAtomeManager::getInstance();
        try {
            Litterale* a = am.createAtomeOrAssociatedLitterale(str);
            return a;
        }
        catch (ExceptionAtome e) {
            throw;
        }
    }

    // C'est une littérale numérique
    if (str.contains("$")){
        QStringList c = str.split("$");

        // Si le dénominateur = 0, on prend en charge l'exception levée
        try {
            Operande* a = NewOperande(c[0]);
            Operande* b = NewOperande(c[1]);
            LTNumerique* e1 = dynamic_cast<LTNumerique*>(a);
            LTNumerique* e2 = dynamic_cast<LTNumerique*>(b);

            return (new LTComplexe(e1, e2));
        }
        catch (ExceptionWrongTypeOperande e) {
            throw;
        }
        catch (ExceptionRationnelle e) {
            throw;
        }
    }
    else if (str.contains("/")){
        QStringList Rationnelle = str.split("/");

        // Si le dénominateur = 0, on prend en charge l'exception levée
        try {
            return (new LTRationnelle(Rationnelle[0], Rationnelle[1]));
        }
        catch (ExceptionWrongTypeOperande e) {
            throw;
        }
        catch (ExceptionRationnelle e) {
            throw;
        }
    }
    else if(str.contains(".")){
        return (new LTReelle(str));
    }

    // C'est un entier ou autre chose
    bool flag;
    int tmp = str.toInt(&flag, 10);

    // Si c'est un entier
    if (flag == true) {
        return (new LTEntier(tmp));
    }


    // Si on arrive ici, c'est qu'aucune concordance entre la chaine et un littérale ou un opérateur n'a été trouvée. Donc exception :
    std::cout << "conversion entier échoue" << std::endl;
    throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERANDE, "L'opérande saisie est inconnue.");

    return nullptr;
}


/* ========================================================
 *  Fonctions pour convertir une string infixe en postfixe
 * =======================================================*/

// Fonction permettant de dire si un caractère est un opérateur dans le cas d'une notation infixe
bool OperandeFactory::isOperator(QString C){
    if(C == "+" || C == "-" || C == "*" || C == "/" || C == "$" || C == " NEG " ||
            C == "DIV" || C == "MOD" || C == "NUM" || C == "DEN" || C == "IM" || C == "RE") return true;
    return false;
}

bool OperandeFactory::isLitterale(const QString& symbol) {
    bool isNumber = false;
    bool isAtome = false;
    // On regarde si c'est un nombre
    for(unsigned int i = 0; i < symbol.length(); i++){
        (symbol[i].isNumber() || symbol[i] == '.') ? isNumber = true : isNumber = false;
    }
    // On test si c'est un atome, c-a-d que le premier caractère est une lettre et la suite un nombre ou une string
    if(symbol[0].isLetter()){
        for(unsigned int i = 0; i < symbol.length(); i++){
            symbol[i].isLetterOrNumber() ? isAtome = true : isAtome = false;
        }
    }
    if(OperandeFactory::isOperator(symbol)) isAtome = false;

    return (isNumber || isAtome);
}

int OperandeFactory::operatorWeight(QString C){
    if(C == "+" || C == "-") return 1;
    if(C == "*" || C == "/") return 2;
    if(C== "$") return 3;
    if(C == "DIV" || C == "MOD" || C == "NUM" || C == "DEN") return 4;
    if(C == "NEG" || C == "IM" || C == "RE") return 5;
    return 0;
}

int OperandeFactory::operateurPrioritaire(QString a, QString b)
{
    int weighta = OperandeFactory::operatorWeight(a);
    int weightb = OperandeFactory::operatorWeight(b);
    if(weighta >= weightb) return 1;
    return 0;
}

QString OperandeFactory::addSpace(QString str){
    QString newString = str.replace(QString("+"), QString(" + "));
    newString = newString.replace(QString("*"), QString(" * "));
    newString = newString.replace(QString("/"), QString(" / "));
    newString = newString.replace(QString("-"), QString(" - "));
    newString = newString.replace(QString("$"), QString(" $ "));
    newString = newString.replace(QString("DIV"), QString(" DIV "));
    newString = newString.replace(QString("MOD"), QString(" MOD "));
    newString = newString.replace(QString("NUM"), QString(" NUM "));
    newString = newString.replace(QString("DEN"), QString(" DEN "));
    newString = newString.replace(QString("IM"), QString(" IM "));
    newString = newString.replace(QString("RE"), QString(" RE "));
    newString = newString.replace(QString("("), QString(" ( "));
    newString = newString.replace(QString(")"), QString(" ) "));
    return newString;
}

QString OperandeFactory::infixToPostfix(QString expr){

    QStack<QString> stack;
    QString postfix = "";
    QString ch;
    QString newInfix =  OperandeFactory::addSpace(expr); // On ajoute des espaces autour des opérateurs
    newInfix = newInfix.remove("'");                    // On retire les simples quotes
    QStringList liste = newInfix.split(' ', QString::SkipEmptyParts);   // On recupére nos QStrings dans une liste

    // debut des modifs
    for(unsigned int i = 0; i < liste.length(); i++){
        ch = liste.at(i);
        if(ch == ",") postfix.push_back(" ");   // si c'est une virgule on n'y prete pas attention
        else if(OperandeFactory::isLitterale(ch))  postfix.push_back(ch);
        else if(ch == "(")  stack.push(ch);
        else if(ch == ")") {
            while(!stack.empty() && stack.top() != "("){
                postfix.push_back(" ");
                postfix.push_back(stack.pop());
            }
            stack.pop(); // Enlève la parenthèse ouvrante
        }
        else if (OperandeFactory::isOperator(ch))
        {
            // Si c'est le premier élément de la liste infixe ou que l'élément d'avant est une parenthèse ouvrante,
            // on remplace - par NEG
            if(ch == "-"){
                std::cout << "On est sur le signe " << ch.toStdString() << std::endl;
                if(!OperandeFactory::isLitterale(liste.at(i-1))){
                    std::cout << "Avant le " << ch.toStdString() << " il y a un "<< liste.at(i-1).toStdString() << " et ce n'est pas une littérale" << std::endl;
                    ch = "NEG";
                }else
                    std::cout << "Avant le " << ch.toStdString() << " il y a un "<< liste.at(i-1).toStdString() << " et c'est un littérale" << std::endl;

            }
            if((i == 0 && ch == "-") || (!stack.empty() && stack.top() == "(" && ch == "-" && !OperandeFactory::isLitterale(liste.at(i-1)))){
                ch = "NEG";
            }
            while(!stack.empty() && !OperandeFactory::operateurPrioritaire(ch, stack.top())){
                postfix.push_back(" ");
                postfix.push_back(stack.pop());
            }
            postfix.push_back(" ");
            stack.push(ch);
        }
    }
    while(!stack.empty()){
        postfix.push_back(" ");
        postfix.push_back(stack.pop());
    }

    return postfix;
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

    // Si c'est un Atome
    if (str[0] >= QChar('A') && str[str.length()-1] <= QChar('Z')){
        LTAtomeManager& am = LTAtomeManager::getInstance();
        try {
            LTAtome* a = am.createAtome(str);
            return a;
        }
        catch (ExceptionAtome e) {
            throw;
        }
    }

    // C'est une littérale numérique
    if (str.contains("$")){
        QStringList c = str.split("$");

        // Si le dénominateur = 0, on prend en charge l'exception levée
        try {
            Operande* a = NewOperande(c[0]);
            Operande* b = NewOperande(c[1]);
            LTNumerique* e1 = dynamic_cast<LTNumerique*>(a);
            LTNumerique* e2 = dynamic_cast<LTNumerique*>(b);

            return (new LTComplexe(e1, e2));
        }
        catch (ExceptionWrongTypeOperande e) {
            throw;
        }
        catch (ExceptionRationnelle e) {
            throw;
        }
    }
    else if (str.contains("/")){
        QStringList Rationnelle = str.split("/");

        // Si le dénominateur = 0, on prend en charge l'exception levée
        try {
            return (new LTRationnelle(Rationnelle[0], Rationnelle[1]));
        }
        catch (ExceptionWrongTypeOperande e) {
            throw;
        }
        catch (ExceptionRationnelle e) {
            throw;
        }
    }
    else if(str.contains(".")){
        return (new LTReelle(str));
    }

    // C'est un entier ou autre chose
    bool flag;
    int tmp = str.toInt(&flag, 10);

    // Si c'est un entier
    if (flag == true) {
        return (new LTEntier(tmp));
    }

    return nullptr;
}

