#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "litterale.h"
#include "ltsansexpression.h"
#include "opnum_ltsansexpression.h"
#include "ltatome.h"
#include <QList>

class LTExpression : public Litterale
{
    LTAtome* identificateur;
    QList<OPNum_LTSansExpression*> liste;

public:
    LTExpression(LTAtome* id, QList<OPNum_LTSansExpression*> l):identificateur(id), liste(l){}
    LTExpression(QList<OPNum_LTSansExpression*> l):identificateur(nullptr), liste(l){}
    virtual LTExpression* getChild(){return dynamic_cast<LTExpression*>(this);}
    virtual ~LTExpression(){}

    virtual void afficher(){
        QList<OPNum_LTSansExpression*>::iterator j;
        std::cout << "'" << std::endl;
        for (j = liste.begin(); j != liste.end(); ++j)
            (*j)->getChild()->afficher();
        std::cout << "'" << std::endl;
    }
};

#endif // EXPRESSION_H
