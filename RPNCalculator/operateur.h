#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "operande.h"
#include "litterale.h"
#include <QString>
#include <iostream>

/*!
 * \brief Classe abstraite des opérateurs
 */
class Operateur : virtual public Operande
{
protected:
    QString value;
    int arite;
public:
    /*!
     * \brief Constructeur
     * \param val Valeur textuelle de l'opérateur
     * \param a Arité
     */
    Operateur(QString val, int a):value(val), arite(a){}
    virtual void afficher() const { std::cout << value.toStdString() << std::endl; }

    /*!
     * \brief Effectue le calcul de l'opérateur, sans prendre de paramètre
     * \return Litterale résultat
     */
    virtual Litterale* compute() = 0;
    /*!
     * \brief Effectue le calcul de l'opérateur en prennant 1 paramètre
     * \return Litterale résultat
     */
    virtual Litterale* compute(Litterale* l) = 0;
    /*!
     * \brief Effectue le calcul de l'opérateur, en prennant 2 paramètres
     * \return Litterale résultat
     */
    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;

    /*!
     * \brief Getter de l'arité
     * \return Arité
     */
    inline int getArite() { return arite; }
    /*!
     * \brief Getter du texte de l'opérateur
     * \return Texte
     */
    virtual QString getText() const { return value; }
    virtual Operateur* clone() const = 0;
};

#endif // OPERATEUR_H
