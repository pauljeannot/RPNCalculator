#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <QString>

class Exception
{
public:

    Exception(const QString& s):msg(s) {}

    virtual ~Exception() {}

    virtual const QString& what() const = 0;

private:
    QString msg;
};


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
    QString msg;
    Type type;
};



#endif // EXCEPTION_H
