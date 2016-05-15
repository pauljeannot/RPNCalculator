#include "opmanipulationpile.h"
#include "controller.h"

//=================================================================
//
//                        OPDup
//
//=================================================================

Litterale* OPDup::compute(Litterale* l) {
    Stack& stack = Controller::getInstance().getStack();
    stack.push(l);
    stack.push(l);
    return nullptr;
}

//=================================================================
//
//                        OPDrop
//
//=================================================================

Litterale* OPDrop::compute(Litterale* l) {
    return nullptr;
}

//=================================================================
//
//                        OPSwap
//
//=================================================================

Litterale* OPSwap::compute(Litterale* l1, Litterale* l2) {
    Stack& stack = Controller::getInstance().getStack();
    stack.push(l2);
    stack.push(l1);
    return nullptr;
}

//=================================================================
//
//                        OPLastOp
//
//=================================================================

Litterale* OPLastOp::compute() {

    Operateur* lastOp = Computer::getInstance().getLastOp();
    Controller& ctrl = Controller::getInstance();

    if(lastOp != nullptr) {
        ctrl.computeLine(lastOp->getText());
    }

    return nullptr;
}

//=================================================================
//
//                        OPLastArgs
//
//=================================================================

Litterale* OPLastArgs::compute() {

    QList<Litterale*>* lastArgs = Computer::getInstance().getLastArgs();

    if(lastArgs == nullptr) return nullptr;

    Stack& stack = Controller::getInstance().getStack();

    QList<Litterale*>::iterator j;
    for (j = lastArgs->begin(); j != lastArgs->end(); ++j) {
        stack.push(*j);
    }

    return nullptr;
}


//=================================================================
//
//                        OPClear
//
//=================================================================

Litterale* OPClear::compute() {
    Stack& stack = Controller::getInstance().getStack();
    stack.clear();
    return nullptr;
}
