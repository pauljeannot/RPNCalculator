#include "computer.h"
#include "exception.h"

Computer* Computer::instance = 0;

void Computer::saveContext(Operateur* op, Litterale* l1, Litterale* l2) {

    if (op->getText() != "LASTOP") {
        this->lastOp = op->clone();
    }

    if (op->getText() != "LASTARGS") {
        QList<Litterale*>::iterator j;
        if (this->lastArgs != nullptr) {
            for (j = this->lastArgs->begin(); j != this->lastArgs->end(); ++j) {
                this->lastArgs->removeOne(*j);
            }
        }

        if (l1 != nullptr) {
            Litterale* l1b = l1->clone();
            this->lastArgs->append(l1b);
        }
        if (l2 != nullptr) {
            Litterale* l2b = l2->clone();
            this->lastArgs->append(l2b);
        }
    }
}

Litterale* Computer::compute(Operateur* op) {

    try {
        Litterale* lit = op->compute();
        saveContext(op);
        return lit;
    }
    catch (ExceptionWrongTypeOperande e) {
        throw;
    }
    catch (ExceptionMemento e) {
        throw;
    }
}

Litterale* Computer::compute(Operateur* op, Litterale* l1) {

    try {
        Litterale* lit = op->compute(l1);
        saveContext(op, l1);
        return lit;
    }
    catch (ExceptionWrongTypeOperande e) {
        throw;
    }
    catch (ExceptionSyntaxte e) {
        throw;
    }
}

Litterale* Computer::compute(Operateur* op, Litterale* l1, Litterale* l2) {

    try {
        Litterale* lit = op->compute(l1, l2);
        saveContext(op, l1, l2);
        return lit;
    }
    catch (ExceptionWrongTypeOperande e) {
        throw;
    }
}
