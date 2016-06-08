#ifndef OPLITERRALEEXPRESION_H
#define OPLITERRALEEXPRESION_H
#include "operateur.h"

/*!
 * \brief Opérateur pour les litterales expressions ou programmes
 */
class OPLiterraleExpresionProgramme : public Operateur
{
public:
    /*!
     * \brief Constructeur
     * \param val Valeur textuelle de l'opérateur
     * \param a Arité
     */
    OPLiterraleExpresionProgramme(QString val, int a):Operateur(val, a){}

    virtual OPLiterraleExpresionProgramme* clone() const = 0;

    virtual Litterale* compute() = 0;

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;
};


/*!
 * \brief Opérateur EVAL
 */
class OPEval : public OPLiterraleExpresionProgramme
{
public:
    /*!
     * \brief Constructeur
     */
    OPEval():OPLiterraleExpresionProgramme("EVAL", 1){}

    virtual OPEval* clone() const {
        return new OPEval();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);

    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

/*!
 * \brief Opérateur EDIT
 */
class OPEdit : public OPLiterraleExpresionProgramme
{
public:
    /*!
     * \brief Constructeur
     */
    OPEdit():OPLiterraleExpresionProgramme("EDIT", 1){}

    virtual OPEdit* clone() const {
        return new OPEdit();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l);
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};
#endif // OPLITERRALEEXPRESION_H
