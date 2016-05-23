#ifndef PROGRAMME_H
#define PROGRAMME_H
#include "litterale.h"
#include "ltatome.h"
#include <QList>


class LTProgramme : public Litterale
{
    LTAtome identificateur;
    QList<Operande*> listeOperande;

public:

    LTProgramme(LTAtome id, QList<Operande *> list): identificateur(id), listeOperande(list){}
    LTProgramme(QList<Operande *> list): identificateur(nullptr), listeOperande(list){}

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        QList<Operande*>::const_iterator j;
        std::cout << "[ " << std::endl;
        for (j = listeOperande.begin(); j != listeOperande.end(); ++j)
            (*j)->afficher();
        std::cout << " ]" << std::endl;
    }

    virtual QString getText() const {
        QString text = "[ ";
        QList<Operande*>::const_iterator j;
        for (j = listeOperande.begin(); j != listeOperande.end(); ++j)
            text += (*j)->getText() + " ";
        text += "]";
        return text;
    }

    virtual QList<Operande*> getListOperande() {
        return listeOperande;
    }

    virtual LTProgramme* clone() const {

        QList<Operande*>  liste2;
        QList<Operande*>::const_iterator j;
        for (j = listeOperande.begin(); j != listeOperande.end(); ++j)
            liste2.append((*j)->clone());

        return new LTProgramme(this->identificateur, liste2);
    }

    virtual Litterale* simplifier() {
        QList<Operande*>::const_iterator j;
        for (j = listeOperande.begin(); j != listeOperande.end(); ++j) {
            Litterale* l = dynamic_cast<Litterale*>(*j);
            if (l != nullptr)
                l->simplifier();
        }
    }

    virtual void write(QXmlStreamWriter& xmlWriter) const {
        xmlWriter.writeStartElement("ltprogramme");

        xmlWriter.writeStartElement("listeOperande");

        QList<Operande*>::const_iterator j;
        for (j = listeOperande.begin(); j != listeOperande.end(); ++j) {
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

    virtual LTProgramme* read(QXmlStreamReader& xmlReader) {

    }


    virtual ~LTProgramme() {}
};

#endif // PROGRAMME_H
