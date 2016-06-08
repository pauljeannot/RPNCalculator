#ifndef COMPUTER_H
#define COMPUTER_H

#include <QList>
#include "operateur.h"
#include "litterale.h"

//! La classe Computer est un singleton qui s'occupe du calcul des litterales avec un opérateur */
class Computer
{

    static Computer* instance;
    Computer():lastOp(nullptr), lastArgs(new QList<Litterale*>) {}
    ~Computer() {}
    Computer(const Computer& c);

    Operateur* lastOp;
    QList<Litterale*>* lastArgs;

    void saveContext(Operateur* op, Litterale* l1 = 0, Litterale* l2 = 0);

public :
    //! Getter de l'instance du singleton.
    /*!
      \return Instance de Computer
    */
    static Computer& getInstance() {
        if (!instance) instance = new Computer();
        return *instance;
    }

    //! Destructeur de l'instance du singleton
    static void freeInstance() { if (instance) delete instance; }

    //! Méthode qui permet d'appliquer un opérateur, ne prennant aucun paramètre.
    /*!
      \param op Opérateur à appliquer
      \return Littérale résultat
    */
    Litterale *compute(Operateur* op);
    //! Méthode qui permet d'appliquer un opérateur, s'appliquant sur un paramètre.
    /*!
      \param op Opérateur à appliquer
      \param l1 Littérale sur lequel l'opérateur s'applique
      \return Littérale résultat
    */
    Litterale *compute(Operateur* op, Litterale* l1);
    //! Méthode qui permet d'appliquer un opérateur, s'appliquant sur 2 paramètres.
    /*!
      \param op Opérateur à appliquer
      \param l1 Littérale sur lequel l'opérateur s'applique
      \param l2 Littérale sur lequel l'opérateur s'applique
      \return Littérale résultat
    */
    Litterale* compute(Operateur* op, Litterale* l1, Litterale* l2);

    //! Permet de récupérer le dernier opérateur utilisé
    /*!
      \return Dernier opérateur utilisé
    */
    Operateur* getLastOp() {
        return lastOp;
    }

    //! Méthode qui permet de récupérer les dernières litterales utilisées avec le dernier opérateur
    /*!
      \return Liste des dernières litterales utilisées
    */
    QList<Litterale*>* getLastArgs() {
        return lastArgs;
    }

};

#endif // COMPUTER_H
