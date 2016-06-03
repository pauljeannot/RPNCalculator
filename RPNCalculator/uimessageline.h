#ifndef UIMESSAGELINE_H
#define UIMESSAGELINE_H

#include <QTextEdit>
#include <QSound>

/*!
 * \brief Partie de l'interface graphique permettant d'afficher des messages d'erreur à l'utilisateur
 */
class UIMessageLine : public QTextEdit
{
    /*!
     * \brief Variable booléenne permettant de savoir si les sons sont activés
     */
    bool playSound;

public:
    /*!
     * \brief Constructeur
     * Règle les paramètres de l'éditeur de texte
     */
    UIMessageLine():QTextEdit(), playSound(true) {
        this->setStyleSheet("background: black; color:white");
        this->setReadOnly(true);
        this->setMaximumHeight(60);
    }

    /*!
     * \brief Permet de changer la valeur du booléen Playsound
     * \param value Booléen
     */
    void setPlaySound(bool value) { this->playSound = value; }

    /*!
     * \brief Met à jout le texte à afficher
     * \param text QString
     */
    void updateMessage(const QString& text) {
        if(this->playSound && text != "") QSound::play("/Users/gum/Documents/UTC/LO21/Projet/RPNCalculator/RPNCalculator/ressources/message-sound.wav");
        this->setText(text);
    }

    /*!
     * \brief Supprime le texte de l'éditeur de texte
     */
    void clearMessage() {
        this->setText("");
    }
};

#endif // UIMESSAGELINE_H
