#include "controller.h"
#include "utcomputer.h"
#include "parseur.h"
#include "litterale.h"
#include "operateur.h"

Controller* Controller::instance = 0;

void Controller::computeLine(const QString& text) {

    QList<Operande*> L = Parseur::NewListOperande(text);
    // Parcours et affichage de la liste

    QList<Operande*>::iterator j;
    for (j = L.begin(); j != L.end(); ++j) {
        Litterale* lit = dynamic_cast<Litterale*>(*j);
        if (lit != nullptr) {
            this->stack.push(lit);
        }
        else {
            Operateur* op = dynamic_cast<Operateur*>(*j);
            if (op != nullptr) {
                int a = op->getArite();

                switch (a) {
                case 0: {
                    break;
                }
                case 1: {
                    Litterale* l0 = this->stack.pop();
                    break;
                }
                case 2: {
                    Litterale* l2 = this->stack.pop();
                    Litterale* l1 = this->stack.pop();
                    break;
                }
                default:
                    break;
                }
            }
        }
    }

    UTComputer& utc = UTComputer::getInstance();
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

