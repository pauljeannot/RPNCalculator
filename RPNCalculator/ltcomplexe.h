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

    virtual LTComplexe* getChild() {
        return dynamic_cast<LTComplexe*>(this);
    }

    virtual const LTComplexe* zero() const {

    }

    virtual void afficher() const {
        std::cout << getText().toStdString() << std::endl;
    }

    QString getText() const {
        return QString(Re->getText() + separateur + Im->getText());
    }

    LTNumerique* getRe() const {
        return Re;
    }

    LTNumerique* getIm() const {
        return Im;
    }

    //======================================================
    // Others methods
    //======================================================

};

#endif // LTCOMPLEXE_H
