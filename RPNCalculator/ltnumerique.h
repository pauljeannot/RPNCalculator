#ifndef LTNUMERIQUE_H
#define LTNUMERIQUE_H

#include "exception.h"
#include "ltnumerique.h"
#include "ltnombre.h"
#include "ltatome.h"
#include <QString>
#include <QStringList>
#include <iostream>

class LTComplexe;
class LTEntier;
class LTRationnelle;
class LTReelle;
class LTNumerique;

//===============================================================================================
//
//                              LTNumerique
//
//===============================================================================================
class LTNumerique : public LTNombre
{
protected:
    LTAtome* identificateur;

public:

    //======================================================
    // Basic methods
    //======================================================

    LTNumerique(LTAtome* a = 0):identificateur(a) {

    }

    virtual ~LTNumerique() {

    }

    //======================================================
    // Getters
    //======================================================

    LTAtome* getAtome() const { return identificateur; }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNumerique* operator--() = 0;

    virtual LTNombre* operator+(LTNombre* p) = 0;

};


//===============================================================================================
//
//                              LTEntier
//
//===============================================================================================

class LTEntier : public LTNumerique{

    int value;

public:

    //======================================================
    // Basic methods
    //======================================================

    LTEntier(int v, LTAtome* a = 0):LTNumerique(a) {
        this->value = v;
    }

    LTEntier(QString v, LTAtome* a = 0):LTNumerique(a) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->value = flag ? tmp : 0;
    }

    virtual ~LTEntier() {

    }

    //======================================================
    // Getter/setter
    //======================================================

    int getValue() const {
        return value;
    }

    void setValue(int v) {
        this->value = v;
    }

    void setValue(QString v) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->value = flag ? tmp : 0;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre* operator+(LTNombre* p);

    virtual LTEntier* operator--();
};


//===============================================================================================
//
//                              LTRationnelle
//
//===============================================================================================

class LTRationnelle : public LTNumerique{

    int E1;
    int E2;
    QString separator;

public:

    //======================================================
    // Basic methods
    //======================================================

    LTRationnelle(int v1, int v2, LTAtome* a = 0):LTNumerique(a) {

        if (v2 == 0) {
            throw ExceptionRationnelle(ExceptionRationnelle::Type::CANNOT_HAVE_DENUM_ZERO, "Le dénumérateur ne peut être égal à 0.");
        }

        this->E1 = v1;
        this->E2 = v2;
        this->separator = "/";
    }

    LTRationnelle(QString v1, QString v2, LTAtome* a = 0):LTNumerique(a) {

        this->separator = "/";

        // Numérateur
        bool flag;
        int tmp = v1.toInt(&flag, 10);
        // Si le cast du numérateur échoue
        if (!flag) {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE , "Le numérateur et le dénominateur d'une littérale rationnelle doivent être des entiers.");
        }
        else {
            this->E1 = tmp;
        }

        tmp = v2.toInt(&flag, 10);
        // Si le cast du dénominateur échoue
        if (!flag) {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE , "Le numérateur et le dénominateur d'une littérale rationnelle doivent être des entiers.");
        }
        // Si le dénominateur vaut 0
        else if (tmp == 0) {
            throw ExceptionRationnelle(ExceptionRationnelle::Type::CANNOT_HAVE_DENUM_ZERO, "Le dénumérateur ne peut être égal à 0.");
        }
        else {
            this->E2 = tmp;
        }
    }

    virtual ~LTRationnelle() {

    }

    //======================================================
    // Getter/setter
    //======================================================

    int getE1() const {
        return E1;
    }

    void setE1(int v) {
        this->E1 = v;
    }

    int getE2() const {
        return E2;
    }

    void setE2(int v) {
        this->E2 = v;
    }

    void setE1(QString v) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->E1 = flag ? tmp : 0;
    }

    void setE2(QString v) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->E2 = flag ? tmp : 1;
    }

    QString getSeparator() const {
        return this->separator;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre* operator+(LTNombre* p);

    virtual LTRationnelle* operator--();

};


//===============================================================================================
//
//                              LTReelle
//
//===============================================================================================

class LTReelle: public LTNumerique{

    float value;
    QString separator;

public:

    //======================================================
    // Basic methods
    //======================================================

    LTReelle(float v, LTAtome* a = 0):LTNumerique(a) {
        this->value = v;
        this->separator = ".";
    }

    LTReelle(QString v, LTAtome* a = 0):LTNumerique(a) {

        bool flag;
        float tmp = v.toFloat(&flag);
        if (!flag) {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE , "Un réél ne doit être composé que de chiffres.");
        }
        else {
            this->value = tmp;
        }
    }

    LTReelle(LTRationnelle* r):LTNumerique(r->getAtome()) {
        float num = (float)(r->getE1());
        float den = (float)(r->getE2());
        float res = num / den;
        this->value = res;
        this->separator = ".";
    }

    virtual ~LTReelle() {

    }

    //======================================================
    // Getter/setter
    //======================================================

    float getValue() const {
        return value;
    }

    void setValue(float v) {
        this->value = v;
    }

    void setValue(QString v) {
        bool flag;
        float tmp = v.toFloat(&flag);
        this->value = flag ? tmp : 0.0;
    }

    // Renvoie la partie entière
    int getE1() const {
        return (int)value;
    }

    //Renvoie la partie décimale sous forme 0.xxxxx
    float getE2() const {

        float a = 0.01;
        int b = (int)a;
        float c = a - (float)b;
        return c;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre* operator+(LTNombre* p);

    virtual LTReelle* operator--();

};

#endif // LTNUMERIQUE_H
