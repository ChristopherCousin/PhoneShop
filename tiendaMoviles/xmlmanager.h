#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <iostream>
#include <QString>
#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>
#include <QtXml>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlSchema>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXmlPatterns/QXmlSchemaValidator>
#include <QTemporaryFile>
#include <QXmlStreamReader>
#include <QDir>

class Xmlmanager
{
public:
    Xmlmanager();
    QString xmlMessage(QString xml);
    QString makeFiles(QString fileName, QString message);
};


#endif // XMLMANAGER_H
