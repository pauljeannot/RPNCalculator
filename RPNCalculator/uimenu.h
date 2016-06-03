#ifndef UIMENU_H
#define UIMENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "uisettingwindow.h"

/*!
 * \brief Classe UIMenu, permet de d'accéder aux vues secondaires de la calculatrice
 */
class UIMenu : public QWidget
{
    Q_OBJECT

    /*!
     * \brief layout
     */
    QVBoxLayout* layout;
    /*!
     * \brief Bouton vers la fenêtre de paramètres
     */
    QPushButton* settingButton;

    /*!
     * \brief Bouton vers la fenêtre de revenir en arrière
     */
    QPushButton* undoButton;

    /*!
     * \brief Bouton permettant de revenir en avant
     */
    QPushButton* redoButton;

    /*!
     * \brief Bouton vers la fenêtre de gestion des variables
     */
    QPushButton* varButton;

    /*!
     * \brief Bouton vers la fenêtre de gestion des programmes
     */
    QPushButton* progButton;

    /*!
     * \brief Bouton vers la fenêtre de paramètre
     */
    UISettingWindow& settingWindow;

public:
    /*!
     * \brief Constructeur
     * \param parent QWidget
     */
    explicit UIMenu(QWidget *parent = 0);

    //! Destructeur
    //! Libère l'instance
    ~UIMenu() {
        UISettingWindow::freeInstance();
    }

signals:

public slots:
    /*!
     * \brief Ouvre la fenêtre des paramètres
     */
    void openSetting();

    /*!
     * \brief Permet d'annuler une opération
     */
    void undoFunction();

    /*!
     * \brief Permet de refaire une opération
     */
    void redoFunction();

    /*!
     * \brief Ouvre la fenêtre de gestion des variables
     */
    void varFunction();

    /*!
     * \brief Ouvre la fenêtre de gestion des programmes
     */
    void progFunction();

};

#endif // UIMENU_H
