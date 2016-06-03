#ifndef UICOMMANDELINE_H
#define UICOMMANDELINE_H

#include <QLineEdit>
#include <iostream>

/*!
 * \brief Classe UICommandLine, gere l'affichage de l'interpréteur de commandes
 */
class UICommandLine : public QLineEdit
{
public:
    //! Constructeur
    UICommandLine():QLineEdit() {}

    /*!
     * \brief Ecrit un texte dans l'interpréteur
     * \param text
     */
    void write(const QString text) {
        this->setText(this->text() + text);
    }

    /*!
     * \brief Supprimer le dernier charactère
     */
    void deleteLastCharacter() {
        QString newText = this->text().left(this->text().length()-1);
        this->setText(newText);
    }

    /*!
     * \brief Supprime le texte de l'interpréteur
     */
    void clear() {
        this->setText("");
    }
};

#endif // UICOMMANDELINE_H
