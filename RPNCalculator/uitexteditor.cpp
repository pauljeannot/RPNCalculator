#include "uitexteditor.h"
#include "controller.h"

#include <iostream>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

UITextEditor * UITextEditor::instance = 0;

UITextEditor::UITextEditor(QString texte, QWidget *parent) :QMainWindow(parent), body(new QWidget(this)), layout(new QVBoxLayout(body))
{

    // On récupère une instance du controller
    Controller& ctl = Controller::getInstance();
    QHBoxLayout* hlay = new QHBoxLayout();
    hlay->setAlignment(Qt::AlignRight);

    // Taille de la fenetre (width, height)
    this->setFixedSize(600,250);

    // Création de l'éditeur
    editor = new QTextEdit();
    editor->setUndoRedoEnabled(true);
    editor->setDocumentTitle("Program & Expression Editor");
    editor->setPlainText(texte);

    this->layout->addWidget(editor);

    // Création des boutons
    QPushButton* Cancel = new QPushButton("Cancel", body);
    Cancel->setFixedHeight(40);
    Cancel->setFlat(true);

    QPushButton* Save = new QPushButton("Save", body);
    Save->setFixedHeight(40);
    Save->setFlat(true);

    // Modification de la couleur des boutons
    QPalette palCancel = Cancel->palette();
    palCancel.setColor(QPalette::Button, QColor(255,255,255));
    Cancel->setAutoFillBackground(true);
    Cancel->setPalette(palCancel);
    Cancel->update();

    QPalette palSave = Save->palette();
    palSave.setColor(QPalette::Button, QColor(255,255,255));
    Save->setAutoFillBackground(true);
    Save->setPalette(palSave);
    Save->update();

    // Ajout des boutons dans le layout horizontal
    hlay->addWidget(Cancel);
    hlay->addWidget(Save);
    hlay->setSpacing(9);

    // Connexion des boutons avec l'application
    QObject::connect(Cancel, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));
    QObject::connect(Save, SIGNAL(clicked(bool)), this, SLOT(saveChange()));

    // Ajout du layout horizontal dans le layout vertical
    this->layout->addLayout(hlay);

    body->setLayout(layout);
    setCentralWidget(body);

}


void UITextEditor::saveChange(){
    QString text = editor->toPlainText();
    Controller::getInstance().computeLine(text);
    this->close();
}

void UITextEditor::closeWindow(){
    this->close();
}

