#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "litterale.h"
#include "ltsansexpression.h"
#include "opnum_ltsansexpression.h"
#include <QList>

class LTAtome;

class LTExpression : public Litterale
{
    LTAtome* identificateur;
    QList<OPNum_LTSansExpression*> liste;

public:

    //======================================================
    // Basics methods
    //======================================================

    LTExpression(LTAtome* id, QList<OPNum_LTSansExpression*> l):identificateur(id), liste(l) {

    }

    LTExpression(QList<OPNum_LTSansExpression*> l):identificateur(nullptr), liste(l) {

    }

    virtual ~LTExpression() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        QList<OPNum_LTSansExpression*>::const_iterator j;
        std::cout << "'" << std::endl;
        for (j = liste.begin(); j != liste.end(); ++j)
            (*j)->afficher();
        std::cout << "'" << std::endl;
    }

    virtual QString getText() const {
        QString text = "'";
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j)
            text += (*j)->getText() + " ";
        text = text.left(text.length()-1);
        text += "'";
        return text;
    }

    virtual QString getContentToCompute() const {
        QString text = "";
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j)
            text += (*j)->getText() + " ";
        text = text.left(text.length()-1);
        return text;
    }

    QList<OPNum_LTSansExpression*> getList() {
        return liste;
    }

    virtual LTExpression* clone() const {
        return nullptr;
    }

};

#endif // EXPRESSION_H
