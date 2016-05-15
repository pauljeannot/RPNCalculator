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
            text += (*j)->getText();
        text += " ]";
        return text;
    }

    virtual LTProgramme* clone() const {
        return nullptr;
    }

    virtual ~LTProgramme() {}
};

#endif // PROGRAMME_H
