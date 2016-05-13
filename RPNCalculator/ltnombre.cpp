#include "ltnombre.h"
#include "ltcomplexe.h"
#include "ltnumerique.h"

LTNombre* LTNombre::operator+(LTNombre* p) {
    LTComplexe* c = dynamic_cast<LTComplexe*>(p);
    LTNumerique* num = dynamic_cast<LTNumerique*>(p);

    if (c != nullptr) {
       return *(this) + c;
    }
    else if (num != nullptr) {
        return *(this) + num;
    }
}
