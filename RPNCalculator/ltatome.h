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

    LTAtome(QString v, EnumNature n, Litterale* p = nullptr): value(v), Nature(n), pointer(p) {

    }

    LTAtome(QString v, Litterale* p = nullptr):value(v), Nature(INDEFINI), pointer(p) {

    }

    virtual ~LTAtome() {

    }

    void setPointer(Litterale* l);

    EnumNature getNature() const;

    Litterale* getPointer() const;

    QString getEnumString() const {
        switch (Nature) {
        case IDVAR:
            return "IDVAR";
            break;
        case IDPROG:
            return "IDPROG";
            break;
        case IDEXP:
            return "IDEXP";
            break;
        case INDEFINI:
            return "INDEFINI";
            break;
        }
    }

    static EnumNature EnumFromString(const QString& text) {
        if (text == "IDVAR")
            return IDVAR;
        else if (text == "IDPROG")
            return IDPROG;
        else if (text == "IDEXP")
            return IDEXP;
        else
            return INDEFINI;
    }

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
        return new LTAtome(this->value, this->Nature, this->pointer);
    }

    virtual Litterale* simplifier() {
        return this;
    }
};

#endif // ATOME_H
