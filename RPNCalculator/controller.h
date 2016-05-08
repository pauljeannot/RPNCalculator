#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "computer.h"
#include "stack.h"
#include <iostream>
#include <QString>

class Controller
{
    static Controller * instance;
    Controller():showKeyboard(true), playSound(true), nbLines(20) {}
    ~Controller() {}
    Controller(const Controller& c);

    // Settings de la vue :
    bool showKeyboard;
    bool playSound;
    unsigned int nbLines;

public:
    static Controller& getInstance() {
        if (!instance) instance = new Controller();

        return *instance;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

    void computeLine(const QString& text) {
        std::cout << text.toStdString() << std::endl;
    }

    bool settingShowKeyboard() const { return showKeyboard; }
    bool settingPlaySound() const { return playSound; }
    unsigned int settingNbLines() const {
        return nbLines; }

    void updateSettings(unsigned int nb, bool playS, bool showK);

};

#endif // CONTROLLER_H
