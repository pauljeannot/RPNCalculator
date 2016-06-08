#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "litterale.h"
#include "operateur.h"
#include "ltsansexpression.h"
#include "opnum_ltsansexpression.h"
#include "parseur.h"
#include "operandefactory.h"
#include <QList>

class LTAtome;

//! Classe LTExpression, gérant les expressions
class LTExpression : public Litterale
{
    LTAtome* identificateur;
    QList<OPNum_LTSansExpression*> liste;

public:

    //======================================================
    // Basics methods
    //======================================================

    //! Constructeur
    /*!
      \param id Atome identifiant l'expression
      \param l Contenu de l'expression
    */
    LTExpression(LTAtome* id, QList<OPNum_LTSansExpression*> l):identificateur(id), liste(l) {

    }

    //! Constructeur
    /*!
      \param l Contenu de l'expression
    */
    LTExpression(QList<OPNum_LTSansExpression*> l):identificateur(nullptr), liste(l) {

    }

    //! Destructeur
    virtual ~LTExpression() {

    }

    //! Fonction qui renvoie une string de l'expression
    /*!
      \return Texte de l'expression
    */
    virtual QString getContentToCompute() const {
        QString text = "";
        QList<OPNum_LTSansExpression*>::const_iterator j;
        for (j = liste.begin(); j != liste.end(); ++j)
            text += (*j)->getText() + " ";
        text = text.left(text.length()-1);
        return text;
    }

    //! Fonction qui renvoie la liste du contenu de l'expression
    /*!
      \return Texte de l'expression
    */
    QList<OPNum_LTSansExpression*> getList() {
        return liste;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const {
        QList<OPNum_LTSansExpression*>::const_iterator j;
        std::cout << getText().toStdString() << std::endl;
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

    //! Fonction qui concatenne un opérateur à la fin d'une expression
    /*!
      \param E2 Expression
      \param op Opérateur
      \return Expression
    */
    virtual LTExpression* concatener(LTExpression* E2, QString op){
        QList<OPNum_LTSansExpression*> concat;

        foreach (OPNum_LTSansExpression* O, liste) {
            concat.push_back(O);
        }
        foreach (OPNum_LTSansExpression* O, E2->getList()) {
            concat.push_back(O);
        }
        OPNum_LTSansExpression* A = OperandeFactory::NewOPNum_LTSansExpression(op);
        concat.push_back(A);

        LTExpression* newExp = new LTExpression(concat);
        return newExp;
    }
};

#endif // EXPRESSION_H
