#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "computer.h"
#include "stack.h"
#include <iostream>
#include <QString>

class Controller
{
    static Controller * instance;
    Controller():showKeyboard(true), playSound(true), nbLines(20) {

        std::cout << nbLines << std::endl;

    }
    ~Controller() {}
    Controller(const Controller& c);



    // Settings de la vue :
    bool showKeyboard;
    bool playSound;
    int nbLines;

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
    void setSettingShowKeyboard(bool value) { this->showKeyboard = value; }

    bool settingPlaySound() const { return playSound; }
    void setSettingPlaySound(bool value) { this->playSound = value; }

    int settingNbLines() const {
        return nbLines; }
    void setSettingNbLines(int value) { this->nbLines = value; }

};

#endif // CONTROLLER_H
