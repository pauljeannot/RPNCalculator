#ifndef UISETTINGWINDOW_H
#define UISETTINGWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QSpinBox>
#include <QSlider>

class UISettingWindow : public QMainWindow
{
    Q_OBJECT

    static UISettingWindow * instance;
    explicit UISettingWindow(QWidget *parent = 0);
    ~UISettingWindow() {    }
    UISettingWindow(const UISettingWindow& utc);

    QWidget* body;
    QVBoxLayout* layout;
    QSlider* slider;
    QSpinBox* nbLinesBox;
    QCheckBox* playSoundBox;
    QCheckBox* showKeyboardBox;


public:
    static UISettingWindow& getInstance(QWidget *parent = 0) {
        if (!instance) instance = new UISettingWindow(parent);
        return *instance;
    }

    static void freeInstance() {
        if (instance) delete instance;
    }

signals:

public slots:
    void updateSettings();

};

#endif // UISETTINGWINDOW_H
