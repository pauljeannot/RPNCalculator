#ifndef UIMESSAGELINE_H
#define UIMESSAGELINE_H

#include <QLineEdit>
#include <QSound>

class UIMessageLine : public QLineEdit
{
    bool playSound;

public:
    UIMessageLine():QLineEdit(), playSound(true) {
        this->setStyleSheet("background: black; color:white");
    }

    void setPlaySound(bool value) { this->playSound = value; }

    void updateMessage(const QString& text) {
        if(this->playSound) QSound::play("/Users/gum/Documents/UTC/LO21/Projet/RPNCalculator/RPNCalculator/ressources/message-sound.wav");
        this->setText(text);
    }
};

#endif // UIMESSAGELINE_H
