#ifndef PARSEUR_H
#define PARSEUR_H
#include "exception.h"
#include "operande.h"
#include "opnum_ltsansexpression.h"
#include <QList>

/*!
 * \brief Classe Parseur
 * Permet de créer des listes d'opérandes à partir d'une QString
 */
class Parseur
{
    //! Constructeur privé, les méthodes de classes sont static
    Parseur();
public:
    /*!
     * \brief Static permet de créer une liste d'opérandes à partir d'une QString
     * \param chaine
     * \return
     */
    static QList<Operande*> NewListOperande(const QString& chaine);
    /*!
     * \brief Méthode static, permet de créer une liste d'opérandes à partir d'une QString. N'accepte pas les Expressions
     * \param chaine
     * \return
     */
    static QList<OPNum_LTSansExpression*> NewListOPNum_LTSansExpression(const QString& chaine);
};

#endif // PARSEUR_H
