#ifndef COMPUTER_H
#define COMPUTER_H

#include <QList>
#include "operateur.h"
#include "litterale.h"

class Computer
{
    static Computer* instance;
    Computer():lastOp(nullptr), lastArgs(new QList<Litterale*>) {}
    ~Computer() {}
    Computer(const Computer& c);

    Operateur* lastOp;
    QList<Litterale*>* lastArgs;

    void saveContext(Operateur* op, Litterale* l1 = 0, Litterale* l2 = 0);

public :
    static Computer& getInstance() {
        if (!instance) instance = new Computer();
        return *instance;
    }

    static void freeInstance() { if (instance) delete instance; }

    Litterale *compute(Operateur* op);
    Litterale *compute(Operateur* op, Litterale* l1);
    Litterale* compute(Operateur* op, Litterale* l1, Litterale* l2);

    Operateur* getLastOp() {
        return lastOp;
    }

    QList<Litterale*>* getLastArgs() {
        return lastArgs;
    }

};

#endif // COMPUTER_H
