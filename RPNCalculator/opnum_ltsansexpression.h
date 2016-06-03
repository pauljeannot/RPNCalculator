#ifndef OPNUM_LTSANSEXPRESSION_H
#define OPNUM_LTSANSEXPRESSION_H
#include "operande.h"
#include "litterale.h"

/*!
 * \brief Classe OPNum_LTSansExpression
 */
class OPNum_LTSansExpression : virtual public Operande
{
public:
    /*!
     * \brief Constructeur
     */
    OPNum_LTSansExpression();

    virtual OPNum_LTSansExpression* clone() const = 0;

};

#endif // OPNUM_LTSANSEXPRESSION_H
