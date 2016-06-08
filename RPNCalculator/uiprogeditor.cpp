#include "uiprogeditor.h"
#include "uicreatevarwindow.h"
#include "ltatomemanager.h"
#include <QMessageBox>

UIProgEditor * UIProgEditor::instance = 0;

UIProgEditor::UIProgEditor(QWidget *parent) : QMainWindow(parent), body(new QWidget(this)), message(new UIMessageLine()), pile(new UIPileVarView("IDPROG")),  horizontalMainLayout(new QHBoxLayout())
{
    this->setFixedSize(700, 400);
    int width = 300;
    QWidget* container = new QWidget(this);
    QWidget* pileModule = new QWidget(container);

    // Layout vertical contenant les boutons
    QVBoxLayout* vlay = new QVBoxLayout();
    vlay->setAlignment(Qt::AlignRight);

    // Création des boutons
    QPushButton* ajout = new QPushButton("Créer un programme", body);
    ajout->setFixedHeight(40);
    ajout->setFixedWidth(width);
    ajout->setFlat(true);

    QPushButton* edition = new QPushButton("Editer le programme sélectionné", body);
    edition->setFixedHeight(40);
    edition->setFixedWidth(width);
    edition->setFlat(true);

    QPushButton* suppression = new QPushButton("Supprimer le programme sélectionné", body);
    suppression->setFixedHeight(40);
    suppression->setFixedWidth(width);
    suppression->setFlat(true);


    QPushButton* clearall = new QPushButton("Supprimer tous les programmes", body);
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

    QPalette pasClearAll = clearall->palette();
    pasClearAll.setColor(QPalette::Button, QColor(255,255,255));
    clearall->setAutoFillBackground(true);
    clearall->setFixedWidth(width);
    clearall->setPalette(pasClearAll);
    clearall->update();

    try{
        QObject::connect(clearall, SIGNAL(clicked(bool)), this, SLOT(clearAll()));
        QObject::connect(ajout, SIGNAL(clicked(bool)), this, SLOT(createVar()));
        QObject::connect(edition, SIGNAL(clicked(bool)), this, SLOT(editVar()));
        QObject::connect(suppression, SIGNAL(clicked(bool)), this, SLOT(deleteVar()));
    }
    catch(ExceptionEmptyField e){
        message->setText(e.what());
    }


    // Ajout des boutons dans le layout horizontal
    vlay->addWidget(ajout);
    vlay->addWidget(edition);
    vlay->addWidget(suppression);
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


void UIProgEditor::refreshStackView() {
   this->pile->reloadView("IDPROG");
}


void UIProgEditor::clearAll() {
   this->pile->clearAll();
}

void UIProgEditor::createVar() {
    UICreateVarWindow::getInstance().reloadAndShow("IDPROG");
    XMLManager::getInstance().saveXMLFileAtomeManager();
}

void UIProgEditor::editVar(){
    if(this->pile->selectedItems().count() == 1){
        // Récupération de l'index de la variable sélectionnée
        int pos = this->pile->row(this->pile->selectedItems().takeFirst());
        // Récupération des informations de la variable
        QString varName = this->pile->verticalHeaderItem(pos)->text();
        QString varContent = this->pile->selectedItems().takeFirst()->text();
        // Suppression de l'ancienne variable
        LTAtomeManager::getInstance().remove(varName);
        // Création de la nouvelle variable
        UICreateVarWindow::getInstance().reloadAndShow(varName, varContent, "IDPROG");
    }
    else if(this->pile->selectedItems().count() > 1)
        QMessageBox::warning(0, "Erreur", "Vous ne pouvez editer qu'un élément à la fois");
    else
        QMessageBox::warning(0, "Erreur", "Vous devez sélectionner un élément.");


}

void UIProgEditor::deleteVar(){
    if(this->pile->selectedItems().count() == 1){
        // Récupération de l'index de la variable sélectionnée
        int pos = this->pile->row(this->pile->selectedItems().takeFirst());
        // Récupération du nom de la variable à partir de l'index
        QString varName = this->pile->verticalHeaderItem(pos)->text();
        // Suppression de la variable dans le Dictionnary
        LTAtomeManager::getInstance().remove(varName);
        // Mise à jour visuelle de la pile
        refreshStackView();
        // Sauvegarde de l'état de la pile
        XMLManager::getInstance().saveXMLFileAtomeManager();
    }
    else if(this->pile->selectedItems().count() > 1)
        QMessageBox::warning(0, "Erreur", "Vous ne pouvez supprimer qu'un élément à la fois");
    else
        QMessageBox::warning(0, "Erreur", "Vous devez sélectionner un élément.");

}

