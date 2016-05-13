#include "controller.h"
#include "utcomputer.h"
#include "ltcomplexe.h"
#include "parseur.h"
#include "litterale.h"
#include "operateur.h"

Controller* Controller::instance = 0;

void Controller::computeLine(const QString& text) {

    QString messageLine;
    QList<Operande*> L;

    // Try en cas d'erreur lors de la création d'opérandes (division par 0 etc...)
    try {
        L = Parseur::NewListOperande(text);
    }
    catch (ExceptionRationnelle e) {
        messageLine = e.what();
        computationEnded(messageLine);
        return;
    }
    catch (ExceptionWrongTypeOperande e) {
        messageLine = e.what();
        computationEnded(messageLine);
        return;
    }


    // Parcours et affichage de la liste
    QList<Operande*>::iterator j;
    Litterale* lit;
    Operateur* op;


    for (j = L.begin(); j != L.end(); ++j) {

        // Si c'est une Litterale
        if ((lit = dynamic_cast<Litterale*>(*j)) != nullptr) {
            this->stack.push(lit);
        }

        // Sinon si c'est un opérateur
        else if ((op = dynamic_cast<Operateur*>(*j)) != nullptr) {
            int a = op->getArite();

            // Try suivant les erreurs relatives à la pile ou à l'exécution de l'opérateur sur le litterale
            try {

                // Cas selon l'arité
                switch (a) {
                case 0: {
                    break;
                }

                    // Arité 1 :
                case 1: {
                    // on pop un élement
                    if (this->stack.canPopItems(1)) {
                        Litterale* l0 = this->stack.pop();
                        Litterale* res = computer.compute(op, l0);
                        this->stack.push(res);
                    }
                    else {
                        messageLine = "Impossible : il faut au moins 1 élément dans la pile pour cet opérateur";
                    }
                    break;
                }
                    // Arité 2 :
                case 2: {
                    if (this->stack.canPopItems(2)) {
                        Litterale* l2 = this->stack.pop();
                        Litterale* l1 = this->stack.pop();
                        Litterale* res = computer.compute(op, l1, l2);
                        this->stack.push(res);
                    }
                    else {
                        messageLine = "Impossible : il faut au moins 2 éléments dans la pile pour cet opérateur";
                    }
                    break;
                }
                }
            }
            catch (ExceptionStack e) {
                if (e.errorType() == ExceptionStack::Type::CANNOT_POP_STACK_EMPTY) {
                    messageLine = "Impossible de dépiler un élement : la pile est vide";
                }
            }
            catch (ExceptionWrongTypeOperande e) {
                if (e.errorType() == ExceptionWrongTypeOperande::Type::WRONG_TYPE_OPERATOR) {
                    messageLine = "L'opérateur " + op->getText() + " ne peut pas s'appliquer à une telle litterale";
                }
            }
        }
    }

    computationEnded(messageLine);
}

void Controller::computationEnded(QString messageLine) {
    std::cout << "computation Ended" << std::endl;
    UTComputer& utc = UTComputer::getInstance();
    utc.updateMessage(messageLine);
    utc.refreshStackView();
    utc.clearCommandLine();
}

void Controller::updateSettings(unsigned int nb, bool playS, bool showK) {
    this->nbLines = nb;
    this->playSound = playS;
    this->showKeyboard = showK;

    UTComputer& utc = UTComputer::getInstance();
    utc.refreshUIWithNewSetting(this->nbLines, this->playSound, this->showKeyboard);
}

QList<const Litterale*> Controller::getNFirstLitteralsOnTheStack(unsigned int n) const {
    QList<const Litterale*> list;
    for(unsigned int i = 0; i < n; i++) {
        if (i < stack.size()) list.append(stack[i]);
    }
    return list;
}
