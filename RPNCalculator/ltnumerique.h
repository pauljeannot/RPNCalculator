#ifndef LTNUMERIQUE_H
#define LTNUMERIQUE_H

#include "exception.h"
#include "ltnombre.h"
#include <QString>
#include <QStringList>
#include <iostream>

class LTComplexe;
class LTEntier;
class LTRationnelle;
class LTReelle;
class LTNumerique;
class LTNombre;
class LTAtome;

//===============================================================================================
//
//                              LTNumerique
//
//===============================================================================================

//! Classe abstraite de litterales numériques, qui regroupe les litterales entieres, réelles et rationnelles
class LTNumerique : public LTNombre
{
protected:
    LTAtome* identificateur;

public:

    //======================================================
    // Basic methods
    //======================================================

    //! Constructeur
    /*!
      \param a Atome identificateur
    */
    LTNumerique(LTAtome* a = 0):identificateur(a) {

    }

    //! Constructeur
    /*!
      \param n Variable à ajouter
      \param a Atome identificateur
    */
    LTNumerique(LTNumerique* n, LTAtome* a = 0):identificateur(a) {

    }

    //! Destructeur
    virtual ~LTNumerique() {

    }

    //======================================================
    // Getters
    //======================================================

    //! Getter pour l'atome identificateur
    /*!
      \return LTAtome identificateur de la LTNumerique
    */
    virtual LTAtome* getAtome() const { return identificateur; }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const = 0;

    virtual QString getText() const = 0;

    virtual LTNumerique* clone() const = 0;

    virtual LTNumerique* simplifier() = 0;

    //======================================================
    // Operator methods
    //======================================================

    // NEG
    //! Opérateur NEG
    /*!
      \return LTNumerique créée
    */
    virtual LTNumerique* operator--() = 0;

    // OPAddition
    virtual LTNumerique* operator+(LTNumerique* p) = 0;
    virtual LTComplexe* operator+(LTComplexe* p) = 0;

    // OPSoustraction
    virtual LTNumerique* operator-(LTNumerique* p) = 0;
    virtual LTComplexe* operator-(LTComplexe* p) = 0;

    // OPMultiplication
    virtual LTNumerique* operator*(LTNumerique* p) = 0;
    virtual LTComplexe* operator*(LTComplexe* p) = 0;

    // OPDivision
    virtual LTNumerique* operator/(LTNumerique* p) = 0;
    virtual LTComplexe* operator/(LTComplexe* p) = 0;

    // OPEgal
    //! Egalité entre 2 LTNumerique
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator== (LTNumerique& l1, LTNumerique& l2);

    // OPDifferent
    //! Différence entre 2 LTNumerique
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator!= (LTNumerique& l1, LTNumerique& l2);

    // OPInferieur
    //! Opérateur inférieur strictement entre 2 LTNumerique
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator< (LTNumerique& l1, LTNumerique& l2);

    // OPInferieurEgal
    //! Opérateur inférieur ou égal entre 2 LTNumerique
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator<= (LTNumerique& l1, LTNumerique& l2);

    // OPSuperieur
    //! Opérateur supérieur entre 2 LTNumerique
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator> (LTNumerique& l1, LTNumerique& l2);

    // OPSuperieurEgal
    //! Opérateur supérieur ou égal entre 2 LTNumerique
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator>= (LTNumerique& l1, LTNumerique& l2);
};


//===============================================================================================
//
//                              LTEntier
//
//===============================================================================================

//! Classe représentant un nombre entier
class LTEntier : public LTNumerique{

    int value;

public:

    //! Variable statique représentant la valeur Zero d'un entier
    /*!
      \return Valeur Zero
    */
    static const LTEntier zero;

    //======================================================
    // Basic methods
    //======================================================

    //! Constructeur
    /*!
      \param v Valeur
      \param a Atome identificateur
    */
    LTEntier(int v, LTAtome* a = 0):LTNumerique(a), value(v) {

    }

