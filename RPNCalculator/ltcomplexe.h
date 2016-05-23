#ifndef LTCOMPLEXE_H
#define LTCOMPLEXE_H
#include "ltnombre.h"
#include "ltnumerique.h"
#include <QString>

class LTComplexe : public LTNombre
{
    LTNumerique* Re;
    LTNumerique* Im;
    QString separateur;

public:

    //======================================================
    // Basics methods
    //======================================================

    LTComplexe(LTNumerique* r, LTNumerique* i): Re(r), Im(i), separateur("$") {

    }

    LTComplexe(const LTComplexe& c):Re(0), Im(0), separateur("$") {

        LTNumerique* re = c.getRe()->clone();
        LTNumerique* im = c.getIm()->clone();

        this->setRe(re);
        this->setIm(im);
    }

    virtual ~LTComplexe() {

    }

    //======================================================
    // Getters/setters
    //======================================================

    void setRe(LTNumerique* v) {
        if(Re != 0) delete(this->Re);
        this->Re = v;
    }

    void setIm(LTNumerique* v) {
        if (Im != 0) delete(this->Im);
        this->Im = v;
    }

    LTNumerique* getRe() const {
        return Re;
    }

    LTNumerique* getIm() const {
        return Im;
    }

    //======================================================
    // Virtual methods
    //======================================================

    virtual void afficher() const;

    virtual QString getText() const;

    virtual LTComplexe* clone() const;

    virtual LTComplexe* simplifier() {
        this->Re = this->Re->simplifier();
        this->Im = this->Im->simplifier();

        return this;
    }

    //======================================================
    // Operator methods
    //======================================================

    // OPAddition
    virtual LTNombre * operator+(LTNumerique* p);
    virtual LTComplexe* operator+(LTComplexe* p);

    // OPSoustraction
    virtual LTNombre * operator-(LTNumerique* p);
    virtual LTComplexe* operator-(LTComplexe* p);

    // OPMultiplication
    virtual LTNombre * operator*(LTNumerique* p);
    virtual LTComplexe* operator*(LTComplexe* p);

    // OPDivision
    virtual LTNombre * operator/(LTNumerique* p);
    virtual LTComplexe* operator/(LTComplexe* p);

    // OPEgal
    friend bool operator==(LTComplexe& l1, LTComplexe& l2);
    friend bool operator==(LTComplexe& l1, LTNumerique& l2);

    // OPDifferent
    friend bool operator!=(LTComplexe& l1, LTComplexe& l2);
    friend bool operator!=(LTComplexe& l1, LTNumerique& l2);

};

#endif // LTCOMPLEXE_H
