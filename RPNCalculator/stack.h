#ifndef STACK_H
#define STACK_H

#include <QStack>
#include <iostream>
#include "operande.h"
#include "litterale.h"

class Stack
{
    QList<Litterale*>stack;

public:
    Stack() {}
    ~Stack() {
        QList<Litterale*>::iterator j;
        for (j = stack.begin(); j != stack.end(); ++j)
            delete (*j);
    }

    inline void swap(QList<Litterale*> &other) { stack.swap(other); }
    void push(Litterale* t) { stack.insert(0, t); }
    Litterale* pop() {
        Litterale* l = stack.at(0);
        stack.removeFirst();
        return l; }
    const Litterale* operator[](unsigned int index) const { return stack[index]; }
    unsigned int size() const { return stack.size(); }
};


#endif // STACK_H
