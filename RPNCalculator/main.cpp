#include "utcomputer.h"
#include "operande.h"
#include "parseur.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    UTComputer& fenetre = UTComputer::getInstance();
    fenetre.show();
    app.exec();
    UTComputer::freeInstance();
    return 0;
}
