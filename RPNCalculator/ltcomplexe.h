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
    virtual LTComplexe* getChild(){return dynamic_cast<LTComplexe*>(this);}
    virtual ~LTComplexe(){}
};

#endif // LTCOMPLEXE_H
