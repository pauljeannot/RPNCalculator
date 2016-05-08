#ifndef LTNOMBRE_H
#define LTNOMBRE_H
#include "ltsansexpression.h"


class LTNombre : public LTSansExpression
{
public:
    LTNombre();
    virtual LTNombre* getChild(){return nullptr;}
    virtual ~LTNombre() {}
};

#endif // LTNOMBRE_H
