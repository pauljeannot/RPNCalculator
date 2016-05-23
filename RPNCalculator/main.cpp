#include "utcomputer.h"
#include "controller.h"
#include "xmlmanager.h"
#include <QApplication>
#include <QDir>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    Controller& ctrl = Controller::getInstance();

    UTComputer& fenetre = UTComputer::getInstance();
    fenetre.show();
    app.exec();
    UTComputer::freeInstance();
    return 0;
}