    //! Constructeur
    /*!
      \param v Texte représentant l'entier à créer
      \param a Atome identificateur
    */
    LTEntier(QString v, LTAtome* a = 0):LTNumerique(a), value(0) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->value = flag ? tmp : 0;
    }

    //! Constructeur par recopie
    /*!
      \param e Entier à recopier
      \param a Atome identificateur
    */
    LTEntier(const LTEntier& e, LTAtome* a = 0):LTNumerique(a), value(e.getValue()) {

    }

    //! Destructeur
    virtual ~LTEntier() {

    }

    //======================================================
    // Getter/setter
    //======================================================

    //! Getter de la valeur de l'entier
    /*!
      \return Valeur de l'entier
    */
    int getValue() const {
        return value;
    }

    //! Setter de la valeur de l'entier
    /*!
      \param v Valeur que l'entier doit prendre
    */
    void setValue(int v) {
        this->value = v;
    }

    //! Setter de la valeur de l'entier
    /*!
      \param v Valeur que l'entier doit prendre
    */
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

    virtual LTEntier* clone() const;

    virtual LTEntier* simplifier() {
        return this;
    }

    //======================================================
    // Operator methods
    //======================================================

    // NEG
    virtual LTEntier* operator--();

    // OPAddition
    virtual LTNumerique* operator+(LTNumerique* p);
    virtual LTComplexe* operator+(LTComplexe* p);

    // OPSoustraction
    virtual LTNumerique* operator-(LTNumerique* p);
    virtual LTComplexe* operator-(LTComplexe* p);

    // OPMultiplication
    virtual LTNumerique* operator*(LTNumerique* p);
    virtual LTComplexe* operator*(LTComplexe* p);

    // OPDivision
    virtual LTNumerique* operator/(LTNumerique* p);
    virtual LTComplexe* operator/(LTComplexe* p);

    // OPEgal
    //! Opérateur égalité entre un entier et un entier
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator== (LTEntier& l1, LTEntier& l2);
    //! Opérateur égalité entre un entier et un réel
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator== (LTEntier& l1, LTReelle& l2);
    //! Opérateur égalité entre un entier et un rationnel
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator== (LTEntier& l1, LTRationnelle& l2);

    // OPInferieur
    //! Opérateur inférieur strictement entre un entier et un entier
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator< (LTEntier& l1, LTEntier& l2);
    //! Opérateur inférieur strictement entre un entier et un réel
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator< (LTEntier& l1, LTReelle& l2);
    //! Opérateur inférieur strictement entre un entier et un rationnel
    /*!
      \param l1 1ère argument de l'opérateur
      \param l2 2ème argument de l'opérateur
      \return Booléen
    */
    friend bool operator< (LTEntier& l1, LTRationnelle& l2);

    //OPAnd
    //! Opérateur ET logique entre un entier et un entier
    /*!
      \param p 2ème argument de l'opérateur
      \return Booléen
    */
    virtual bool operator&&(LTEntier* p) const;
    //OPOr
    //! Opérateur OU logique entre un entier et un entier
    /*!
      \param p 2ème argument de l'opérateur
      \return Booléen
    */
    virtual bool operator||(LTEntier* p) const;
    //OPNot
    //! Opérateur NOT logique entre un entier et un entier
    /*!
      \param p 2ème argument de l'opérateur
      \return Booléen
    */
    virtual bool operator!() const;
};


//===============================================================================================
//
//                              LTRationnelle
//
//===============================================================================================

//! Classe représentant un nombre rationnel
class LTRationnelle : public LTNumerique{

    int E1;
    int E2;
    QString separator;

public:

    /*!
     * \brief Représentation d'un rationnelle avec pour valeur Zero
     */
    static const LTRationnelle zero;

    //======================================================
    // Basic methods
    //======================================================

    //! Constructeur
    /*!
      \param v1 Valeur du numérateur
      \param v2 Valeur du dénominateur
      \param a Atome identificateur
    */
    LTRationnelle(int v1, int v2, LTAtome* a = 0):LTNumerique(a), E1(v1), E2(0), separator("/") {

        if (v2 == 0) {
            throw ExceptionRationnelle(ExceptionRationnelle::Type::CANNOT_HAVE_DENUM_ZERO, "Le dénumérateur ne peut être égal à 0.");
        }
        else {
                if (v2 < 0) {
                    this->E2 = -v2;
                    this->E1 = -v1;
                }
                else
                    this->E2 = v2;
        }
    }

