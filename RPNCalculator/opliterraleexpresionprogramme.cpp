#include "opliterraleexpresionprogramme.h"
#include "ltprogramme.h"
#include "controller.h"

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
        std::cout << "résultat : '" << text.toStdString()  << "'" << std::endl;

        Controller::getInstance().computeLine(text);
    }

    LTExpression* exp = dynamic_cast<LTExpression*>(l);
    if (exp != nullptr) {
        Controller::getInstance().computeLine(exp->getContentToCompute());
    }


    return nullptr;
}



// [ DUP 0 < [ NEG ] IFT ]

//LTNombre* e1 = dynamic_cast<LTNombre*>(l1);
//LTNombre* e2 = dynamic_cast<LTNombre*>(l2);

//if (e1 != nullptr && e2 != nullptr) {
//    int res = ((*e1) == *(e2));

//    if (res == OPLogique::trueValue.getValue()) return OPLogique::trueValue.clone();
//    else return OPLogique::falseValue.clone();
//}
//else {
//    throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur = n'est pas utilisable avec ce type de litterales.");
//}
