#include "xmlmanager.h"

Xmlmanager::Xmlmanager()
{

}


std::tuple<QString,QString> Xmlmanager::writeXML()
{
   return std::make_tuple("Lisa Simpson","sda");
}


QString Xmlmanager::writeOrderStatusXml(QString orderStatus)
{
    QDomDocument document;
    QDomElement root = document.createElement("OrderStatus");


    QDomElement status = document.createElement("Status");

    QDomText statustxt = document.createTextNode(orderStatus);


    status.appendChild(statustxt);
    root.appendChild(status);
    document.appendChild(root);

    QString message = document.toString();
    return message;
}
