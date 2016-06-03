#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "operande.h"
#include "ltatome.h"
#include <QtXml>
#include <iostream>
#include <QFile>
/*!
 * \brief Gère l'écriture et la lecture des données dans un fichier XML
 */
class XMLManager
{
    static XMLManager* instance;
    XMLManager() {}
    ~XMLManager() {}
    XMLManager(const XMLManager& c);

public :
    /*!
     * \brief getInstance
     * \return Une instance de XMLManager
     */
    static XMLManager& getInstance() {
        if (!instance) instance = new XMLManager();
        return *instance;
    }
    /*!
     * \brief Libère l'instance
     */
    static void freeInstance() { if (instance) delete instance; }

    /*!
     * \brief Sauvegarde la pile dans un fichier XML
     */
    void saveXMLFileStack();

    /*!
     * \brief Sauvegarde les paramètres dans un fichier XML
     */
    void saveXMLFileSettings();

    /*!
     * \brief Lit les données de la pile à partir du fichier XML
     * \return
     */
    QList<Operande *> readXMLFileStack();

    /*!
     * \brief Lit les paramètres de la pile à partir du fichier XML
     * \return
     */
    bool readXMLFileSettings();

    /*!
     * \brief Sauvegarde le tableau associatif contenant les atomes et les littérales associés dans un fichier XML
     */
    void saveXMLFileAtomeManager();

    /*!
     * \brief Lit le tableau associatif contenant les atomes et les littérales associés à partir d'un fichier XML
     * \return
     */
    QMap<QString, LTAtome*> readXMLFileAtomeManager();


private:
    QList<Operande*> processStack(QXmlStreamReader& xmlReader);
    bool processSettings(QXmlStreamReader& xmlReader);
    QMap<QString, LTAtome*> processAtomeManager(QXmlStreamReader& xmlReader);

    QString readNextText(QXmlStreamReader& xmlReader);
    QString errorString(QXmlStreamReader& xmlReader);

    QString _filename;

};

#endif // XMLMANAGER_H
