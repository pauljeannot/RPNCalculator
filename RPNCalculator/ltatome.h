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

    virtual void write(QXmlStreamWriter& xmlWriter) const {
        xmlWriter.writeStartElement("ltatome");

        xmlWriter.writeStartElement("value");
        xmlWriter.writeCharacters (this->value);
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("EnumNature");
        xmlWriter.writeCharacters (this->getEnumString());
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("pointer");
        if (pointer != nullptr) {
            pointer->write(xmlWriter);
        }
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
    }

    virtual LTAtome* read(QXmlStreamReader& xmlReader) {

    }
};

#endif // ATOME_H
