#ifndef LTATOMEMANAGER_H
#define LTATOMEMANAGER_H

#include <QMap>
#include <QString>
#include <QString>
#include "ltatome.h"
#include "exception.h"
#include "controller.h"

//! Classe LTAtomeManager (Singleton) : factory d'atome, gère leur création, notamment les cas où un atome du même nom existe déjà
class LTAtomeManager
{
    static LTAtomeManager* instance;
    LTAtomeManager();
    ~LTAtomeManager() {}
    LTAtomeManager(const LTAtomeManager& c);

    QMap<QString, LTAtome*> dictionnary;
    QList<QString> operatorsExisting;

public:

    //! Fonction qui permet de récupérer l'instance du singleton
    /*!
      \return Instance de LTAtomeManager
    */
    static LTAtomeManager& getInstance() {
        if (!instance) instance = new LTAtomeManager();
        return *instance;
    }

    //! Fonction qui permet de libérer l'instance du singleton
    static void freeInstance() { if (instance) delete instance; }

    //! Permet de créer un atome ou de renvoyer la litterale associée à l'atome considéré
    /*!
      \param name Nom de l'atome
      \param n Nature de l'atome
      \return Litterale Atome créée ou Litterale associée à l'atome renvoyée
    */
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

    //! Fonction qui permet de créer un atome
    /*!
      \param name Nom de l'atome
      \param n Nature de l'atome
      \return Litterale Atome créée
    */
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

    //! Créé une expression à partir d'un atome
    /*!
      \param a Litterale Atome
      \return Litterale Expression créée
    */
    LTExpression* expressionFromAtome(LTAtome* a) {
        QList<OPNum_LTSansExpression*>* list = new QList<OPNum_LTSansExpression*>();
        list->append(a);
        LTExpression* e = new LTExpression(*list);
        return e;
    }

    //! Suppression d'un atome
    /*!
      \param a Litterale Atome
    */
    void removeAtome(LTAtome* a) {
        dictionnary.remove(a->getName());
        this->saveInFile();
    }

    //! Sauvegarde dans un fichier XML l'ensemble des atomes, leur valeur et les litterales associées
    void saveInFile() {
        Controller::getInstance().saveAtomeManagerInFile();
    }

    //! Renvoie le map contenant les identifiants et les atomes associés
    /*!
      \return Map contenant en clé l'identifiant de l'atome, et en valeur l'atome lui même
    */
    QMap<QString, LTAtome*> getDictionnary() {
        return dictionnary;
    }

    //! Ajouter une liste d'élément dans la map
    /*!
      \param dic Map contenant les éléments à ajouter
    */
    void appendToDictionnary(QMap<QString, LTAtome*> dic) {
        QMap<QString, LTAtome*>::iterator i;
        for (i = dic.begin(); i != dic.end(); ++i) {
            dictionnary.insert(i.key(), i.value());
        }
    }

    //! Tout supprimer de la map
    void removeAllFromDictionnary(){
      dictionnary.clear();
    }

    //! Supprimer un atome spécifique de la map
    /*!
      \param varName Nom de l'atome à supprimer
    */
    void remove(const QString& varName){
        dictionnary.remove(varName);
    }
};

#endif // LTATOMEMANAGER_H
