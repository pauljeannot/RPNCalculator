#include "uicreatevarwindow.h"
#include "controller.h"
#include "operandefactory.h"
#include "uivareditor.h"
#include "uiprogeditor.h"
#include "exception.h"

#include <iostream>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

UICreateVarWindow * UICreateVarWindow::instance = 0;

UICreateVarWindow::UICreateVarWindow(QWidget *parent, QString name, QString content, QString type) :QMainWindow(parent), type(type), body(new QWidget(this)), layout(new QVBoxLayout(body))
{
    // On récupère une instance du controller
    Controller& ctl = Controller::getInstance();
    QHBoxLayout* hlay = new QHBoxLayout();
    hlay->setAlignment(Qt::AlignRight);

    // Taille de la fenetre (width, height)
    this->setFixedSize(350,200);

    // Création de l'éditeur
    varName = new QLineEdit();
    varName->setPlaceholderText("Variable name");
    varName->isUndoAvailable();
    varName->isRedoAvailable();
    if(!name.isEmpty()) varName->setText(name);

    varContent = new QLineEdit();
    varContent->setPlaceholderText("Variable content");
    varContent->isUndoAvailable();
    varContent->isRedoAvailable();
     if(!content.isEmpty()) varContent->setText(content);

    this->layout->addWidget(varName);
    this->layout->addWidget(varContent);

    // Création des boutons
    QPushButton* Cancel = new QPushButton("Cancel", body);
    Cancel->setFixedHeight(40);
    Cancel->setFlat(true);

    QPushButton* Create = new QPushButton("Create", body);
    Create->setFixedHeight(40);
    Create->setFlat(true);

    // Modification de la couleur des boutons
    QPalette palCancel = Cancel->palette();
    palCancel.setColor(QPalette::Button, QColor(255,255,255));
    Cancel->setAutoFillBackground(true);
    Cancel->setPalette(palCancel);
    Cancel->update();

    QPalette palCreate = Create->palette();
    palCreate.setColor(QPalette::Button, QColor(255,255,255));
    Create->setAutoFillBackground(true);
    Create->setPalette(palCreate);
    Create->update();

    // Ajout des boutons dans le layout horizontal
    hlay->addWidget(Cancel);
    hlay->addWidget(Create);
    hlay->setSpacing(9);
    this->layout->addLayout(hlay);

    // Connexion des boutons avec l'application
    QObject::connect(Cancel, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));
    QObject::connect(Create, SIGNAL(clicked(bool)), this, SLOT(saveChange()));

    body->setLayout(layout);
    setCentralWidget(body);

}


void UICreateVarWindow::saveChange(){
    QString name = varName->text().toUpper();
    QString content = varContent->text();

    if(!name.isEmpty() && !content.isEmpty())
        Controller::getInstance().computeLine(content + " " + name + "  STO");
    else{
        QMessageBox::warning(0, "Erreur", "L'un des champs est vide.");
        return;
    }

    this->close();
    if(type == "IDVAR")
        UIVarEditor::getInstance().refreshStackView();
    else
        UIProgEditor::getInstance().refreshStackView();
}

void UICreateVarWindow::closeWindow(){
    this->close();
}



