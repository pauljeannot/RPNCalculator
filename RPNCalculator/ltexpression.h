#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "litterale.h"
#include "operateur.h"
#include "ltsansexpression.h"
#include "opnum_ltsansexpression.h"
#include <QList>

class LTAtome;

class LTExpression : public Litterale
{
    LTAtome* identificateur;
    QList<OPNum_LTSansExpression*> liste;

public:

    //======================================================
    // Basics methods
    //======================================================

    LTExpression(LTAtome* id, QList<OPNum_LTSansExpression*> l):identificateur(id), liste(l) {

    }

    LTExpression(QList<OPNum_LTSansExpression*> l):identificateur(nullptr), liste(l) {

    }

    virtual ~LTExpression() {

    }

    virtual QString getContentToCompute() const {
        QString text = "";
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j)
            text += (*j)->getText() + " ";
        text = text.left(text.length()-1);
        return text;
    }

    QList<OPNum_LTSansExpression*> getList() {
        return liste;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        QList<OPNum_LTSansExpression*>::const_iterator j;
        std::cout << "'" << std::endl;
        for (j = liste.begin(); j != liste.end(); ++j)
            (*j)->afficher();
        std::cout << "'" << std::endl;
    }

    virtual QString getText() const {
        QString text = "'";
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j)
            text += (*j)->getText() + " ";
        text = text.left(text.length()-1);
        text += "'";
        return text;
    }

    virtual LTExpression* clone() const {

        QList<OPNum_LTSansExpression*> liste2;
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j)
            liste2.append((*j)->clone());

        return new LTExpression(this->identificateur, liste2);
    }

    virtual LTExpression* simplifier() {
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j) {

            LTSansExpression* exp = dynamic_cast<LTSansExpression*>(*j);
            if (exp != nullptr)
                exp->simplifier();
        }
    }

    virtual void write(QXmlStreamWriter& xmlWriter) const {
        xmlWriter.writeStartElement("ltexpression");
        xmlWriter.writeStartElement("liste");

        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j) {
            Operateur* op = dynamic_cast<Operateur*>(*j);
            Litterale* l = dynamic_cast<Litterale*>(*j);
            if (op != nullptr) {
                xmlWriter.writeStartElement("operateur");
                xmlWriter.writeCharacters (op->getText());
                xmlWriter.writeEndElement();
            }
            else if (l != nullptr) l->write(xmlWriter);
            else std::cout << "gros problème ici : ni un operateur ni une litterale" << std::endl;
        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }

    virtual LTExpression* read(QXmlStreamReader& xmlReader) {

    }
};

#endif // EXPRESSION_H
