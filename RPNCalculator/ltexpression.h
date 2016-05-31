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
