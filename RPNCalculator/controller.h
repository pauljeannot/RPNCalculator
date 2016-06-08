#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "computer.h"
#include "xmlmanager.h"
#include "memento.h"
#include <iostream>
#include <QString>

//! Classe du controller : il gère l'ensemble de la partie calculatoire de la calculatrice
class Controller
{
    static Controller * instance;
    Controller():careTaker(*(new CareTaker())), originator(*(new Originator())), computer(Computer::getInstance()), stack(new Stack()), xmlManager(XMLManager::getInstance()), showKeyboard(true), playSound(true), nbLines(20), currentStackIndex(0), unixSystem(true), initDone(false) {
        std::cout << "constructor" << std::endl;

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
    bool unixSystem;
    bool initDone;

public:
    //! Fonction qui permet de récupérer l'instance du singleton
    /*!
      \return Instance du Controller
    */
    static Controller& getInstance() {
        if (!instance) {
            instance = new Controller();
            instance->initEnded();
        }
        return *instance;
    }

    //! Fonction qui permet de libérer l'instance du singleton
    static void freeInstance() { if (instance) delete instance; }

    //! Méthode qui permet d'exécuter une opérateur passée par paramètre au format QString (comme "1 2 +").
    /*!
      \param text Texte à calculer
    */
    void computeLine(const QString& text);

    //! Fonction renvoyant
    /*!
      \return Stack Retourne la référence de pile
    */
    Stack& getStack() { return *stack; }

    //! Fonction renvoyant l'information sur le système de l'utilisateur
    /*!
      \return Booléen concernant le système utilisateur : vrai si l'utilisateur un système Unix, non si Windows.
    */
    bool getSystem() const { return unixSystem; }

private:
    void computationEnded(QString messageLine);
    void saveContext();
    void saveStackInFile() const ;
    void readStackFromFile() const;
    void saveSettingsInFile() const;
    void readSettingsFromFile();

public:
    //! Méthode qui permet de sauvegarder les atomes identifiant des variables, programmes ou expressions dans un fichier en XML
    void saveAtomeManagerInFile();
    //! Méthode qui permet de lire dans un fichier XML les atomes identifiant des variables, programmes ou expressions
    void readAtomeManagerInFile();

    //! Fonction renvoyant l'information sur le système de l'utilisateur
    /*!
      \return Booléen concernant le système utilisateur : vrai si l'utilisateur un système Unix, non si Windows.
    */
    bool settingUnixSystem() const { return unixSystem; }
    //! Fonction qui renvoie  si le clavier doit être affiché
    /*!
      \return Booléen : vrai si le clavier doit être affiché, faux sinon
    */
    bool settingShowKeyboard() const { return showKeyboard; }
    //! Fonction qui renvoie si le son doit être joué lorsqu'un message d'erreur s'affiche
    /*!
      \return Booléen : vrai si le son doit être joué, faux sinon
    */
    bool settingPlaySound() const { return playSound; }
    //! Fonction qui renvoie le nombre de ligne à afficher dans la pile
    /*!
      \return Entier du nombre de ligne
    */
    unsigned int settingNbLines() const { return nbLines; }

    //! Setter de la propriété du système
    /*!
      \param b Booléen : vrai si le système est Unix, faux sinon
    */
    void setUnixSystem(bool b) { unixSystem = b; }
    //! Setter de la propriété de l'affichage du clavier
    /*!
      \param b Booléen : vrai si il doit être affiché, faux sinon
    */
    void setShowKeyboard(bool b) { showKeyboard = b; }
    //! Setter de la propriété du son (si faut jouer un son lors de l'affichage d'une erreur)
    /*!
      \param b Booléen : vrai si oui, faux si non
    */
    void setPlaySound(bool b) { playSound = b; }
    //! Setter de la propriété du système
    /*!
      \param b Entier du nombre de ligne à afficher dans la pile
    */
    void setNbLines(int b) { nbLines = b; }

    //! Méthode permettant de mettre à jour les réglages dans l'interface graphique
    /*!
      \param nb Entier du nombre de ligne à afficher dans la pile
      \param playS Booléen : vrai si il faut jouer un son lors de l'affichage d'une erreur
      \param showK Booléen : vrai si il faut afficher le clavier
    */
    void updateSettings(unsigned int nb, bool playS, bool showK);

    //! Fonction qui retourne les N premières litterales de la pile
    /*!
      \param n Nombre de littérale
      \return Liste des litterales à afficher
    */
    QList<const Litterale*> getNFirstLitteralsOnTheStack(unsigned int n) const;

    //! Méthode qui permet de revenir un état en arrière
    void undoFunction();
    //! Méthode qui permet de revenir un état en avant
    void redoFunction();
    //! Méthode appelée lorsque l'initialisation est terminée
    void initEnded();
};

#endif // CONTROLLER_H
