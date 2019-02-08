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

class Xmlmanager
{
public:
    Xmlmanager();
    std::tuple<QString,QString, QString> readNewOrder();
    QString writeOrderStatusXml(QString orderStatus);
    QString writeLoginXml(QString orderStatus);
    void loadXmls();

private:
    QDomDocument newOrderXML;
    QDomDocument findOrderXML;
    QDomDocument LoginXML;
};

#endif // XMLMANAGER_H
