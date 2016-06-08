#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <QString>

//==================================================================
//                 Exception
//==================================================================

//! Classe mère abstraite pour gérer les exceptions
class Exception
{
public:

    //! Contructeur
    /*!
      \param s Message de l'exception
    */
    Exception(const QString& s):msg(s) {}

    //! Destructeur d'une exception
    virtual ~Exception() {}

    //! Fonction virtuelle pure qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const = 0;

protected:
    QString msg;
};

//==================================================================
//                 ExceptionStack
//==================================================================

//! Classe d'exception de la pile
class ExceptionStack : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        CANNOT_POP_STACK_EMPTY /*!< Si la pile est vide */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionStack(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionStack() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionRationnelle
//==================================================================

//! Classe d'exception pour les Litterales Rationnelles
class ExceptionRationnelle : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        CANNOT_HAVE_DENUM_ZERO, /*!< Si le dénominateur vaut 0 */
        UNKNOWN_SEPARATOR /*!< Si le séparateur est inconnu */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionRationnelle(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionRationnelle() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionWrongTypeOperande
//==================================================================

//! Classe d'exception si une opérande est mal utilisée
class ExceptionWrongTypeOperande : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        WRONG_TYPE_OPERATOR, /*!< L'opérateur est incorrect */
        WRONG_TYPE_LITTERALE,  /*!< La litterale est incorrecte */
        WRONG_TYPE_OPERANDE /*!< L'opérande est incorrecte */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionWrongTypeOperande(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionWrongTypeOperande() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionMemento
//==================================================================

//! Classe d'exception pour le design pattern Memento et la gestion de l'Undo Redo
class ExceptionMemento : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        CANNOT_UNDO,/*!< Impossible de revenir à l'état précédent */
        CANNOT_REDO/*!< Impossible de revenir à l'état suivant */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionMemento(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionMemento() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};


//==================================================================
//                 ExceptionAtome
//==================================================================

//! Classe d'exception pour les Litterales Atomes
class ExceptionAtome : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        ATOME_IS_OPERATOR /*!< L'atome est déjà un opérateur connu */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionAtome(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionAtome() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionSyntaxte
//==================================================================

//! Classe d'exception pour la syntaxe
class ExceptionSyntaxte : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        SYNTAX_ERROR /*!< La syntaxe est erronée */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionSyntaxte(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionSyntaxte() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//! Classe d'exception pour les vérifications des champs
class ExceptionEmptyField : public Exception
{
public:

    //! Type enum correspondant
    enum Type {
        EMPTY_FIELD, /*!< Le champs de texte est vide */
        WRONG_NUMBER_SELECTED /*!< Le nombre de champs sélectionné est incorrect */
    };

    //! Constructeur de l'exception
    /*!
      \param t Type de l'exception
      \param s Texte de l'exception
    */
    ExceptionEmptyField(const Type t, const QString& s = ""):Exception(s), type(t) {}

    //! Destructeur de l'exception
    virtual ~ExceptionEmptyField() {}

    //! Fonction qui retourne le message de l'exception
    /*!
      \return Le texte de l'exception
    */
    virtual const QString& what() const {
        return this->msg;
    }

    //! Fonction qui retourne le type de l'exception
    /*!
      \return Le type de l'exception
    */
    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};
#endif // EXCEPTION_H
