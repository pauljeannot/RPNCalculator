#ifndef UTCOMPUTER_H
#define UTCOMPUTER_H

#include <QMainWindow>
#include "uicommandeline.h"
#include "uimessageline.h"
#include "uiclavier.h"
#include "uipileview.h"
#include "uimenu.h"
#include <iostream>
#include <QList>

/*!
 * \brief Gère tous composants graphiques de la calculatrice
 */
class UTComputer : public QMainWindow
{
    Q_OBJECT

    static UTComputer * instance;
    UICommandLine *cmd;
    UIMessageLine* message;
    UIKeyboard *clavier;
    UIPileView * pile;
    QHBoxLayout* horizontalMainLayout;
    UIMenu* menu;

    // Opérande qui doivent être évaluées directement lorsqu'elles sont tappées au clavier
    QList<QString> evaluatedOperandes = QList<QString>({"+", "-", "*", "/", "$"});

    // Opérande qui ne doivent pas entrainer d'évaluation
    QList<QString> softOperandes = QList<QString>({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " ", "."});

    explicit UTComputer(QWidget *parent = 0);

    ~UTComputer() {
        delete cmd;
        delete message;
        delete clavier;
        delete pile;
        delete menu;
        delete horizontalMainLayout;
    }

    UTComputer(const UTComputer& utc);


    bool isInExpression(const QString& text);
    bool isInProgram(const QString& text);

public:
    /*!
     * \brief getInstance
     * \param parent
     * \return
     */
    static UTComputer& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UTComputer(parent);
        return *instance;
    }

    /*!
     * \brief Libère l'instance
     */
    static void freeInstance() {
        if (instance) delete instance;
    }

    /*!
     * \brief Ecrit une QString dans l'interpréteur de commande
     * \param text
     */
    void writeInCommandeLine(const QString& text);

    /*!
     * \brief Affiche le clavier
     */
    void showKeyboard() {
        if(!horizontalMainLayout->children().contains(clavier)) {
            this->setFixedSize(800, 500);
            horizontalMainLayout->addWidget(clavier);
           }
    }

    /*!
     * \brief Cacher le clavier
     */
    void hideKeyboard() {
        horizontalMainLayout->removeWidget(clavier);
        this->setFixedSize(330, 500);
    }

    /*!
     * \brief Actualise l'affichage de la calculatrice avec les nouveaux paramètres
     * \param nbLines
     * \param playS
     * \param showK
     */
    void refreshUIWithNewSetting(unsigned int nbLines, bool playS, bool showK);

    /*!
     * \brief Actualise l'affichage de la pile
     */
    void refreshStackView();

    /*!
     * \brief Met a jour le message d'erreur
     * \param text
     */
    void updateMessage(const QString& text) {
        this->message->updateMessage(text);
    }

    /*!
     * \brief Nettoie l'interpreteur de commande
     */
    void clearCommandLine() {
        this->cmd->clear();
    }

signals:

public slots:
    /*!
     * \brief Applique un traitement quand l'interpréteur de commandes est édité.
     * \param text
     */
    void commandeLineEdited(const QString text);

    /*!
     * \brief Applique un traitement quand la touche Entrer est pressée.

     */
    void commandeLineEnterPressed();
};

#endif // UTCOMPUTER_H
