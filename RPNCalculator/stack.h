#ifndef STACK_H
#define STACK_H

#include <QStack>
#include <iostream>
#include "operande.h"
#include "litterale.h"
#include "exception.h"

/*!
 * Pile permettant de sotcker les littérales utilisées dans l'application
 * \brief Classe Stack
 */
class Stack
{
    //! QList de pointeur de littérale permet de gérer celles-ci
    QList<Litterale*>stack;

public:
    //! Constructeur publique car il y a plusieurs stacks qui co-existent dans l'application
    Stack() {}
    //! Destructeur qui supprime tous les éléments de la pile
    ~Stack() {
        QList<Litterale*>::iterator j;
        for (j = stack.begin(); j != stack.end(); ++j)
            delete (*j);
    }
    //! Remplace le contenu de la pile car le contenu d'une autre pile
    inline void swap(QList<Litterale*> &other) { stack.swap(other); }

    //! Insère un élément dans la pile
    /*!
        \param t Littérale*
        \return void
    */
    void push(Litterale* t) {
        stack.insert(0, t);
    }

    //! Supprime le premier élément de la pile
    Litterale* pop() throw (ExceptionStack) {
        if (!isEmpty()) {
            Litterale* l = stack.at(0);
            stack.removeFirst();
            return l;
        }
        else {
            throw ExceptionStack(ExceptionStack::Type::CANNOT_POP_STACK_EMPTY, "Impossible de dépiler : la pile est vide");
        }
    }

    //! Annonce si l'on peut retirer N éléments de la pile
    /*!
        \param nb Nombre d'éléments à retirer
        \return bool
    */
    bool canPopItems(unsigned int nb) const {

        if (((int)size() - (int)nb) >= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    //! Annonce si la stack est vide ou non
    bool isEmpty() const {
        if (size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    //! Vide la pile
    void clear() {
        QList<Litterale*>::iterator j;
        for (j = stack.begin(); j != stack.end(); ++j) {
            stack.removeOne(*j);
        }
    }
    //! Renvoie la littérale située à un index précis
    /*!
        \param index Position de l'élément à récupérer
        \return const Litterale*
    */
    const Litterale* operator[](unsigned int index) const { return stack[index]; }

    //! Renvoie la taille de la pile
    unsigned int size() const { return stack.size(); }

    //! Crée un clone de la pile
    /*!
        \return Stack*
    */
    Stack* clone() const {
        Stack* newStack = new Stack();
        for (int j = (int)stack.size() -1; j >= 0; --j) {
            newStack->push(stack.at(j));
        }
        return newStack;
    }

    //! Renvoie la pile
    /*!
        \return QList<Litterale*>
    */
    QList<Litterale*> getStackItems() const {
        return stack;
    }
};


#endif // STACK_H
