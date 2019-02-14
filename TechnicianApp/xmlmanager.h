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

class Xmlmanager
{
public:
    Xmlmanager();
    std::tuple<QString,QString, QString> readNewOrder();
    QString readFindOrder();
    std::tuple<QString, QString> readLogin();
    std::tuple<QString, QString, QString> readOrders();
    QString writeOrderStatusXml(QString orderStatus);
    QString writeLoginXml(QString orderStatus);
    void loadXmls();
    bool validatexml(QString xml, QString xsd);
    QString makeFiles(QString fileName, QString message);
    QString writeRequestOrdersXml();
    QString xmlMessage(QString xml);
    std::tuple<std::vector<QString>, std::vector<QString>, std::vector<QString>, std::vector<QString>, std::vector<QString>> readOrdersXML(QString xml);
    QString writeNewOrderStatus(QString idorder, QString newStatus);
    QString writeUpdateStatusXml(QString idorder, QString newStatus);


private:
    QDomDocument OrdersXML;
    QDomDocument findOrderXML;
    QDomDocument LoginXML;
};

#endif // XMLMANAGER_H
