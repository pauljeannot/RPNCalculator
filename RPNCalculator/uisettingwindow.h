#ifndef UISETTINGWINDOW_H
#define UISETTINGWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QSpinBox>
#include <QSlider>
/*!
 * \brief Fenêtre de gestion des paramètres
 */
class UISettingWindow : public QMainWindow
{
    Q_OBJECT
    /*!
     * \brief instance
     */
    static UISettingWindow * instance;
    /*!
     * \brief Constructeur
     * \param parent
     */
    explicit UISettingWindow(QWidget *parent = 0);

    //! Destructeur
    ~UISettingWindow() {    }
    /*!
     * \brief Constructeur par recopie
     * \param utc
     */
    UISettingWindow(const UISettingWindow& utc);

    /*!
     * \brief body
     */
    QWidget* body;
    /*!
     * \brief layout
     */
    QVBoxLayout* layout;
    /*!
     * \brief slider
     */
    QSlider* slider;
    /*!
     * \brief nbLinesBox
     */
    QSpinBox* nbLinesBox;
    /*!
     * \brief playSoundBox
     */
    QCheckBox* playSoundBox;
    /*!
     * \brief showKeyboardBox
     */
    QCheckBox* showKeyboardBox;


public:
    /*!
     * \brief getInstance
     * \param parent
     * \return
     */
    static UISettingWindow& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UISettingWindow(parent);
        return *instance;
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
     * \brief Met à jout les paramètres
     */
    void updateSettings();

};

#endif // UISETTINGWINDOW_H