    //! Constructeur
    /*!
      \param v1 Valeur texte du numérateur
      \param v2 Valeur texte du dénominateur
      \param a Atome identificateur
    */
    LTRationnelle(QString v1, QString v2, LTAtome* a = 0):LTNumerique(a), separator("/") {

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

    //! Constructeur par recopie
    /*!
      \param r Valeur du rationnel à copier
      \param a Atome identificateur
    */
    LTRationnelle(const LTRationnelle& r, LTAtome* a = 0):LTNumerique(a), E1(r.getE1()), E2(r.getE2()), separator("/") {

    }

    //! Constructeur de conversion d'un entier
    /*!
      \param r Valeur du rationnel à copier
      \param a Atome identificateur
    */
    LTRationnelle(const LTEntier& r, LTAtome* a = 0):LTNumerique(a), E1(r.getValue()*this->getE2()), E2(this->getE2()), separator("/") {

    }

    //! Destructeur
    virtual ~LTRationnelle() {

    }

    //! Calcul du pgcd
    /*!
      \param a Valeur 1
      \param b Valeur 2
    */
    int pgcd(unsigned int a , unsigned int b )
    {
        int r = 0;
        if(a <b)
            std::swap(a, b);

        if((r = a%b) == 0)
            return b;
        else
            return pgcd(b, r);
    }

    //======================================================
    // Getter/setter
    //======================================================

    //! Getter du numérateur
    /*!
      \return Numérateur
    */
    int getE1() const {
        return E1;
    }

    //! Setter du numérateur
    /*!
      \param v Valeur à donner
    */
    void setE1(int v) {
        this->E1 = v;
    }

    //! Getter du dénominateur
    /*!
      \return Dénominateur
    */
    int getE2() const {
        return E2;
    }

    //! Setter du dénominateur
    /*!
      \param v Valeur à donner
    */
    void setE2(int v) {
        this->E2 = v;
    }

    //! Setter du numérateur
    /*!
      \param v Valeur textuelle à donner
    */
    void setE1(QString v) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->E1 = flag ? tmp : 0;
    }

    //! Setter du dénominateur
    /*!
      \param v Valeur textuelle à donner
    */
    void setE2(QString v) {
        bool flag;
        int tmp = v.toInt(&flag, 10);
        this->E2 = flag ? tmp : 1;
    }

    //! Getter du séparateur
    /*!
      \return Retourne le séparateur /
    */
    QString getSeparator() const {
        return this->separator;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    virtual LTRationnelle* clone() const;

    virtual LTNumerique* simplifier() {

        int res = pgcd((unsigned int)this->getE1(), (unsigned int)this->getE2());
        this->E1 = this->getE1() / res;
        this->E2 = this->getE2() / res;

        if(this->getE2() == 1) {
            return new LTEntier(this->getE1(), this->getAtome());
        }
        else {
            return this;
        }
    }

    //======================================================
    // Operator methods
    //======================================================

    // NEG
    virtual LTRationnelle* operator--();

    // OPAddition
    virtual LTNumerique* operator+(LTNumerique* p);
    virtual LTComplexe* operator+(LTComplexe* p);

    // OPSoustraction
    virtual LTNumerique* operator-(LTNumerique* p);
    virtual LTComplexe* operator-(LTComplexe* p);

    // OPMultiplication
    virtual LTNumerique* operator*(LTNumerique* p);
    virtual LTComplexe* operator*(LTComplexe* p);

    // OPDivision
    virtual LTNumerique* operator/(LTNumerique* p);
    virtual LTComplexe* operator/(LTComplexe* p);

    // OPEgal
    /*!
     * \brief Opérateur d'égalité entre un rationnel et un rationnel
     * \param l1 premier paramètre
     * \param l2 second paramètre
     * \return
     */
    friend bool operator== (LTRationnelle& l1, LTRationnelle& l2);
    /*!
     * \brief Opérateur d'égalité entre un rationnel et un entier
     * \param l1 premier paramètre
     * \param l2 second paramètre
     * \return
     */
    friend bool operator== (LTRationnelle& l1, LTEntier& l2);
    /*!
     * \brief Opérateur d'égalité entre un rationnel et un entier
     * \param l1 premier paramètre
     * \param l2 second paramètre
     * \return
     */
    friend bool operator== (LTRationnelle& l1, LTReelle& l2);

    // OPInferieur
    /*!
     * \brief Opérateur strictement inférieur entre un rationnel et un rationnel
     * \param l1 premier paramètre
     * \param l2 second paramètre
     * \return
     */
    friend bool operator< (LTRationnelle& l1, LTRationnelle& l2);
    /*!
     * \brief Opérateur strictement inférieur entre un rationnel et un entier
     * \param l1 premier paramètre
     * \param l2 second paramètre
     * \return
     */
    friend bool operator< (LTRationnelle& l1, LTEntier& l2);
    /*!
     * \brief Opérateur strictement inférieur entre un rationnel et un reel
     * \param l1 premier paramètre
     * \param l2 second paramètre
     * \return
     */
    friend bool operator< (LTRationnelle& l1, LTReelle& l2);
};


//===============================================================================================
//
//                              LTReelle
//
//===============================================================================================

/*!
 * \brief Classe représentant un réel
 */
class LTReelle: public LTNumerique{

    float value;
    QString separator;

public:

    /*!
     * \brief Variable statique représentant un réel ayant pour valeur zero.
     */
    static const LTReelle zero;

    //======================================================
    // Basic methods
    //======================================================

    /*!
     * \brief Constructeur
     * \param v Valeur
     * \param a Atome identificateur
     */
    LTReelle(float v, LTAtome* a = 0):LTNumerique(a), value(v), separator(".") {

    }

