#ifndef UIVAREDITOR_H
#define UIVAREDITOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "uicommandeline.h"
#include "uimessageline.h"
#include "uipilevarview.h"
#include "uimenu.h"
#include <iostream>
#include <QList>
/*!
 * \brief Classe UIVarEditor
 */
class UIVarEditor: public QMainWindow
{
    Q_OBJECT
    /*!
     * \brief instance
     */
    static UIVarEditor * instance;
    /*!
     * \brief body
     */
    QWidget* body;
    /*!
     * \brief message
     */
    UIMessageLine* message;
    /*!
     * \brief pile
     */
    UIPileVarView * pile;
    /*!
     * \brief horizontalMainLayout
     */
    QHBoxLayout* horizontalMainLayout;

    /*!
     * \brief Constructeur
     * \param parent
     */
    explicit UIVarEditor(QWidget *parent = 0);

    /*!
     * \brief Destructeur
     */
    ~UIVarEditor() {
        delete message;
        delete pile;
        delete horizontalMainLayout;
    }
    /*!
     * \brief Constructeur par recopie
     * \param utc
     */
    UIVarEditor(const UIVarEditor& utc);

public:
    /*!
     * \brief getInstance
     * \param parent
     * \return
     */
    static UIVarEditor& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UIVarEditor(parent);
        return *instance;
    }

    /*!
     * \brief Libère l'instance
     */
    static void freeInstance() {
        if (instance) delete instance;
    }

    /*!
     * \brief Met a jour la vue de la pile
     */
    void refreshStackView();

    /*!
     * \brief Met a jour le message d'erreur à destination de l'utilisation
     * \param text
     */
    void updateMessage(const QString& text) {
        this->message->updateMessage(text);
    }

    /*!
     * \brief Met à jour la pile en fonction du type de variable et l'affiche
     */
    void reloadAndShow(){
        pile->reloadView("IDVAR");
        this->show();
    }

public slots:
    /*!
     * \brief Supprimer toutes les variables
     */
    void clearAll();
    /*!
     * \brief Crée une nouvelle variable
     */
    void createVar();
    /*!
     * \brief Edite une variable
     */
    void editVar();
    /*!
     * \brief Supprime une variable
     */
    void deleteVar();
};


#endif // UIVAREDITOR_H
