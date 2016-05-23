#ifndef XMLMANAGER_H
#define XMLMANAGER_H

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

    void saveXMLFile();
    void readXMLFile();

    void read();

private:
    void processRates();
    void processRate();
    void processNombre();
    QString readNextText();
    QString errorString();

    QString _filename;
    QXmlStreamReader xml;

};

#endif // XMLMANAGER_H
