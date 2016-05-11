#ifndef ATOME_H
#define ATOME_H
#include "ltsansexpression.h"
#include <QString>
#include <iostream>

enum EnumNature {IDVAR, IDOP, OPPREDEF, INDEFINI};

class LTAtome : public LTSansExpression
{
    QString value;
    EnumNature Nature;
public:
    LTAtome(QString v, EnumNature n): value(v), Nature(n) {}
    LTAtome(QString v):value(v), Nature(INDEFINI){}
    virtual void afficher(){
        std::cout << value.toStdString() << std::endl;
    }
    const QString getText() const {
        return QString(value);
    }

    virtual LTAtome* getChild(){return dynamic_cast<LTAtome*>(this);}
    virtual ~LTAtome(){}
};

#endif // ATOME_H
