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
    int E1;
    int E2;
    QString separateur;

public:

    //======================================================
    // Basic methods
    //======================================================

    LTNumerique(int e1, LTAtome* a = 0, int e2 = 0, QString s = ""):E1(e1), identificateur(a), E2(e2), separateur(s) {

    }

    virtual ~LTNumerique() {

    }

    //======================================================
    // Getters
    //======================================================

    int getE1() const { return E1; }
    int getE2() const { return E2; }
    void setE1(int v) { this->E1 = v; }
    void setE2(int v) { this->E2 = v; }
    QString getSeparator() const { return separateur; }
    LTAtome* getAtome() const { return identificateur; }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        std::cout << getE1() << getSeparator().toStdString() << getE2() << std::endl;
    }

    virtual QString getText() const {
        return QString(QString::number(E1) + getSeparator() + QString::number(E2));
    }

    virtual LTNumerique* getChild() {
        return dynamic_cast<LTNumerique*>(this);
    }

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNumerique* operator--() {
        this->E1 = -getE1();
        return this;
    }

    virtual LTNombre* operator+(LTNombre* p) = 0;

};


//===============================================================================================
//
//                              LTEntier
//
//===============================================================================================

class LTEntier : public LTNumerique{

public:

    //======================================================
    // Basic methods
    //======================================================

    LTEntier(int v, LTAtome* a = 0):LTNumerique(v, a) {

    }

    LTEntier(QString v, LTAtome* a = 0):LTNumerique(0, a) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->E1 = flag ? tmp : 0;
    }

    virtual ~LTEntier() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        std::cout << getE1() << std::endl;
    }

    QString getText() const {
        return QString::number(E1);
    }

    virtual LTEntier* getChild() {
        return dynamic_cast<LTEntier*>(this);
    }

    virtual const LTEntier* zero() const {
        return new LTEntier(0);
    }

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre* operator+(LTNombre* p);
};


//===============================================================================================
//
//                              LTRationnelle
//
//===============================================================================================

class LTRationnelle : public LTNumerique{

public:

    //======================================================
    // Basic methods
    //======================================================

    LTRationnelle(int v1, int v2, LTAtome* a = 0):LTNumerique(v1, a, v2, "/") {
        if (v2 == 0) {
            throw ExceptionRationnelle(ExceptionRationnelle::Type::CANNOT_HAVE_DENUM_ZERO, "Le dénumérateur ne peut être égal à 0.");
        }
    }

    LTRationnelle(QString v1, QString v2, LTAtome* a = 0):LTNumerique(0, a, 1, "/") {
        bool flag;
        int tmp = v1.toInt(&flag, 10);
        this->E1 = flag ? tmp : 0;

        tmp = v2.toInt(&flag, 10);
        // Si c'est un chiffre et qu'il vaut 0 : exception : pas de division par 0
        if (flag == true && tmp == 0) {
            throw ExceptionRationnelle(ExceptionRationnelle::Type::CANNOT_HAVE_DENUM_ZERO, "Le dénumérateur ne peut être égal à 0.");
        }
        // Sinon si c'est bien un chiffre mais différent de 0 : on stocke
        else if (flag == true) {
            this->E2 = tmp;
        }
        // Si ce n'est pas un chiffre : exception
        else {
            std::cout << "in" << std::endl;
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE , "Le numérateur et le dénominateur d'une littérale rationnelle doivent être des entiers.");
        }
    }

    virtual ~LTRationnelle() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual LTRationnelle* getChild() {
        return dynamic_cast<LTRationnelle*>(this);
    }

    virtual const LTRationnelle* zero() const {
        return new LTRationnelle(0, 1);
    }

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre* operator+(LTNombre* p);

};


//===============================================================================================
//
//                              LTReelle
//
//===============================================================================================

class LTReelle: public LTNumerique{

public:

    //======================================================
    // Basic methods
    //======================================================

    LTReelle(int v1, int v2, LTAtome* a = 0):LTNumerique(v1, a, v2, ".") {

    }

    LTReelle(QString v1, QString v2, LTAtome* a = 0):LTNumerique(0, a, 1, ".") {
//        bool flag;
//        int tmp = v1.toInt(&flag, 10);
//        this->E1 = flag ? tmp : 0;

//        float tmp2 = v2.toFloat(&flag);
//        QString s;
//        s.setNum(tmp2);
//        QStringList list = s.split(".");

//        int res3 = list.at(1).toFloat();


//        this->E2 = flag ? tmp3 : 0;
    }

    LTReelle(LTRationnelle* r):LTNumerique(0, r->getAtome(), 0, ".") {
        float num = (float)(r->getE1());
        float den = (float)(r->getE2());
        float res = num / den;

        QString res2;
        res2.setNum(res);
        QStringList list = res2.split(".");
        int res3 = list.at(1).toFloat();
        this->E1 = (int)res;
        this->E2 = res3;
    }

    virtual ~LTReelle() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual LTReelle* getChild() {
        return dynamic_cast<LTReelle*>(this);
    }

    virtual const LTReelle* zero() const {
        return new LTReelle(0, 0);
    }

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre* operator+(LTNombre* p);

};

#endif // LTNUMERIQUE_H
