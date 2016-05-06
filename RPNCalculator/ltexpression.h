#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "litterale.h"
#include "ltsansexpression.h"
#include "opnum_ltsansexpression.h"
#include "ltatome.h"
#include <vector>

class LTExpression : public Litterale
{
    LTAtome identificateur;
    std::vector<OPNum_LTSansExpression> liste;

public:
    LTExpression(LTAtome id, std::vector<OPNum_LTSansExpression> l):identificateur(id), liste(l){}
    virtual LTExpression* getChild(){return nullptr;}
    virtual ~LTExpression(){}
};

#endif // EXPRESSION_H
