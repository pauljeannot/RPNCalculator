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

    virtual ~LTComplexe() {

    }

    //======================================================
    // Virtual methods herited
    //======================================================

    virtual void afficher() const {
        std::cout << getText().toStdString() << std::endl;
    }

    QString getText() const {
        return QString(Re->getText() + separateur + Im->getText());
    }

    void setRe(LTNumerique* v) {
        delete(this->Re);
        this->Re = v;
    }

    LTNumerique* getRe() const {
        return Re;
    }

    void setIm(LTNumerique* v) {
        delete(this->Im);
        this->Im = v;
    }

    LTNumerique* getIm() const {
        return Im;
    }

    //======================================================
    // Operator methods
    //======================================================

    virtual LTNombre * operator+(LTNumerique* p);

    virtual LTComplexe* operator+(LTComplexe* p);

};

#endif // LTCOMPLEXE_H
