#ifndef LITTERALE_H
#define LITTERALE_H
#include "operande.h"
#include <QString>
#include <IOStream>
#include <QXmlStreamWriter>

class LTNumerique;

class Litterale : virtual public Operande
{
public:

    //======================================================
    // Basic methods
    //======================================================

    Litterale() {

    }

    virtual ~Litterale() {

    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual Litterale* clone() const = 0;

    virtual Litterale* simplifier() = 0;

    virtual void write(QXmlStreamWriter& xmlWriter) const = 0;

    virtual Litterale* read(QXmlStreamReader& xmlReader) = 0;
};

#endif // LITTERALE_H
