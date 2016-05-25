#include "uivareditor.h"


UIVarEditor * UIVarEditor::instance = 0;

UIVarEditor::UIVarEditor(QWidget *parent) : QMainWindow(parent), body(new QWidget(this)), message(new UIMessageLine()), pile(new UIPileView()), horizontalMainLayout(new QHBoxLayout())
{
    this->setFixedSize(800, 500);
    int width = 300;
    QWidget* container = new QWidget(this);
    QWidget* pileModule = new QWidget(container);

    // Layout vertical contenant les boutons
    QVBoxLayout* vlay = new QVBoxLayout();
    vlay->setAlignment(Qt::AlignRight);

    // Création des boutons
    QPushButton* ajout = new QPushButton("Créer une variable", body);
    ajout->setFixedHeight(40);
    ajout->setFixedWidth(width);
    ajout->setFlat(true);

    QPushButton* edition = new QPushButton("Editer la variable sélectionnée", body);
    edition->setFixedHeight(40);
    edition->setFixedWidth(width);
    edition->setFlat(true);

    QPushButton* suppression = new QPushButton("Supprimer la variable sélectionnée", body);
    suppression->setFixedHeight(40);
    suppression->setFixedWidth(width);
    suppression->setFlat(true);

    QPushButton* infos = new QPushButton("Inspecter la variable sélectionnée", body);
    infos->setFixedHeight(40);
    infos->setFixedWidth(width);
    infos->setFlat(true);

    QPushButton* clearall = new QPushButton("Supprimer toutes les variables", body);
    clearall->setFixedHeight(40);
    clearall->setFixedWidth(width);
    clearall->setFlat(true);

    // Modification de la couleur des boutons
    QPalette palAjout = ajout->palette();
    palAjout.setColor(QPalette::Button, QColor(255,255,255));
    ajout->setAutoFillBackground(true);
    ajout->setPalette(palAjout);
    ajout->update();

    QPalette palEdition = edition->palette();
    palEdition.setColor(QPalette::Button, QColor(255,255,255));
    edition->setAutoFillBackground(true);
    edition->setFixedWidth(width);
    edition->setPalette(palEdition);
    edition->update();

    QPalette palSuppression = suppression->palette();
    palSuppression.setColor(QPalette::Button, QColor(255,255,255));
    suppression->setAutoFillBackground(true);
    suppression->setFixedWidth(width);
    suppression->setPalette(palSuppression);
    suppression->update();

    QPalette palInfos = infos->palette();
    palInfos.setColor(QPalette::Button, QColor(255,255,255));
    infos->setAutoFillBackground(true);
    infos->setFixedWidth(width);
    infos->setPalette(palInfos);
    infos->update();

    QPalette pasClearAll = clearall->palette();
    pasClearAll.setColor(QPalette::Button, QColor(255,255,255));
    clearall->setAutoFillBackground(true);
    clearall->setFixedWidth(width);
    clearall->setPalette(pasClearAll);
    clearall->update();

    // Ajout des boutons dans le layout horizontal
    vlay->addWidget(ajout);
    vlay->addWidget(edition);
    vlay->addWidget(suppression);
    vlay->addWidget(infos);
    vlay->addWidget(clearall);

    vlay->setSpacing(15);



    QVBoxLayout* pileModuleLayout = new QVBoxLayout();
    pileModuleLayout->addWidget(message);
    pileModuleLayout->addWidget(pile);
    pileModuleLayout->setAlignment(Qt::AlignLeft);
    pileModuleLayout->setSpacing(0);
    pileModuleLayout->setContentsMargins(0, 0, 0, 0);
    pileModule->setLayout(pileModuleLayout);

    horizontalMainLayout->addWidget(pileModule);
    horizontalMainLayout->addLayout(vlay);
    Controller& controller = Controller::getInstance();

    container->setLayout(horizontalMainLayout);
    setCentralWidget(container);
}


void UIVarEditor::refreshStackView() {
   this->pile->reloadView();
}
