#ifndef COMPUTER_H
#define COMPUTER_H

#include "operateur.h"
#include "litterale.h"

class Computer
{
    static Computer* instance;
    Computer() {}
    ~Computer() {}
    Computer(const Computer& c);

public :
    static Computer& getInstance() {
        if (!instance) instance = new Computer();
        return *instance;
    }

    static void freeInstance() { if (instance) delete instance; }

    Litterale *compute(Operateur* op, Litterale* l1) const;
    Litterale* compute(Operateur* op, Litterale* l1, Litterale* l2) const;

};

#endif // COMPUTER_H
