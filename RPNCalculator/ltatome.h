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

    virtual void afficher() const {
        std::cout << value.toStdString() << std::endl;
    }

    QString getText() const {
        return QString(value);
    }

    virtual LTAtome* clone() const {
        return new LTAtome(this->value, this->Nature);
    }

};

#endif // ATOME_H
