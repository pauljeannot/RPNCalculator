#ifndef PROGRAMME_H
#define PROGRAMME_H
#include "litterale.h"
#include "ltatome.h"
#include <vector>


class LTProgramme : public Litterale
{
    LTAtome identificateur;
    std::vector<Operande> listeOperande;

public:
    LTProgramme(LTAtome id, std::vector<Operande> list): identificateur(id), listeOperande(list){}
    LTProgramme* getChild();
};

#endif // PROGRAMME_H
