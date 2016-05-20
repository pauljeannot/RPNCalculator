#include "opconditionnelboucle.h"
#include "ltnumerique.h"
#include "ltprogramme.h"
#include "oplogique.h"
#include "controller.h"

//=================================================================
//
//                        OPIft
//
//=================================================================

Litterale* OPIft::compute(Litterale* l1, Litterale* l2) {

    LTEntier* e = dynamic_cast<LTEntier*>(l1);
    if ((e != nullptr && e->getValue() == OPLogique::falseValue.getValue()) ){
        return nullptr;
    }
    else {
        LTProgramme* prog = dynamic_cast<LTProgramme*>(l2);

        if (prog != nullptr) {
            QString text = l2->getText() + " EVAL ";
            Controller::getInstance().computeLine(text);
        }
        else {
            Controller::getInstance().computeLine(l2->getText());
        }

        return nullptr;
    }
}


// DUP 0 < [ NEG ] IFT
