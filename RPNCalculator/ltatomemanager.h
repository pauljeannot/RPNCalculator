#ifndef LTATOMEMANAGER_H
#define LTATOMEMANAGER_H

#include <QMap>
#include <QString>
#include <QString>
#include "ltatome.h"
#include "exception.h"
#include "controller.h"

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

    Litterale* createAtomeOrAssociatedLitterale(QString name, LTAtome::EnumNature n = LTAtome::EnumNature::INDEFINI) {

        // Si un atome n'existe pas encore avec un tel nom et qu'il n'est pas un opérateur prédefini :
        if(dictionnary.count(name) == 0 && !operatorsExisting.contains(name)) {
            LTAtome* a =  new LTAtome(name, n);
            dictionnary.insert(name, a);
            LTExpression* e = expressionFromAtome(a);
            this->saveInFile();
            return e;
        }
        // Si un atome existe déjà sous ce nom mais qu'il n'est pas un opérateur prédef
        else if (dictionnary.count(name) == 1 && !operatorsExisting.contains(name)) {
            LTAtome* a = dictionnary.value(name);

//            std::cout << "existe déjà" << std::endl;
            // Si c'est un type prédéfini, on renvoie l'atome sous forme d'une expression
            if (a->getNature() == LTAtome::EnumNature::INDEFINI) {
                return expressionFromAtome(a);
            }
            // Sinon on remplace l'atome par sa vraie valeur qu'il identifie
            else {
                return a->getPointer();
            }
        }
        else {
            std::cout << "L'atome existe déjà et est un opérateur connu donc throw" << std::endl;
            throw ExceptionAtome(ExceptionAtome::Type::ATOME_IS_OPERATOR, "Impossible de créer cet atome : il correspond à un opérateur existant qui ne peut être redéfini.");
        }
    }

    LTAtome* createAtome(QString name, LTAtome::EnumNature n = LTAtome::EnumNature::INDEFINI) {

        // Si un atome n'existe pas encore avec un tel nom et qu'il n'est pas un opérateur prédefini :
        if(dictionnary.count(name) == 0 && !operatorsExisting.contains(name)) {
            LTAtome* a =  new LTAtome(name, n);
            dictionnary.insert(name, a);
//            std::cout << "existe pas" << std::endl;
            this->saveInFile();
            return a;
        }
        // Si un atome existe déjà sous ce nom mais qu'il n'est pas un opérateur prédef
        else if (dictionnary.count(name) == 1 && !operatorsExisting.contains(name)) {
//            std::cout << "existe déjà" << std::endl;
            LTAtome* a = dictionnary.value(name);
            return a;
        }
    }

    LTExpression* expressionFromAtome(LTAtome* a) {
        QList<OPNum_LTSansExpression*>* list = new QList<OPNum_LTSansExpression*>();
        list->append(a);
        LTExpression* e = new LTExpression(*list);
        return e;
    }

    void removeAtome(LTAtome* a) {
        dictionnary.remove(a->getName());
        this->saveInFile();
    }

    void saveInFile() {
        Controller::getInstance().saveAtomeManagerInFile();
    }

    QMap<QString, LTAtome*> getDictionnary() {
        return dictionnary;
    }

    // Ajouter un élément dans la map
    void appendToDictionnary(QMap<QString, LTAtome*> dic) {
        QMap<QString, LTAtome*>::iterator i;
        for (i = dic.begin(); i != dic.end(); ++i) {
            dictionnary.insert(i.key(), i.value());
        }
    }

    // Supprimer un élément de la map
    void removeAllFromDictionnary(){
      dictionnary.clear();
    }

    void remove(const QString& varName){
        dictionnary.remove(varName);
    }

};

#endif // LTATOMEMANAGER_H
