#include "utcomputer.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    UTComputer fenetre;
    fenetre.show();
    return app.exec();
}
