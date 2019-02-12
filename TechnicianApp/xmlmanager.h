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

class Xmlmanager
{
public:
    Xmlmanager();
    std::tuple<QString,QString, QString> readNewOrder();
    QString readFindOrder();
    std::tuple<QString, QString> readLogin();
    QString writeOrderStatusXml(QString orderStatus);
    QString writeLoginXml(QString orderStatus);
    void loadXmls();
    bool validatexml(QString xml, QString xsd);
    void makeFiles(QString fileName, QString message);
    QString writeRequestOrdersXml();


private:
    QDomDocument OrdersXML;
    QDomDocument findOrderXML;
    QDomDocument LoginXML;
};

#endif // XMLMANAGER_H
