#ifndef ATOME_H
#define ATOME_H
#include "ltsansexpression.h"
#include <QString>
#include <iostream>

class LTAtome : public LTSansExpression
{
public:
    enum EnumNature {IDVAR, IDOP, OPPREDEF, INDEFINI};

private:
    QString value;
    EnumNature Nature;

public:
    //======================================================
    // Basic methods
    //======================================================

    LTAtome(QString v, EnumNature n): value(v), Nature(n) {

    }

    LTAtome(QString v):value(v), Nature(INDEFINI) {

    }

    virtual ~LTAtome() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual LTAtome* getChild(){
        return dynamic_cast<LTAtome*>(this);
    }

    virtual void afficher() const {
        std::cout << value.toStdString() << std::endl;
    }

    QString getText() const {
        return QString(value);
    }
};

#endif // ATOME_H
