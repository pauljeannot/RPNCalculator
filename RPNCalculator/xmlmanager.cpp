#include "xmlmanager.h"
#include "controller.h"
#include <QXmlStreamAttribute>
#include <QXmlStreamWriter>
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

XMLManager* XMLManager::instance = 0;

void XMLManager::saveXMLFile()
{

    QXmlStreamWriter* xml = new QXmlStreamWriter();
    QXmlStreamWriter& xmlWriter = *xml;
    QFile file("/Users/gum/Desktop/output.xml");

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
            (*j)->write(xmlWriter);
        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();
    }
}


void XMLManager::readXMLFile() {

}


void XMLManager::read() {

    QFile xmlFile("/Users/gum/Desktop/output.xml");
    xmlFile.open(QIODevice::ReadOnly);
    xml.setDevice(&xmlFile);

    if (xml.readNextStartElement() && xml.name() == "stack")
       processRates();

    // readNextStartElement() leaves the stream in
    // an invalid state at the end. A single readNext()
    // will advance us to EndDocument.
    if (xml.tokenType() == QXmlStreamReader::Invalid)
        xml.readNext();

    if (xml.hasError()) {
        xml.raiseError();
        qDebug() << errorString();
    }
}

void XMLManager::processRates() {
    if (!xml.isStartElement() || xml.name() != "stack")
        return;
    while (xml.readNextStartElement()) {
        if (xml.name() == "item")
            processRate();
        else if (xml.name() == "nombre")
            processNombre();
        else
            xml.skipCurrentElement();
    }
}

void XMLManager::processRate() {
    if (!xml.isStartElement() || xml.name() != "item")
        return;

    QString from;
    QString to;
    QString conversion;
    while (xml.readNextStartElement()) {
        if (xml.name() == "from")
            from = readNextText();
        else if (xml.name() == "to")
            to = readNextText();
        else if (xml.name() == "conversion")
            conversion = readNextText();
        xml.skipCurrentElement();
    }

    if (!(from.isEmpty() || to.isEmpty() || conversion.isEmpty())) {

        std::cout << from.toStdString() << std::endl;
        std::cout << to.toStdString() << std::endl;
        std::cout << conversion.toStdString() << std::endl;
    }
}

void XMLManager::processNombre() {
    if (!xml.isStartElement() || xml.name() != "nombre")
        return;

    QString from;
    QString to;
    QString conversion;
    while (xml.readNextStartElement()) {
        if (xml.name() == "from")
            from = readNextText();
        else if (xml.name() == "to")
            to = readNextText();
        else if (xml.name() == "conversion")
            conversion = readNextText();
        xml.skipCurrentElement();
    }

    if (!(from.isEmpty() || to.isEmpty() || conversion.isEmpty())) {

        std::cout << "nombre " <<  from.toStdString() << std::endl;
        std::cout << "nombre " << to.toStdString() << std::endl;
        std::cout << "nombre " << conversion.toStdString() << std::endl;
    }
}


QString XMLManager::readNextText() {
    xml.readNext();
    return xml.text().toString();
}

QString XMLManager::errorString() {
    return QObject::tr("%1\nLine %2, column %3")
            .arg(xml.errorString())
            .arg(xml.lineNumber())
            .arg(xml.columnNumber());
}
