#ifndef LTATOMEMANAGER_H
#define LTATOMEMANAGER_H

#include <QMap>
#include <QString>
#include <QString>
#include "ltatome.h"
#include "exception.h"

class LTAtomeManager
{
    static LTAtomeManager* instance;
    LTAtomeManager();
    ~LTAtomeManager() {}
    LTAtomeManager(const LTAtomeManager& c);

    QMap<QString, LTAtome*> dictionnary;
    QList<QString> operatorsExisting;

public:

    static LTAtomeManager& getInstance() {
        if (!instance) instance = new LTAtomeManager();
        return *instance;
    }

    static void freeInstance() { if (instance) delete instance; }

    Litterale* createAtome(QString name, LTAtome::EnumNature n = LTAtome::EnumNature::INDEFINI) {
        if(dictionnary.count(name) == 0 && !operatorsExisting.contains(name)) {
            LTAtome* a =  new LTAtome(name, n);
            dictionnary.insert(name, a);
            LTExpression* e = expressionFromAtome(a);
            return e;
        }
        else if (dictionnary.count(name) == 1 && !operatorsExisting.contains(name)) {
            LTAtome* a = dictionnary.value(name);

            if (a->getNature() == LTAtome::EnumNature::INDEFINI) {
                std::cout << "indef " << std::endl;
                return expressionFromAtome(a);
            }
            else {
                return a->getPointer();
            }
        }
        else {
            std::cout << "L'atome existe déjà et est un opérateur connu donc throw" << std::endl;
            throw ExceptionAtome(ExceptionAtome::Type::ATOME_IS_OPERATOR, "Impossible de créer cet atome : il correspond à un opérateur existant qui ne peut être redéfini.");
        }
    }

    LTExpression* expressionFromAtome(LTAtome* a) {
        QList<OPNum_LTSansExpression*>* list = new QList<OPNum_LTSansExpression*>();
        list->append(a);
        LTExpression* e = new LTExpression(*list);
        return e;
    }
};

#endif // LTATOMEMANAGER_H
