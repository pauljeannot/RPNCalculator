#ifndef ATOME_H
#define ATOME_H
#include "ltsansexpression.h"
#include "ltexpression.h"
#include "ltnombre.h"
#include <QString>
#include <QMap>
#include <iostream>

class LTAtome : public LTSansExpression
{
public:
    enum EnumNature {IDVAR, IDPROG, IDEXP, INDEFINI};

private:
    QString value;
    EnumNature Nature;
    Litterale* pointer;

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

    void setPointer(Litterale* l);

    EnumNature getNature() const;

    Litterale* getPointer() const;

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        std::cout << value.toStdString() << std::endl;
    }

    QString getText() const {
        return value;
    }

    QString getName() const {
        return value;
    }


    virtual LTAtome* clone() const {
        return new LTAtome(this->value, this->Nature);
    }

};

#endif // ATOME_H
