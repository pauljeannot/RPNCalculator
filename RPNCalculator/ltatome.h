#ifndef ATOME_H
#define ATOME_H
#include "ltsansexpression.h"
#include "ltexpression.h"
#include "ltnombre.h"
#include <QString>
#include <QMap>
#include <iostream>

//! Classe d'une litterale atome
class LTAtome : public LTSansExpression
{
public:
    //! Enum concernant la nature de l'atome
    enum EnumNature {
        IDVAR,/*!< Identificateur d'une variable */
        IDPROG,/*!< Identificateur d'un programme */
        IDEXP,/*!< Identificateur d'une expression */
        INDEFINI/*!< Identificateur indéfini */
    };

private:
    QString value;
    EnumNature Nature;
    Litterale* pointer;

public:

    //======================================================
    // Basic methods
    //======================================================

    //! Constructeur de l'atome
    /*!
      \param v Nom de l'atome
      \param n Nature de l'atome
      \param p Litterale associée
    */
    LTAtome(QString v, EnumNature n, Litterale* p = nullptr): value(v), Nature(n), pointer(p) {

    }

    //! Constructeur de l'atome
    /*!
      \param v Nom de l'atome
      \param p Litterale associée
    */
    LTAtome(QString v, Litterale* p = nullptr):value(v), Nature(INDEFINI), pointer(p) {

    }

    //! Destructeur de l'atome
    virtual ~LTAtome() {

    }

    //! Définir la litterale pointée par l'atome
    /*!
      \param l Litterale pointée par l'atome
    */
    void setPointer(Litterale* l);

    //! Renvoie la nature de l'atome
    /*!
      \return Nature de l'atome
    */
    EnumNature getNature() const;

    //! Renvoie la litterale pointée par l'atome
    /*!
      \return Litterale pointée par l'atome
    */
    Litterale* getPointer() const;

    //! Renvoie la nature de l'atome au format texte
    /*!
      \return Nature de l'atome au format texte
    */
    QString getEnumString() const {
        switch (Nature) {
        case IDVAR:
            return "IDVAR";
            break;
        case IDPROG:
            return "IDPROG";
            break;
        case IDEXP:
            return "IDEXP";
            break;
        case INDEFINI:
            return "INDEFINI";
            break;
        }
    }

    //! Renvoie une nature en fonction d'un texte
    /*!
      \param p Nature de l'atome au format Texte
      \return Nature de l'atome au format Enum
    */
    static EnumNature EnumFromString(const QString& text) {
        if (text == "IDVAR")
            return IDVAR;
        else if (text == "IDPROG")
            return IDPROG;
        else if (text == "IDEXP")
            return IDEXP;
        else
            return INDEFINI;
    }

    //======================================================
    // Virtual methods
    //======================================================

    //! Fonction d'affichage
    virtual void afficher() const {
        std::cout << value.toStdString() << std::endl;
    }

    //! Getter de l'identifiant au format texte
    /*!
      \return Renvoie la propriété value
    */
    QString getText() const {
        return value;
    }

    //! Getter de l'identifiant au format texte
    /*!
      \return Renvoie la propriété value
    */
    QString getName() const {
        return value;
    }

    virtual LTAtome* clone() const {
        return new LTAtome(this->value, this->Nature, this->pointer);
    }

    virtual Litterale* simplifier() {
        return this;
    }
};

#endif // ATOME_H