    /*!
     * \brief Constructeur
     * \param v Valeur textuelle
     * \param a Atome identificateur
     */
    LTReelle(QString v, LTAtome* a = 0):LTNumerique(a), separator(".") {

        bool flag;
        float tmp = v.toFloat(&flag);
        if (!flag) {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_LITTERALE , "Un réél ne doit être composé que de chiffres.");
        }
        else {
            this->value = tmp;
        }
    }

    /*!
     * \brief Constructeur de conversion prennant un rationnel
     * \param r Rationnel à convertir
     */
    LTReelle(LTRationnelle* r):LTNumerique(r->getAtome()), separator(".") {
        float num = (float)(r->getE1());
        float den = (float)(r->getE2());
        float res = num / den;
        this->value = res;
    }

    /*!
     * \brief Constructeur par recopie
     * \param r Réel à copier
     * \param a Atome identificateur
     */
    LTReelle(const LTReelle& r, LTAtome* a= 0):LTNumerique(a), value(r.getValue()), separator(".") {

    }

    /*!
     * \brief Constructeur de conversion prennant un entier
     * \param r Entier à convertir
     * \param a Atome identificateur
     */
    LTReelle(const LTEntier& r, LTAtome* a = 0):LTNumerique(a), value((float)r.getValue()), separator(".") {

    }

    /*!
     * \brief Destructeur
     */
    virtual ~LTReelle() {

    }

    //======================================================
    // Getter/setter
    //======================================================

    /*!
     * \brief Getter de la valeur
     * \return Valeur
     */
    float getValue() const {
        return value;
    }

    /*!
     * \brief Setter du réel
     * \param Valeur
     */
    void setValue(float v) {
        this->value = v;
    }

    /*!
     * \brief Setter textuel du réel
     * \param v Texte du réel
     */
    void setValue(QString v) {
        bool flag;
        float tmp = v.toFloat(&flag);
        this->value = flag ? tmp : 0.0;
    }

    // Renvoie la partie entière
    /*!
     * \brief Getter de la partie entière
     * \return Partie entière
     */
    int getE1() const {
        return (int)value;
    }

    //Renvoie la partie décimale sous forme 0.xxxxx
    /*!
     * \brief Getter de la partie décimale
     * \return Partie décimale
     */
    float getE2() const {
        return (this->getValue() - (float)getE1());
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    virtual LTReelle* clone() const;

    virtual LTNumerique* simplifier() {

        if((float)this->getE1() == this->getValue()) {
            return new LTEntier(this->getE1(), this->getAtome());
        }
        else {
            return this;
        }
    }

    //======================================================
    // Operator methods
    //======================================================

    virtual LTReelle* operator--();

    // OPAddition
    virtual LTNumerique* operator+(LTNumerique* p);
    virtual LTComplexe* operator+(LTComplexe* p);

    // OPSoustraction
    virtual LTNumerique* operator-(LTNumerique* p);
    virtual LTComplexe* operator-(LTComplexe* p);

    // OPMultiplication
    virtual LTNumerique* operator*(LTNumerique* p);
    virtual LTComplexe* operator*(LTComplexe* p);

    // OPDivision
    virtual LTNumerique* operator/(LTNumerique* p);
    virtual LTComplexe* operator/(LTComplexe* p);

    // OPEgal
    /*!
     * \brief Opérateur d'égalité entre un réel et un réel
     * \param l1
     * \param l2
     * \return
     */
    friend bool operator== (LTReelle& l1, LTReelle& l2);
    /*!
     * \brief Opérateur d'égalité entre un réel et un rationnel
     * \param l1
     * \param l2
     * \return
     */
    friend bool operator== (LTReelle& l1, LTRationnelle& l2);
    /*!
     * \brief Opérateur d'égalité entre un réel et un entier
     * \param l1
     * \param l2
     * \return
     */
    friend bool operator== (LTReelle& l1, LTEntier& l2);

    // OPInferieur
    /*!
     * \brief Opérateur inférieur strictement entre un réel et un réel
     * \param l1
     * \param l2
     * \return
     */
    friend bool operator< (LTReelle& l1, LTReelle& l2);
    /*!
     * \brief Opérateur inférieur strictement entre un réel et un rationnel
     * \param l1
     * \param l2
     * \return
     */
    friend bool operator< (LTReelle& l1, LTRationnelle& l2);
    /*!
     * \brief Opérateur inférieur strictement entre un réel et un entier
     * \param l1
     * \param l2
     * \return
     */
    friend bool operator< (LTReelle& l1, LTEntier& l2);
};

#endif // LTNUMERIQUE_H
