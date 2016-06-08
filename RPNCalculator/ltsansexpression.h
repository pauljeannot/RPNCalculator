#ifndef LTSANSEXPRESSION_H
#define LTSANSEXPRESSION_H
#include "litterale.h"
#include "opnum_ltsansexpression.h"

/*!
 * \brief Classe fille des Litterales sauf Expression
 */
class LTSansExpression : public OPNum_LTSansExpression, public Litterale
{
public:

    //======================================================
    // Basic methods
    //======================================================

    /*!
     * \brief Constructeur
     */
    LTSansExpression() {

    }

    /*!
     * \brief Destructeur
     */
    virtual ~LTSansExpression() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual QString getText() const = 0;

    virtual void afficher() const = 0;

    virtual LTSansExpression* clone() const = 0;

    virtual Litterale* simplifier() = 0;
};

#endif // LTSANSEXPRESSION_H
