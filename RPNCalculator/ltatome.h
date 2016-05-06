#ifndef ATOME_H
#define ATOME_H
#include "ltsansexpression.h"
#include <QString>

enum EnumNature {IDVAR, IDOP, OPPREDEF};

class LTAtome : public LTSansExpression
{
    QString value;
    EnumNature Nature;
public:
    LTAtome(QString v, EnumNature n): value(v), Nature(n) {}
    virtual LTAtome* getChild(){return nullptr;}
    virtual ~LTAtome(){}
};

#endif // ATOME_H
