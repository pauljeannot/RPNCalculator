#ifndef MEMENTO_H
#define MEMENTO_H

#include "stack.h"

class Memento
{

    Stack* stack;

public:
    Memento(Stack* s):stack(s) { }
    Stack* getStack() { return stack; }
};

class CareTaker
{

    QList<Memento> mementos;

public:
    CareTaker() {}
    void addMemento(Memento m, int index) {
        int max = this->size();
        if(this->size() > index) {
            for (unsigned int i = index; i < max; i++) {
                this->mementos.removeLast();
            }
        }
        mementos.append(m);
    }

    Memento getMemento(int index) { return mementos.at(index); }
    int size() { return mementos.size(); }
};

class Originator
{

    Stack* stack;

public:
    Originator():stack(nullptr) {}
    void setStack(Stack* s) { this->stack = s; }
    Memento storeInMemento() { return Memento(stack); }
    Stack* restoreFromMemento(Memento m) { m.getStack(); }

};

#endif // MEMENTO_H
