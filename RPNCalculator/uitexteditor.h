#ifndef UITEXTEDITOR_H
#define UITEXTEDITOR_H

#include "ltatome.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>

/*!
 * \brief Classe UITextEditor
 */
class UITextEditor : public QMainWindow
{
    Q_OBJECT
    /*!
     * \brief instance
     */
    static UITextEditor * instance;

    /*!
     * \brief Constructeur
     * \param texte Texte a afficher dans l'éditeur
     * \param atome Atome lié a la Litterale donc nous affichons le texte
     * \param parent QWidget
     */
    explicit UITextEditor(QString texte, LTAtome* atome = nullptr, QWidget* parent = 0);

    /*!
     * \brief Constructeur de recopie
     * \param utc
     */
    UITextEditor(const UITextEditor& utc);

    /*!
     * \brief Destructeur
     */
    ~UITextEditor() {}

    QWidget* body;
    QVBoxLayout* layout;
    QTextEdit* editor;
    QString message;
    LTAtome* atomeRef;

public:
    /*!
     * \brief getInstance
     * \param texte Texte a afficher dans l'éditeur
     * \param atome Atome lié a la Litterale donc nous affichons le texte
     * \param parent QWidget parent
     * \return
     */
    static UITextEditor& getInstance(QString texte, LTAtome* atome = 0, QWidget* parent = 0) {
        if (!instance) {
            instance = new UITextEditor(texte, atome, parent);
        }
        else{
            instance->setEditor(texte);
            instance->setatomeRef(atome);
        }
        return *instance;
    }

    /*!
     * \brief Affiche un texte dans l'éditeur
     * \param t Texte a afficher
     */
    void setEditor(QString& t){
        editor->setPlainText(t);
    }

    /*!
     * \brief Affecte un pointeur d'atome à l'atome référençant
     * \param a Atome dont on veut afficher la valeur
     */
    void setatomeRef(LTAtome* a){
        atomeRef = a;
    }

    /*!
     * \brief Libère l'instance
     */
    static void freeInstance() {
        if (instance) delete instance;
    }

signals:

public slots:
    /*!
     * \brief Enregistre les changements de la littérale pointée par l'atome
     */
    void saveChange();
    /*!
     * \brief Ferme la fenêtre
     */
    void closeWindow();
};

#endif // UITEXTEDITOR_H
