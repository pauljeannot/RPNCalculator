#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <QString>

//==================================================================
//                 Exception
//==================================================================

class Exception
{
public:

    Exception(const QString& s):msg(s) {}

    virtual ~Exception() {}

    virtual const QString& what() const = 0;

protected:
    QString msg;
};

//==================================================================
//                 ExceptionStack
//==================================================================

class ExceptionStack : public Exception
{
public:

    enum Type { CANNOT_POP_STACK_EMPTY };

    ExceptionStack(const Type t, const QString& s = ""):Exception(s), type(t) {}

    virtual ~ExceptionStack() {}

    virtual const QString& what() const {
        return this->msg;
    }

    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionRationnelle
//==================================================================

class ExceptionRationnelle : public Exception
{
public:

    enum Type { CANNOT_HAVE_DENUM_ZERO, UNKNOWN_SEPARATOR };

    ExceptionRationnelle(const Type t, const QString& s = ""):Exception(s), type(t) {}

    virtual ~ExceptionRationnelle() {}

    virtual const QString& what() const {
        return this->msg;
    }

    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionWrongTypeOperande
//==================================================================

class ExceptionWrongTypeOperande : public Exception
{
public:

    enum Type { WRONG_TYPE_OPERATOR, WRONG_TYPE_LITTERALE, WRONG_TYPE_OPERANDE };

    ExceptionWrongTypeOperande(const Type t, const QString& s = ""):Exception(s), type(t) {}

    virtual ~ExceptionWrongTypeOperande() {}

    virtual const QString& what() const {
        return this->msg;
    }

    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};

//==================================================================
//                 ExceptionMemento
//==================================================================

class ExceptionMemento : public Exception
{
public:

    enum Type { CANNOT_UNDO, CANNOT_REDO };

    ExceptionMemento(const Type t, const QString& s = ""):Exception(s), type(t) {}

    virtual ~ExceptionMemento() {}

    virtual const QString& what() const {
        return this->msg;
    }

    virtual Type errorType() const {
        return this->type;
    }

private:
    Type type;
};


#endif // EXCEPTION_H
