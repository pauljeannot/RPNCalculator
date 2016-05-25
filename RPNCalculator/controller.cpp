#include "controller.h"
#include "utcomputer.h"
#include "ltcomplexe.h"
#include "parseur.h"
#include "litterale.h"
#include "operateur.h"
#include <QMessageBox>

Controller* Controller::instance = 0;

void Controller::computeLine(const QString& text) {
    std::cout << "C'est une littérale : " << text.toStdString() << std::endl;
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
    catch (ExceptionAtome e) {
        messageLine = e.what();
        computationEnded(messageLine);
        return;
    }
    catch (ExceptionSyntaxte e) {
        messageLine = e.what();
        computationEnded(messageLine);
        return;
    }

    // Parcours et affichage de la liste
    QList<Operande*>::iterator j;
    Litterale* lit;
    Operateur* op;
    QList<Litterale*> poped;


    for (j = L.begin(); j != L.end(); ++j) {
        std::cout << "Dans la boucle : " << (*j)->getText().toStdString() << std::endl;
        // Si c'est une Litterale
        if ((lit = dynamic_cast<Litterale*>(*j)) != nullptr) {

            this->saveContext();
            this->stack->push(lit);
        }

        // Sinon si c'est un opérateur
        else if ((op = dynamic_cast<Operateur*>(*j)) != nullptr) {
            int a = op->getArite();

            // Si jamais l'opérateur demandé est un UNDO ou REDO, on ne sauvegarde surtout pas la pile
            if(op->getText() != "UNDO" && op->getText() != "REDO") {
                this->saveContext();
            }

            // Try suivant les erreurs relatives à la pile ou à l'exécution de l'opérateur sur le litterale
            try {

                // Cas selon l'arité
                switch (a) {
                case 0: {
                    Litterale* res = computer.compute(op);
                    if (res != nullptr) this->stack->push(res->simplifier());
                    break;
                }

                    // Arité 1 :
                case 1: {
                    // on pop un élement
                    if (this->stack->canPopItems(1)) {
                        Litterale* l0 = this->stack->pop();
                        poped.append(l0);
                        Litterale* res = computer.compute(op, l0);
                        if (res != nullptr) this->stack->push(res->simplifier());
                    }
                    else {
                        messageLine = "Impossible : il faut au moins 1 élément dans la pile pour cet opérateur";
                    }
                    break;
                }
                    // Arité 2 :
                case 2: {
                    if (this->stack->canPopItems(2)) {
                        Litterale* l2 = this->stack->pop();
                        Litterale* l1 = this->stack->pop();
                        poped.append(l1);
                        poped.append(l2);
                        Litterale* res = computer.compute(op, l1, l2);
                        if (res != nullptr) this->stack->push(res->simplifier());
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
                messageLine = e.what();
                if (poped.size() > 0)
                    this->stack->push(poped.at(0));
                if (poped.size() > 1)
                    this->stack->push(poped.at(1));
            }
            catch (ExceptionMemento e) {
                messageLine = e.what();
            }
            catch (ExceptionSyntaxte e) {
                messageLine = e.what();
            }
        }
    }

    computationEnded(messageLine);
}

void Controller::computationEnded(QString messageLine) {

    this->saveStackInFile();
//    this->readStackFromFile();

    UTComputer& utc = UTComputer::getInstance();
    utc.updateMessage(messageLine);
    utc.refreshStackView();
    utc.clearCommandLine();
}

void Controller::updateSettings(unsigned int nb, bool playS, bool showK) {
    this->nbLines = nb;
    this->playSound = playS;
    this->showKeyboard = showK;
    this->saveSettingsInFile();

    UTComputer& utc = UTComputer::getInstance();
    utc.refreshUIWithNewSetting(this->nbLines, this->playSound, this->showKeyboard);
}

QList<const Litterale*> Controller::getNFirstLitteralsOnTheStack(unsigned int n) const {
    QList<const Litterale*> list;
    for(unsigned int i = 0; i < n; i++) {
        if (i < stack->size()) list.append((*stack)[i]);
    }
    return list;
}

void Controller::saveContext() {
    currentStackIndex++;
    this->stack = this->stack->clone();
    originator.setStack(this->stack);
    careTaker.addMemento(originator.storeInMemento(), currentStackIndex);
}

void Controller::saveStackInFile() const {
    this->xmlManager.saveXMLFileStack();
}

void Controller::saveSettingsInFile() const {
    this->xmlManager.saveXMLFileSettings();
}

void Controller::readStackFromFile() const {
    QList<Operande*> list = this->xmlManager.readXMLFileStack();

    for (int i = list.size() - 1; i >= 0; i--) {
        Litterale* l = dynamic_cast<Litterale*>(list.at(i));
        if (l != nullptr) this->stack->push(l);
    }
}

void Controller::readSettingsFromFile() {

    if (this->xmlManager.readXMLFileSettings() == true) {
        initDone = true;

    }
    else {
        initDone = false;
    }

}


void Controller::undoFunction() {
    if(currentStackIndex >= 1) {
        currentStackIndex--;
        this->stack = originator.restoreFromMemento(careTaker.getMemento(currentStackIndex));
        this->computationEnded("");
    }
    else {
        throw ExceptionMemento(ExceptionMemento::Type::CANNOT_UNDO, "Impossible de revenir en arrière.");
    }
}

void Controller::redoFunction() {
    if (careTaker.size() - 1 > currentStackIndex) {
        currentStackIndex++;
        this->stack = originator.restoreFromMemento(careTaker.getMemento(currentStackIndex));
        this->computationEnded("");
    }
    else {
        throw ExceptionMemento(ExceptionMemento::Type::CANNOT_UNDO, "Impossible de revenir en arrière.");
    }
}

void Controller::initEnded() {

    this->readSettingsFromFile();

    if (initDone == false) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Emplacement du fichier de sauvegarde");
        msgBox.setText("Le fichier de sauvegarde permet de garder une trace des dernières utilisations de RPNCalculator et ainsi de mémoriser les programmes/variables que vous avez écrits. Celui-ci est enregistré dans le dossier temporaire de votre ordinateur. Êtes-vous sous un système Unix ?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(msgBox.exec() == QMessageBox::Yes) {
            unixSystem = true;
        }
        else {
            unixSystem = false;
        }
        initDone = true;

        // Write
        this->saveSettingsInFile();
        this->saveStackInFile();
    }
    else {
        // Read and push on stack
        this->readStackFromFile();
        this->saveContext();
    }
}
