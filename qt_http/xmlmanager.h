#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <iostream>
#include <QString>
#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>
#include <QtXml>

class Xmlmanager
{
public:
    Xmlmanager();
    std::tuple<QString,QString> writeXML();
    QString writeOrderStatusXml(QString orderStatus);
};

#endif // XMLMANAGER_H
