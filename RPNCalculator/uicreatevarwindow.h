#ifndef UICREATEVARWINDOW_H
#define UICREATEVARWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>

/*!
 * \brief Classe UICreateVarWindow
 * Fenêtre de création des variables
 */
class UICreateVarWindow : public QMainWindow
{
    Q_OBJECT
    /*!
     * \brief instance de la fenêtre
     */
    static UICreateVarWindow * instance;
    /*!
     * \brief Constructeur
     * \param parent QWidget parent
     * \param name Nom de la variable
     * \param content Contenu de la variable
     * \param type Type de variable
     */
    explicit UICreateVarWindow(QWidget* parent = 0, QString name = "", QString content = "", QString type = "");

    /*!
     * \brief Surchage du constructeur, permet la recopie
     * \param utc
     */
    UICreateVarWindow(const UICreateVarWindow& utc);

    //! Destructeur
    ~UICreateVarWindow() {}

    /*!
     * \brief body
     */
    QWidget* body;

    /*!
     * \brief layout
     */
    QVBoxLayout* layout;

    /*!
     * \brief Nom de la variable
     */
    QLineEdit* varName;

    /*!
     * \brief Contenu de la variable
     */
    QLineEdit* varContent;

    /*!
     * \brief message à afficher lors d'une erreur
     */
    QString message;

    /*!
     * \brief type de la variable
     */
    QString type;

public:
    /*!
     * \brief Permet d'acceder à une instance
     * \param parent QWiget partent
     * \param name Nom de la variable
     * \param content Contenu de la variable
     * \param type Type de la variable
     * \return UICreateVarWindow& Une instance de la fenetre
     */
    static UICreateVarWindow& getInstance(QWidget* parent = 0, QString name = "", QString content = "", QString type = "") {
        if (!instance) {
            instance = new UICreateVarWindow(parent, name, content, type);
        }
        return *instance;
    }

    /*!
     * \brief Affiche le nom de la variable
     * \param t
     */
    void setVarName(QString& t){
        varName->setText(t);
    }

    /*!
     * \brief Affiche le contenu de la variable
     * \param t
     */
    void setVarContent(QString& t){
        varContent->setText(t);
    }

    /*!
     * \brief Libère l'instance
     */
    static void freeInstance() {
        if (instance) delete instance;
    }

    /*!
     * \brief Actualise la fenêtre de création en fonction du type de variable a créer et l'affiche à l'écran
     * \param type Type de la variable à créer
     */
    void reloadAndShow(QString type){
        this->type = type;
        varName->clear();
        varContent->clear();
        this->show();
    }
    /*!
     * \brief Actualise la fenêtre de création en fonction du type de variable a créer et l'affiche à l'écran
     * \param name Nom de la variable
     * \param content Contenu de la variable
     * \param type Type de la variable
     */
    void reloadAndShow(QString name, QString content, QString type){
        this->type = type;
        varName->setText(name);
        varContent->setText(content);
        this->show();
    }

signals:

public slots:
    /*!
     * \brief Crée la variable
     */
    void saveChange();
    /*!
     * \brief Ferme la fenêtre
     */
    void closeWindow();
};


#endif // UICREATEVARWINDOW_H
