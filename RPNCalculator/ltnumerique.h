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
#include <iostream>

/** \class LTNumerique
   * \brief Classe abstraite représentant les littérales numériques
   *
   *  La classe contient une variable de type Atome et représente les litterales numériques.
   */
class LTNumerique : public LTNombre
{
protected:
    LTAtome* identificateur; /*!< Identificateur d'une littérale numérique*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe LTNumerique
         *
         *  \param a : Atome - identificateur de la litterale
         */
    LTNumerique(LTAtome* a):identificateur(a){}
    LTNumerique():identificateur(nullptr){}
    virtual void afficher (){}
    virtual const QString getText() const {}

    /*!
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    virtual LTNumerique* getChild() { return dynamic_cast<LTNumerique*>(this);}
    virtual ~LTNumerique() {}
};

/** \class LTEntier
   * \brief Littérales entieres.
   *
   *  Classe représentant les littérales entieres
   */
class LTEntier : public LTNumerique{
protected:
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
    LTEntier(LTAtome* a, int v): value(v), LTNumerique::LTNumerique(a){}
    LTEntier(int v):value(v){}
    LTEntier(QString s){
        bool ok;
        value = s.toInt(&ok, 10);
    }
    int getValue() const{ return value; }
    void afficher (){
        std::cout << value << std::endl;
    }
    const QString getText() const {
        return QString::number(value);
    }
    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    virtual LTEntier* getChild() {return dynamic_cast<LTEntier*>(this);}
    virtual ~LTEntier(){}
};

/** \class LTPossedantEntier
   * \brief Littérales possédant des littérales entiéres.
   *
   *  Littérales numériques étant composés de deux littérales entieres et d'un separateur
   */
class LTPossedantEntier : public LTNumerique{

protected:
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
    LTPossedantEntier(LTEntier e1, LTEntier e2, QString s, LTAtome* a): E1(e1), E2(e2), separateur(s), LTNumerique(a){}
    LTPossedantEntier(LTEntier e1, LTEntier e2, QString s): E1(e1), E2(e2), separateur(s){}
    int getE1() const{ return E1.getValue(); }
    int getE2() const{ return E2.getValue(); }
    QString getSeparator() const{ return separateur; }
    virtual void afficher (){
        std::cout << getE1() << getSeparator().toStdString() << getE2() << std::endl;
    }
    const QString getText() const {
        return QString(E1.getText() + getSeparator() + E2.getText());
    }

    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    virtual LTPossedantEntier* getChild() {return dynamic_cast<LTPossedantEntier*>(this);}
    virtual ~LTPossedantEntier(){}

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
    LTRationnelle(LTEntier e1, LTEntier e2, QString s, LTAtome* a): LTPossedantEntier(e1, e2, s, a){}
    LTRationnelle(LTEntier e1, LTEntier e2, QString s): LTPossedantEntier(e1, e2, s){}
    void afficher (){
        std::cout << getE1() << getSeparator().toStdString() << getE2() << std::endl;
    }
    const QString getText() const {
        return QString(E1.getText() + getSeparator() + E2.getText());
    }
    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    virtual LTRationnelle* getChild() {return dynamic_cast<LTRationnelle*>(this);}
    virtual ~LTRationnelle(){}
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
    LTReelle(LTEntier e1, LTEntier e2, QString s, LTAtome* a): LTPossedantEntier(e1, e2, s, a){}
    LTReelle(LTEntier e1, LTEntier e2, QString s): LTPossedantEntier(e1, e2, s){}
    void afficher (){
        std::cout << getE1() << getSeparator().toStdString() << getE2() << std::endl;
    }

    const QString getText() const {
        return QString(E1.getText() + getSeparator() + E2.getText());
    }

    /**
         *  \brief GetChild
         *
         *  Fonction renvoit une instance de la vrai nature de l'objet (sans polymoprhisme).
         */
    virtual LTReelle* getChild() {
        return dynamic_cast<LTReelle*>(this);
    }
    virtual ~LTReelle(){}
};
/*
inline std::ostream& operator<<(std::ostream& f, const LTEntier* e){
    f << e->getValue();
    return f;
}

inline std::ostream& operator<<(std::ostream& f, const LTPossedantEntier* e){
    f << e->getE1() << e->getSeparator().toStdString() << e->getE2() << std::endl;
    return f;
}


inline std::ostream& operator<<(std::ostream& f, const LTEntier e){
    f << e.getValue();
    return f;
}

inline std::ostream& operator<<(std::ostream& f, const LTPossedantEntier e){
    f << e.getE1() << e.getSeparator().toStdString() << e.getE2() << std::endl;
    return f;
}

*/
#endif // LTNUMERIQUE_H
