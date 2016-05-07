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

    QObject::connect(this->cmd, SIGNAL(textChanged(QString)),
                     this, SLOT(commandeLineChanged(const QString)));

    QObject::connect(this->cmd, SIGNAL(returnPressed()),
                     this, SLOT(commandeLineEnterPressed()));
}

void UTComputer::commandeLineEnterPressed() {
    Controller& controller = Controller::getInstance();
    controller.computeLine(cmd->text());
    this->showKeyboard();
}

void UTComputer::commandeLineChanged(const QString text) {

    QStringList textSplitted = text.split(" ");
    QString lastOperande = textSplitted.value(textSplitted.length()-1);
    QList<QString> ops({"+", "-", "*", "/", "$"});
    if (ops.contains(lastOperande)) {
        Controller& controller = Controller::getInstance();
        controller.computeLine(text);
    }
}

void UTComputer::writeInCommandeLine(const QString& text) {
    if(text == "ENTER") commandeLineEnterPressed();
    else if(text == "BACK") {
        cmd->deleteLastCharacter();
        this->hideKeyboard();
    }
    else {
        this->cmd->write(text);
        QList<QString> ops({"+", "-", "*", "/", "$","0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " "});
        if (!ops.contains(text)) {
            Controller& controller = Controller::getInstance();
            controller.computeLine(cmd->text());
        }
    }
}




