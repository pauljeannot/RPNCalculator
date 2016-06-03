#ifndef OPMANIPULATIONPILE_H
#define OPMANIPULATIONPILE_H
#include "operateur.h"

/*!
 * \brief Classe OPManipulationPile
 * Classe mère des opérateurs de manipulation de pile
 */
class OPManipulationPile : public Operateur
{
public:
    //! Constructeur
    /*!
          \param val QString valeur de l'opérateur
          \param a arité de l'opérateur
        */
    OPManipulationPile(QString val, int a):Operateur(val, a){}

    //! Virtuelle pure. Permet de cloner un opérateur de manipulation de pile
    virtual OPManipulationPile* clone() const = 0;

    virtual Litterale* compute() = 0;

    virtual Litterale* compute(Litterale* l) = 0;

    virtual Litterale* compute(Litterale* l1, Litterale* l2) = 0;
};

/*!
 * \brief Classe OPDup
 */
class OPDup : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPDup():OPManipulationPile("DUP", 1){}

    virtual OPDup* clone() const {
        return new OPDup();
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
 * \brief Classe OPDrop
 */
class OPDrop : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPDrop():OPManipulationPile("DROP", 1){}

    virtual OPDrop* clone() const {
        return new OPDrop();
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
 * \brief Classe OPSwap
 */
class OPSwap : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPSwap():OPManipulationPile("SWAP", 2){}

    virtual OPSwap* clone() const {
        return new OPSwap();
    }

    virtual Litterale* compute() {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " n'est pas utilisable sans litterales.");
    }
    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }

    virtual Litterale* compute(Litterale* l1, Litterale* l2);
};

/*!
 * \brief Classe OPLastOp
 */
class OPLastOp : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPLastOp():OPManipulationPile("LASTOP", 0){}

    virtual OPLastOp* clone() const {
        return new OPLastOp();
    }

    virtual Litterale* compute();

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

/*!
 * \brief Classe OPLastArgs
 */
class OPLastArgs : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPLastArgs():OPManipulationPile("LASTARGS", 0){}

    virtual OPLastArgs* clone() const {
        return new OPLastArgs();
    }

    virtual Litterale* compute();

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

/*!
 * \brief Classe OPUndo
 */
class OPUndo : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPUndo():OPManipulationPile("UNDO", 0){}

    virtual OPUndo* clone() const {
        return new OPUndo();
    }

    virtual Litterale* compute();

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

/*!
 * \brief Classe OPRedo
 */
class OPRedo : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPRedo():OPManipulationPile("REDO", 0){}

    virtual OPRedo* clone() const {
        return new OPRedo();
    }

    virtual Litterale* compute();

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

/*!
 * \brief Classe OPClear
 */
class OPClear : public OPManipulationPile
{
public:
    /*!
     * \brief Constructeur
     */
    OPClear():OPManipulationPile("CLEAR", 0){}

    virtual OPClear* clone() const {
        return new OPClear();
    }

    virtual Litterale* compute();

    virtual Litterale* compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est binaire et nécessite 2 litterales.");
    }
    virtual Litterale* compute(Litterale* l1, Litterale* l2) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opérateur " + this->value + " est unaire et nécessite 1 seule litterale.");
    }
};

#endif // OPMANIPULATIONPILE_H
