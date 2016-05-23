#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "computer.h"
#include "xmlmanager.h"
#include "memento.h"
#include <iostream>
#include <QString>

class Controller
{
    static Controller * instance;
    Controller():careTaker(*(new CareTaker())), originator(*(new Originator())), computer(Computer::getInstance()), stack(new Stack()), xmlManager(XMLManager::getInstance()), showKeyboard(true), playSound(true), nbLines(20), currentStackIndex(0) {

        originator.setStack(this->stack);
        careTaker.addMemento(originator.storeInMemento(), 0);
        this->stack = this->stack->clone();
    }

    ~Controller() {}
    Controller(const Controller& c);

    //Memento :
    CareTaker& careTaker;
    Originator& originator;
    int currentStackIndex;

    // Membres :
    Stack* stack;
    Computer& computer;

    // XMLManager
    XMLManager& xmlManager;

    // Settings de la vue :
    bool showKeyboard;
    bool playSound;
    unsigned int nbLines;

public:
    static Controller& getInstance() {
        if (!instance) instance = new Controller();
        return *instance;
    }

    static void freeInstance() { if (instance) delete instance; }

    void computeLine(const QString& text);

    Stack& getStack() { return *stack; }

private:
    void computationEnded(QString messageLine);
    void saveContext();
    void saveStackInFile() const ;

public:
    bool settingShowKeyboard() const { return showKeyboard; }
    bool settingPlaySound() const { return playSound; }
    unsigned int settingNbLines() const { return nbLines; }
    void updateSettings(unsigned int nb, bool playS, bool showK);
    QList<const Litterale*> getNFirstLitteralsOnTheStack(unsigned int n) const;

    void undoFunction();
    void redoFunction();


};

#endif // CONTROLLER_H
