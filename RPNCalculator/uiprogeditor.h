#ifndef UIPROGEDITOR_H
#define UIPROGEDITOR_H

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
 * \brief Class UIProgEditor
 */
class UIProgEditor: public QMainWindow
{
    Q_OBJECT
    /*!
     * \brief instance
     */
    static UIProgEditor * instance;
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
     * \param parent QWidget
     */
    explicit UIProgEditor(QWidget *parent = 0);

    /*!
     * \brief destructeur
     */
    ~UIProgEditor() {
        delete message;
        delete pile;
        delete horizontalMainLayout;
    }

    /*!
     * \brief Constructeur par recopie
     * \param utc
     */
    UIProgEditor(const UIProgEditor& utc);

public:
    /*!
     * \brief getInstance
     * \param parent QWidget
     * \return Une instance de UIProgEditor
     */
    static UIProgEditor& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UIProgEditor(parent);
        return *instance;
    }

    /*!
     * \brief Libère l'instace
     */
    static void freeInstance() {
        if (instance) delete instance;
    }

    /*!
     * \brief Met à jout la vue de la pile
     */
    void refreshStackView();

    /*!
     * \brief Met à jour le message d'erreur
     * \param text
     */
    void updateMessage(const QString& text) {
        this->message->updateMessage(text);
    }

    /*!
     * \brief Actualise la vue de la pile et l'affiche à l'écran
     */
    void reloadAndShow(){
        pile->reloadView("IDPROG");
        this->show();
    }

public slots:
    /*!
     * \brief Supprime toutes les variables
     */
    void clearAll();
    /*!
     * \brief Crée une variable programme
     */
    void createVar();
    /*!
     * \brief Edite une variable programme
     */
    void editVar();
    /*!
     * \brief Supprime une variable programme
     */
    void deleteVar();
};

#endif // UIPROGEDITOR_H
