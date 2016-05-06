#include "utcomputer.h"
#include "uibutton.h"
#include "uibuttonsline.h"
#include "uiclavier.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


UTComputer::UTComputer(QWidget *parent) : QMainWindow(parent), clavier(new UIKeyboard()), cmd(new UICommandLine()), message(new UIMessageLine()), pile(new UIPileView())
{
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

    QHBoxLayout* hlay = new QHBoxLayout();
    hlay->addWidget(pileModule);
    hlay->addWidget(clavier);

    container->setLayout(hlay);

    setCentralWidget(container);
}
