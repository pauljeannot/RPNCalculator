#include "opnumerique.h"


//=================================================================
//
//                        OPComplexe
//
//=================================================================

    Litterale* OPComplexe::compute(Litterale* l) {
        throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "L'opération '' est binaire et nécessite 2 litterales.");
    }

    Litterale* OPComplexe::compute(Litterale* l1, Litterale* l2) {
        LTNumerique* num1 = dynamic_cast<LTNumerique*>(l1);
        LTNumerique* num2 = dynamic_cast<LTNumerique*>(l2);
        // Si c'est un LTNumérique, on applique l'opérateur, sinon on lève une exception
        if (num1 != nullptr && num2!= nullptr) {
            return new LTComplexe(num1, num2);
        }
        else {
            throw ExceptionWrongTypeOperande(ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR, "Un complexe ne peut être créé qu'à partir d'une litterale numérique.");
        }
    }
