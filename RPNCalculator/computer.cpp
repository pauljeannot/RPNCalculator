#include "computer.h"
#include "exception.h"

Computer* Computer::instance = 0;

Litterale* Computer::compute(Operateur* op, Litterale* l1) const {
    try {
        return op->getChild()->compute(l1->getChild());
    }
    catch(ExceptionWrongTypeOperande e) {
        throw;
    }
}

Litterale* Computer::compute(Operateur* op, Litterale* l1, Litterale* l2) const {
//    return op->getChild()->compute(l1->getChild(), l2->getChild());
}
