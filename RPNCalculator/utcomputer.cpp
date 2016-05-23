#include "utcomputer.h"
#include "uibutton.h"
#include "uibuttonsline.h"
#include "uiclavier.h"
#include "controller.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

UTComputer * UTComputer::instance = 0;

UTComputer::UTComputer(QWidget *parent) : QMainWindow(parent), cmd(new UICommandLine()), message(new UIMessageLine()), clavier(new UIKeyboard()), pile(new UIPileView()), horizontalMainLayout(new QHBoxLayout()), menu(new UIMenu())
{
    this->setFixedSize(800, 500);

    QWidget* container = new QWidget(this);
    QWidget* pileModule = new QWidget(container);

    QVBoxLayout* pileModuleLayout = new QVBoxLayout();
    pileModuleLayout->addWidget(message);
    pileModuleLayout->addWidget(pile);
    pileModuleLayout->addWidget(cmd);
    pileModuleLayout->setAlignment(Qt::AlignLeft);
    pileModuleLayout->setSpacing(0);
    pileModuleLayout->setContentsMargins(0, 0, 0, 0);
    pileModule->setLayout(pileModuleLayout);

    horizontalMainLayout->addWidget(menu);
    horizontalMainLayout->addWidget(pileModule);
    this->showKeyboard();

    container->setLayout(horizontalMainLayout);
    setCentralWidget(container);

    QObject::connect(this->cmd, SIGNAL(textEdited(QString)),
                     this, SLOT(commandeLineEdited(const QString)));

    QObject::connect(this->cmd, SIGNAL(returnPressed()),
                     this, SLOT(commandeLineEnterPressed()));
}


// Appelée lorsqu'on appuie sur enter
void UTComputer::commandeLineEnterPressed() {

    Controller& controller = Controller::getInstance();
    controller.computeLine(cmd->text());
}


// Appelée lorsque le texte dans la commandeLine change (par le clavier de l'user)
void UTComputer::commandeLineEdited(const QString text) {

    QString lastOperande = text.right(1);

    // Si la dernière opérande entrée correspond à une evaluatedOperandes, on évalue directement
    if (evaluatedOperandes.contains(lastOperande) && !isInExpression(text) && !isInProgram(text)) {
        Controller& controller = Controller::getInstance();
        controller.computeLine(text);
    }
}

// Appelée lors d'un clic sur un bouton, text correspond à la valeur du bouton
void UTComputer::writeInCommandeLine(const QString& text) {

    // Si l'utilisateur clique sur ENTER, on évalue
    if(text == "ENTER") commandeLineEnterPressed();

    // Si l'utilisateur clique sur BACK, on supprime un caractère
    else if(text == "BACK") {
        cmd->deleteLastCharacter();
    }

    // SINON, on écrit directement dans la ligne de commande
    else {
        this->cmd->write(text);

        // Si ce n'est pas une softOperandes, alors on évalue
        if (!softOperandes.contains(text)) {
            Controller& controller = Controller::getInstance();
            controller.computeLine(cmd->text());
        }
    }
}

void UTComputer::refreshUIWithNewSetting(unsigned int nbLines, bool playS, bool showK) {
    if (showK) this->showKeyboard();
    else this->hideKeyboard();
    this->pile->reloadView(nbLines);
    this->message->setPlaySound(playS);
}

void UTComputer::refreshStackView() {
   this->pile->reloadView();
}

bool UTComputer::isInExpression(const QString& text) {
    QStringList textSplitted = text.split("'");
    if (textSplitted.size() > 1 && (textSplitted.size() % 2 == 0)) {
        std::cout << "Dans une expression : " << textSplitted.size() << " && " << textSplitted.size() % 2 << std::endl;
        return true;
    }
    else {
        return false;
    }
}

bool UTComputer::isInProgram(const QString& text) {
    QStringList textSplitted = text.split("[");
    QStringList textSplitted2 = text.split("]");
    if (textSplitted.size() != textSplitted2.size()) {
        std::cout << "Dans un programme : " << textSplitted.size() << " != " << textSplitted2.size() << std::endl;
        return true;
    }
    else {
        return false;
    }
}

