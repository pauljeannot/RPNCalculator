#ifndef OPERANDEFACTORY_H
#define OPERANDEFACTORY_H
#include "operande.h"
#include "ltnumerique.h"
#include "opnum_ltsansexpression.h"
#include <QString>

/*!
 * \brief Operande Factory qui crééent des objets (Litterales et Operateurs)
 */
class OperandeFactory{
 public:
    /*!
      * \brief Créé une opérande à partir d'un texte
      * \param Texte à transformer en opérande
      * \return Operande créée
      */
     static Operande* NewOperande(const QString& str);

     /*!
      * \brief Créé une litterale (sauf expression) à partir d'un texte
      * \param str Texte
      * \return Litterale sans expression
      */
     static OPNum_LTSansExpression* NewOPNum_LTSansExpression(const QString& str);

     /*!
      * \brief Fonction qui renvoie vrai si le texte correspond à un opérateur
      * \param Texte
      * \return Booléen
      */
     static bool isOperator(QString C);

     /*!
      * \brief Fonction qui renvoie vrai si le texte est une litterale
      * \param symbol Texte
      * \return Booléen
      */
     static bool isLitterale(const QString& symbol);

     /*!
      * \brief Poids de l'opérateur
      * \param arg Texte
      * \return Entier
      */
     static int operatorWeight(QString arg);

     /*!
      * \brief Renvoie 0 ou 1 selon le fait que l'opérateur a et plus lourd que le b
      * \param a Opérateur 1
      * \param b Opérateur 2
      * \return  Entier
      */
     static int operateurPrioritaire(QString a, QString b);

     /*!
      * \brief Conversion entre une string correspondant à une expression infix vers postfix
      * \param expr Texte
      * \return Texte
      */
     static QString infixToPostfix(QString expr);

     /*!
      * \brief Permet d'ajouter un espace entre chaque opérateur
      * \param str Texte
      * \return Texte espacé
      */
     static QString addSpace(QString str);
 };

#endif // OPERANDEFACTORY_H
