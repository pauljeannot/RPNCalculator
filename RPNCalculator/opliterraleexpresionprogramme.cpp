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
        return nullptr;
    }


}


//---------------------------------------------
//
//                  OPEdit
//
//---------------------------------------------

Litterale* OPEdit::compute(Litterale* l) {
    LTProgramme* p = dynamic_cast<LTProgramme*>(l);
    LTAtome* a = dynamic_cast<LTAtome*>(l);

    if (p != nullptr) {
        QString text = p->getText();
        UITextEditor* TEditor = &UITextEditor::getInstance(text);
        TEditor->show();

    }else if (a != nullptr) {

        QString text = a->getText();
        std::cout << "résultat : '" << text.toStdString()  << "'" << std::endl;
        UITextEditor& TEditor = UITextEditor::getInstance(text);
        TEditor.show();

    }
    else throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur EDIT n'est utilisable qu'avec des programmes.");

    return nullptr;
}
