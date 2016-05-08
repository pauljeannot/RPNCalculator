#include "controller.h"
#include "utcomputer.h"

Controller* Controller::instance = 0;

void Controller::updateSettings(unsigned int nb, bool playS, bool showK) {
    this->nbLines = nb;
    this->playSound = playS;
    this->showKeyboard = showK;

    UTComputer& utc = UTComputer::getInstance();
    utc.refreshUIWithNewSetting(this->nbLines, this->playSound, this->showKeyboard);
}

