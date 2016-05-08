#ifndef LTNUMERIQUE_H
#define LTNUMERIQUE_H
/**
 * \file ltnumerique.h
 * \brief Fichier contenant les classes représentant les littérales numériques.
 * \author Jeannot.P Cartier.F
 * \version 0.1
 * \date 6 mai 2016
 */
#include "ltnombre.h"
#include "ltatome.h"
#include <QString>

/** \class LTNumerique
   * \brief Classe abstraite représentant les littérales numériques
   *
   *  La classe contient une variable de type Atome et représente les litterales numériques.
   */
class LTNumerique : public LTNombre
{
protected:
    LTAtome identificateur; /*!< Identificateur d'une littérale numérique*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe LTNumerique
         *
         *  \param a : Atome - identificateur de la litterale
         */
    LTNumerique(LTAtome a):identificateur(a){}
    /*!
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    virtual LTNumerique* getChild();
};

/** \class LTEntier
   * \brief Littérales entieres.
   *
   *  Classe représentant les littérales entieres
   */
class LTEntier : public LTNumerique{
    int value; /*!< Valeur de la littérale entière*/
public:
    /**
         *  \brief Constructeur
         *
         *  Constructeur de la classe LTEntier
         *
         *  \param a : Atome - identificateur de la litterale
         *  \param v : int - valeur de la littérale
         */
    LTEntier(LTAtome a, int v): value(v), LTNumerique::LTNumerique(a){}
    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    LTEntier* getChild() {}
};

/** \class LTPossedantEntier
   * \brief Littérales possédant des littérales entiéres.
   *
   *  Littérales numériques étant composés de deux littérales entieres et d'un separateur
   */
class LTPossedantEntier : public LTNumerique{
    LTEntier E1; /*!< Première littérale entière*/
    LTEntier E2; /*!< Deuxième littérale entière*/
    QString separateur; /*!< Séparateur */
public:
    /**
         *  \brief Constructeur
         *
         *  Constructeur de la classe LTPossedantEntier
         *
         *  \param a : Atome - identificateur de la litterale
         *  \param e1 : LTEntier - Première litterale entière
         *  \param e2 : LTEntier - Deuxième litterale entière
         *  \param s : Qstring - Séparateur
         */
    LTPossedantEntier(LTEntier e1, LTEntier e2, QString s, LTAtome a): E1(e1), E2(e2), separateur(s), LTNumerique(a){}
    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    LTPossedantEntier* getChild();

};

/** \class LTRationnelle
   * \brief Littérales rationnelles.
   */
class LTRationnelle : public LTPossedantEntier{
public:
    /**
         *  \brief Constructeur
         *
         *  Constructeur de la classe LTRationnelle
         *
         *  \param a : Atome - identificateur de la litterale
         *  \param e1 : LTEntier - Numérateur
         *  \param e2 : LTEntier - Dénominateur
         *  \param s : Qstring - Séparateur ("/")
         */
    LTRationnelle(LTEntier e1, LTEntier e2, QString s, LTAtome a): LTPossedantEntier(e1, e2, s, a){}
    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    LTRationnelle* getChild();
};

/** \class LTReelle
   * \brief Littérales réelles.
   */
class LTReelle : public LTPossedantEntier{
public:
    /**
         *  \brief Constructeur
         *
         *  Constructeur de la classe LTReelle
         *
         *  \param a : Atome - identificateur de la litterale
         *  \param e1 : LTEntier - Partie entière
         *  \param e2 : LTEntier - Partie décimale
         *  \param s : Qstring - Séparateur (".")
         */
    LTReelle(LTEntier e1, LTEntier e2, QString s, LTAtome a): LTPossedantEntier(e1, e2, s, a){}
    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    LTReelle* getChild();
};

#endif // LTNUMERIQUE_H
