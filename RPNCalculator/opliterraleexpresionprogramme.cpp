#include "opliterraleexpresionprogramme.h"
#include "ltprogramme.h"
#include "controller.h"
#include "uitexteditor.h"

//---------------------------------------------
//
//                  OPEval
//
//---------------------------------------------

Litterale* OPEval::compute(Litterale* l) {

    LTProgramme* p = dynamic_cast<LTProgramme*>(l);
    if (p != nullptr) {
        QString text = " ";
        QList<Operande*> list = p->getListOperande();

        QList<Operande*>::const_iterator j;
        for (j = list.begin(); j != list.end(); ++j)
            text += (*j)->getText() + " ";
        text += " ";

        Controller::getInstance().computeLine(text);
    }

    LTExpression* exp = dynamic_cast<LTExpression*>(l);
    if (exp != nullptr) {
        QList<OPNum_LTSansExpression*> liste = exp->getList();
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j) {
            LTAtome* a = dynamic_cast<LTAtome*>(*j);
            if(a != nullptr && a->getNature() != LTAtome::EnumNature::IDVAR)
                throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE, "Une expression n'est évaluée que si elle contient des litterales numériques ou atomes identifiant des variables.");
        }

        Controller::getInstance().computeLine(exp->getContentToCompute());
    }

    return nullptr;
}


//---------------------------------------------
//
//                  OPEdit
//
//---------------------------------------------

Litterale* OPEdit::compute(Litterale* l) {
    LTProgramme* p = dynamic_cast<LTProgramme*>(l);
    LTExpression* expAtome = dynamic_cast<LTExpression*>(l);
    std::cout << p << std::endl;
    if (p != nullptr) {
        QString text = p->getText();
        UITextEditor* TEditor = &UITextEditor::getInstance(text);
        TEditor->show();

    }else
        // Si la litterale l est bien une expression ne contenant qu'un atome
        if(expAtome != nullptr && expAtome->getList().size() == 1) {
            LTAtome* atome = dynamic_cast<LTAtome*>(expAtome->getList().at(0));
            if(atome->getEnumString() == "IDPROG" || atome->getEnumString() == "IDVAR"){
                QString texte = atome->getPointer()->getText();
                UITextEditor& TEditor = UITextEditor::getInstance(texte, atome);
                TEditor.show();
            }

        }
    else throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur EDIT n'est utilisable que sur des programmes ou des variables de programmes.");

    return nullptr;
}
