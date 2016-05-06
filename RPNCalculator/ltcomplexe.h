#ifndef LTCOMPLEXE_H
#define LTCOMPLEXE_H
#include "ltnombre.h"
#include "ltnumerique.h"
#include <QString>

class LTComplexe : public LTNombre
{
    LTNumerique Re;
    LTNumerique Im;
    QString separateur;
public:
    LTComplexe(LTNumerique r, LTNumerique i, QString s): Re(r), Im(i), separateur(s){}
    LTComplexe* getChild() = 0;
};

#endif // LTCOMPLEXE_H
