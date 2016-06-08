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

    /*!
     * \brief Constructeur de programme
     * \param id Atome identificateur
     * \param list Liste d'opérande composant le programme
     */
    LTProgramme(LTAtome id, QList<Operande *> list): identificateur(id), listeOperande(list){}

    /*!
     * \brief Constructeur de programme
     * \param list Liste d'opérande composant le programme
     */
    LTProgramme(QList<Operande *> list): identificateur(nullptr), listeOperande(list){}

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        QList<Operande*>::const_iterator j;
        std::cout << getText().toStdString() << std::endl;
    }

    virtual QString getText() const {
        QString text = "[ ";
        QList<Operande*>::const_iterator j;
        for (j = listeOperande.begin(); j != listeOperande.end(); ++j)
            text += (*j)->getText() + " ";
        text += "]";
        return text;
    }

    /*!
     * \brief Getter de la liste d'opérande composant le programme
     * \return
     */
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

    /*!
     * \brief Destructeur
     */
    virtual ~LTProgramme() {}
};

#endif // PROGRAMME_H
