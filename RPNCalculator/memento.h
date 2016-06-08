#ifndef MEMENTO_H
#define MEMENTO_H

#include "stack.h"

/*!
 * \brief Classe du design pattern Memento
 */
class Memento
{

    Stack* stack;

public:
    /*!
     * \brief Constructeur
     * \param s Pile à sauvegarder dans le Memento
     */
    Memento(Stack* s):stack(s) { }
    /*!
     * \brief Getter de la pile
     * \return Pile
     */
    Stack* getStack() { return stack; }
};

/*!
 * \brief Classe du design pattern Memento représentant le CareTaker
 */
class CareTaker
{

    QList<Memento> mementos;

public:
    /*!
     * \brief Constructeur
     */
    CareTaker() {}
    /*!
     * \brief Ajouter un memento
     * \param m Memento à ajouter
     * \param index Index
     */
    void addMemento(Memento m, int index) {
        int max = this->size();
        if(this->size() > index) {
            for (unsigned int i = index; i < max; i++) {
                this->mementos.removeLast();
            }
        }
        mementos.append(m);
    }

    /*!
     * \brief Getter d'un memento à un index spécifique
     * \param index Index
     * \return Memento
     */
    Memento getMemento(int index) { return mementos.at(index); }

    /*!
     * \brief Nombre de mementos contenus dans le CareTaker
     * \return Nombre
     */
    int size() { return mementos.size(); }
};

/*!
 * \brief Classe du design pattern Memento représentant l'Originator
 */
class Originator
{

    Stack* stack;

public:
    /*!
     * \brief Constructeur
     */
    Originator():stack(nullptr) {}

    /*!
     * \brief Setter de la pile
     * \param s Pile
     */
    void setStack(Stack* s) { this->stack = s; }

    /*!
     * \brief Permet de sauvegarder l'état en un Memento
     * \return Memento
     */
    Memento storeInMemento() { return Memento(stack); }

    /*!
     * \brief Restaure un Memento depuis
     * \param m Memento
     * \return Pile
     */
    Stack* restoreFromMemento(Memento m) { m.getStack(); }

};

#endif // MEMENTO_H
