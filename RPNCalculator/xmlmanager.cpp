#include "xmlmanager.h"
#include "parseur.h"
#include "controller.h"
#include <QXmlStreamAttribute>
#include <QXmlStreamWriter>
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

XMLManager* XMLManager::instance = 0;

//================================================================================================================================================
//
//                          STACK
//
//================================================================================================================================================


void XMLManager::saveXMLFileStack()
{
    QXmlStreamWriter& xmlWriter = *(new QXmlStreamWriter());

    QFile* f;
    if (Controller::getInstance().getSystem() == true) {
        f = new QFile("/tmp/stack.xml");
    }
    else {
        f = new QFile("/tmp/stack.xml");
    }

    QFile& file = *f;

    if (!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::warning(0, "Error!", "Error opening file");
    }
    else
    {
        xmlWriter.setDevice(&file);

        /* Writes a document start with the XML version number. */
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("stack");

        // Writing the stack throught each element
        QList<Litterale*> stack = Controller::getInstance().getStack().getStackItems();
        QList<Litterale*>::iterator j;
        for (j = stack.begin(); j != stack.end(); ++j) {
            xmlWriter.writeStartElement("item");
            xmlWriter.writeCharacters ((*j)->getText());
            xmlWriter.writeEndElement();
        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();
    }
}

QList<Operande*> XMLManager::readXMLFileStack() {

    QXmlStreamReader& xmlReader = *(new QXmlStreamReader());
    QFile* f;
    if (Controller::getInstance().getSystem() == true) {
        f = new QFile("/tmp/stack.xml");
    }
    else {
        f = new QFile("/tmp/stack.xml");
    }

    QFile& xmlFile = *f;

    xmlFile.open(QIODevice::ReadOnly);
    xmlReader.setDevice(&xmlFile);

    QList<Operande*> res;
    while (xmlReader.readNextStartElement()) {

        if (xmlReader.name() == "stack")
            res = processStack(xmlReader);

        if (xmlReader.tokenType() == QXmlStreamReader::Invalid)
            xmlReader.readNext();

        if (xmlReader.hasError()) {
            xmlReader.raiseError();
            qDebug() << errorString(xmlReader);
        }
        xmlReader.skipCurrentElement();
    }
    return res;
}

QList<Operande*> XMLManager::processStack(QXmlStreamReader& xmlReader) {
    QList<Operande*> res;

    if (!xmlReader.isStartElement() || xmlReader.name() != "stack")
        return res;

    while (xmlReader.readNextStartElement()) {
        if (xmlReader.name() == "item") {
            QList<Operande*> L;
            QString text = readNextText(xmlReader);

            // Try en cas d'erreur lors de la création d'opérandes (division par 0 etc...)
            try {
                L = Parseur::NewListOperande(text);
                res.append(L.at(0));
            }
            catch (ExceptionRationnelle e) {
                std::cout << e.what().toStdString() << std::endl;
                return res;
            }
            catch (ExceptionWrongTypeOperande e) {
                std::cout << e.what().toStdString() << std::endl;
                return res;
            }
            catch (ExceptionAtome e) {
                std::cout << e.what().toStdString() << std::endl;
                return res;
            }
        }
        xmlReader.skipCurrentElement();
    }

    return res;
}

//================================================================================================================================================
//
//                          SETTINGS
//
//================================================================================================================================================

void XMLManager::saveXMLFileSettings()
{
    QXmlStreamWriter& xmlWriter = *(new QXmlStreamWriter());

    QFile* f;
    if (Controller::getInstance().getSystem() == true) {
        f = new QFile("/tmp/settings.xml");
    }
    else {
        f = new QFile("/tmp/settings.xml");
    }

    QFile& file = *f;

    if (!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::warning(0, "Error!", "Error opening file");
    }
    else
    {
        xmlWriter.setDevice(&file);

        /* Writes a document start with the XML version number. */
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("settings");

        Controller& ctrl= Controller::getInstance();

        xmlWriter.writeStartElement("showKeyboard");
        if (ctrl.settingShowKeyboard() == true)  xmlWriter.writeCharacters ("true");
        else xmlWriter.writeCharacters ("false");
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("playSound");
        if (ctrl.settingPlaySound() == true)  xmlWriter.writeCharacters ("true");
        else xmlWriter.writeCharacters ("false");
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("nbLines");
        xmlWriter.writeCharacters (QString::number(ctrl.settingNbLines()));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("unixSystem");
        if (ctrl.settingUnixSystem() == true)  xmlWriter.writeCharacters ("true");
        else xmlWriter.writeCharacters ("false");
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();
    }
}

bool XMLManager::readXMLFileSettings() {

    QXmlStreamReader& xmlReader = *(new QXmlStreamReader());
    QFile* f;
    if (Controller::getInstance().getSystem() == true) {
        f = new QFile("/tmp/settings.xml");
    }
    else {
        f = new QFile("/tmp/settings.xml");
    }

    QFile& xmlFile = *f;


    if (!xmlFile.open(QIODevice::ReadOnly))
    {
//      QMessageBox::warning(0, "Error!", "Error opening file");
      return false;
    }
    else {
        xmlReader.setDevice(&xmlFile);

        bool flag;
        while (xmlReader.readNextStartElement()) {

            if (xmlReader.name() == "settings")
                flag = processSettings(xmlReader);


            if (xmlReader.tokenType() == QXmlStreamReader::Invalid)
                xmlReader.readNext();

            if (xmlReader.hasError()) {
                xmlReader.raiseError();
                qDebug() << errorString(xmlReader);
            }
            xmlReader.skipCurrentElement();
        }
        return flag;
    }
}

bool XMLManager::processSettings(QXmlStreamReader& xmlReader) {

    if (!xmlReader.isStartElement() || xmlReader.name() != "settings")
        return false;

    Controller& ctrl= Controller::getInstance();

    while (xmlReader.readNextStartElement()) {

        if (xmlReader.name() == "showKeyboard") {
            QString text = readNextText(xmlReader);
            if (text == "true") ctrl.setShowKeyboard(true);
            else ctrl.setShowKeyboard(false);
        }
        else if (xmlReader.name() == "nbLines") {
            QString text = readNextText(xmlReader);
            ctrl.setNbLines(text.toInt());
            std::cout << ctrl.settingNbLines() << std::endl;
        }
        else if (xmlReader.name() == "playSound") {
            QString text = readNextText(xmlReader);
            if (text == "true") ctrl.setPlaySound(true);
            else ctrl.setPlaySound(false);
        }
        else if (xmlReader.name() == "unixSystem") {
            QString text = readNextText(xmlReader);
            if (text == "true") ctrl.setUnixSystem(true);
            else ctrl.setUnixSystem(false);
        }

        xmlReader.skipCurrentElement();
    }

    return true;
}


QString XMLManager::readNextText(QXmlStreamReader& xmlReader) {
    xmlReader.readNext();
    return xmlReader.text().toString();
}

QString XMLManager::errorString(QXmlStreamReader& xmlReader) {
    return QObject::tr("%1\nLine %2, column %3")
            .arg(xmlReader.errorString())
            .arg(xmlReader.lineNumber())
            .arg(xmlReader.columnNumber());
}
