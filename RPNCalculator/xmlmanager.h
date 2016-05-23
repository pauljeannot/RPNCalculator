#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "operande.h"
#include <QtXml>
#include <iostream>
#include <QFile>

class XMLManager
{
    static XMLManager* instance;
    XMLManager() {}
    ~XMLManager() {}
    XMLManager(const XMLManager& c);

public :
    static XMLManager& getInstance() {
        if (!instance) instance = new XMLManager();
        return *instance;
    }

    static void freeInstance() { if (instance) delete instance; }

    void saveXMLFileStack();
    void saveXMLFileSettings();

    QList<Operande *> readXMLFileStack();
    bool readXMLFileSettings();

private:
    QList<Operande*> processStack(QXmlStreamReader& xmlReader);
    bool processSettings(QXmlStreamReader& xmlReader);

    QString readNextText(QXmlStreamReader& xmlReader);
    QString errorString(QXmlStreamReader& xmlReader);

    QString _filename;

};

#endif // XMLMANAGER_H
