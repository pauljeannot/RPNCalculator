#ifndef OPERANDE_H
#define OPERANDE_H


class Operande
{
public:
    Operande(){}
    virtual ~Operande(){}
    virtual Operande* getChild() {return dynamic_cast<Operande*>(this);}
    virtual void afficher() {}
};

#endif // OPERANDE_H
