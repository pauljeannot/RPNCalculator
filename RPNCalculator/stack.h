#ifndef STACK_H
#define STACK_H

#include <QStack>
#include <iostream>
#include "operande.h"
#include "litterale.h"
#include "exception.h"

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

    void push(Litterale* t) {
        stack.insert(0, t);
    }

    Litterale* pop() throw (ExceptionStack) {
        if (!isEmpty()) {
            Litterale* l = stack.at(0);
            stack.removeFirst();
            return l;
        }
        else {
            throw ExceptionStack(ExceptionStack::Type::CANNOT_POP_STACK_EMPTY, "Impossible de dépiler : la pile est vide");
        }
    }

    bool canPopItems(unsigned int nb) const {

        if (((int)size() - (int)nb) >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isEmpty() const {
        if (size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void clear() {
        QList<Litterale*>::iterator j;
        for (j = stack.begin(); j != stack.end(); ++j) {
            stack.removeOne(*j);
        }
    }

    const Litterale* operator[](unsigned int index) const { return stack[index]; }
    unsigned int size() const { return stack.size(); }
};


#endif // STACK_H
