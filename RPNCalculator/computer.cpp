#include "computer.h"
#include "exception.h"

Computer* Computer::instance = 0;

Litterale* Computer::compute(Operateur* op, Litterale* l1) const {
    try {
        return op->compute(l1);
    }
    catch (ExceptionWrongTypeOperande e) {
        throw;
    }
}

Litterale* Computer::compute(Operateur* op, Litterale* l1, Litterale* l2) const {
    try {
        return op->compute(l1, l2);
    }
    catch (ExceptionWrongTypeOperande e) {
        throw;
    }
}
