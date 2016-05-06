#ifndef LTNOMBRE_H
#define LTNOMBRE_H
#include "ltsansexpression.h"


class LTNombre : public LTSansExpression
{
public:
    LTNombre();
    virtual LTNombre* getChild()=0;
};

#endif // LTNOMBRE_H
