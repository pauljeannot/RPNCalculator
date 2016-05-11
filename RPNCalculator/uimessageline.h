#ifndef UIMESSAGELINE_H
#define UIMESSAGELINE_H

#include <QTextEdit>
#include <QSound>

class UIMessageLine : public QTextEdit
{
    bool playSound;

public:
    UIMessageLine():QTextEdit(), playSound(true) {
        this->setStyleSheet("background: black; color:white");
        this->setReadOnly(true);
        this->setMaximumHeight(60);
    }

    void setPlaySound(bool value) { this->playSound = value; }

    void updateMessage(const QString& text) {
        if(this->playSound && text != "") QSound::play("/Users/gum/Documents/UTC/LO21/Projet/RPNCalculator/RPNCalculator/ressources/message-sound.wav");
        this->setText(text);
    }

    void clearMessage() {
        this->setText("");
    }
};

#endif // UIMESSAGELINE_H
