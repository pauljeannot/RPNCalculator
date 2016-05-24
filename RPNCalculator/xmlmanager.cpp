#include "xmlmanager.h"
#include "parseur.h"
#include "controller.h"
#include "ltatomemanager.h"
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

//================================================================================================================================================
//
//                          ATOMEMANAGER
//
//================================================================================================================================================


void XMLManager::saveXMLFileAtomeManager() {

    QXmlStreamWriter& xmlWriter = *(new QXmlStreamWriter());

    QFile* f;
    if (Controller::getInstance().getSystem() == true) {
        f = new QFile("/tmp/atomemanager.xml");
    }
    else {
        f = new QFile("/tmp/atomemanager.xml");
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
        xmlWriter.writeStartElement("atomemanager");

        QMap<QString, LTAtome*> dictionnary = LTAtomeManager::getInstance().getDictionnary();

        QMap<QString, LTAtome*>::iterator i;
        for (i = dictionnary.begin(); i != dictionnary.end(); ++i) {

                xmlWriter.writeStartElement("atome");

                xmlWriter.writeStartElement("value");
                xmlWriter.writeCharacters (i.key());
                xmlWriter.writeEndElement();

                xmlWriter.writeStartElement("nature");
                xmlWriter.writeCharacters (i.value()->getEnumString());
                xmlWriter.writeEndElement();

                    xmlWriter.writeStartElement("pointer");
                    if (i.value()->getPointer() != nullptr)
                        xmlWriter.writeCharacters (i.value()->getPointer()->getText());
                    xmlWriter.writeEndElement();


                xmlWriter.writeEndElement();
        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();
    }
}


QMap<QString, LTAtome*> XMLManager::readXMLFileAtomeManager() {

    QXmlStreamReader& xmlReader = *(new QXmlStreamReader());
    QFile* f;
    QMap<QString, LTAtome*> dic;

    if (Controller::getInstance().getSystem() == true) {
        f = new QFile("/tmp/atomemanager.xml");
    }
    else {
        f = new QFile("/tmp/atomemanager.xml");
    }

    QFile& xmlFile = *f;


    if (!xmlFile.open(QIODevice::ReadOnly))
    {
//      QMessageBox::warning(0, "Error!", "Error opening file");
      return dic;
    }
    else {
        xmlReader.setDevice(&xmlFile);

        xmlReader.setDevice(&xmlFile);
        while (xmlReader.readNextStartElement()) {
            if (xmlReader.name() == "atomemanager")
                dic = processAtomeManager(xmlReader);

            if (xmlReader.tokenType() == QXmlStreamReader::Invalid)
                xmlReader.readNext();

            if (xmlReader.hasError()) {
                xmlReader.raiseError();
                qDebug() << errorString(xmlReader);
            }
            xmlReader.skipCurrentElement();
        }
    }
    return dic;
}

QMap<QString, LTAtome*> XMLManager::processAtomeManager(QXmlStreamReader& xmlReader) {

    QMap<QString, LTAtome*> dictionnary;

    if (!xmlReader.isStartElement() || xmlReader.name() != "atomemanager")
        return dictionnary;

    QString value = "";
    QString nature = "";
    QString pointer = "";

        while (!xmlReader.atEnd()) {
            if (xmlReader.readNextStartElement()) {

                if (xmlReader.name() == "atome") {
                    value = "";
                    nature = "";
                    pointer = "";
                }
                else if (xmlReader.name() == "value")
                    value = readNextText(xmlReader);
                else if (xmlReader.name() == "nature")
                    nature = readNextText(xmlReader);
                else if (xmlReader.name() == "pointer")
                    pointer = readNextText(xmlReader);

                if (value != "" && nature != "") {

                    if (nature == "INDEFINI") {
                        LTAtome* a = new LTAtome(value, LTAtome::EnumFromString(nature));

                        dictionnary.insert(value, a);
                        value = "";
                        nature = "";
                        pointer = "";
                    }
                    else if (pointer != "") {
                        LTAtome* a = new LTAtome(value, LTAtome::EnumFromString(nature));

                        if (pointer != "") {
                            QList<Operande*> L = Parseur::NewListOperande(pointer);
                            Litterale* l = dynamic_cast<Litterale*>(L.at(0));
                            a->setPointer(l);
                        }

                        dictionnary.insert(value, a);
                        value = "";
                        nature = "";
                        pointer = "";
                    }
                }
            }
        }

        std::cout << dictionnary.size() << std::endl;

    return dictionnary;
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
