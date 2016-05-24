#include "opatome.h"
#include "ltatomemanager.h"
#include "ltprogramme.h"
#include "ltnumerique.h"

//=================================================================
//
//                        OPSto
//
//=================================================================

Litterale* OPSto::compute(Litterale* l1, Litterale* l2) {

    LTProgramme* prog = dynamic_cast<LTProgramme*>(l1);
    LTNumerique* num = dynamic_cast<LTNumerique*>(l1);
    LTExpression* exp = dynamic_cast<LTExpression*>(l1);

    // Si le type de litterale à stocker est correct
    if (prog != nullptr || num != nullptr || exp != nullptr) {
        LTExpression* expAtome = dynamic_cast<LTExpression*>(l2);
        // Si la litterale l2 est bien une expression ne contenant qu'un atome
        if(expAtome != nullptr && expAtome->getList().size() == 1) {
            LTAtome* atome = dynamic_cast<LTAtome*>(expAtome->getList().at(0));
            atome->setPointer(l1);
            Controller::getInstance().saveAtomeManagerInFile();
        }
        else {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE, "Une litterale ne peut être identifé que par un atome, contenu dans une expression.");
        }
    }
    else {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE, "Un atome ne peut identifier qu'une litterale numérique, expression ou programme.");
    }

    return nullptr;
}

//=================================================================
//
//                        OPForget
//
//=================================================================

Litterale* OPForget::compute(Litterale* l) {

        LTExpression* expAtome = dynamic_cast<LTExpression*>(l);
        // Si la litterale l est bien une expression ne contenant qu'un atome
        if(expAtome != nullptr && expAtome->getList().size() == 1) {
            LTAtome* atome = dynamic_cast<LTAtome*>(expAtome->getList().at(0));
            atome->setPointer(nullptr);
            LTAtomeManager::getInstance().removeAtome(atome);
        }
        else {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE, "L'opérateur FORGET ne s'utilise qu'avec un atome contenu dans une expression.");
        }
    return nullptr;
}
