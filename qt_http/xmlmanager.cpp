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
    QDomElement root = document.createElement("FoundedOrder");


    QDomElement order = document.createElement("Order");
    QDomElement status = document.createElement("Status");

    QDomText statustxt = document.createTextNode(orderStatus);


    status.appendChild(statustxt);
    order.appendChild(status);
    root.appendChild(order);
    document.appendChild(root);

    QString message = document.toString();
    return message;
}

QString Xmlmanager::writeLoginXml(QString logininfo)
{
    QDomDocument document;
    QDomElement root = document.createElement("LoginInfo");


    QDomElement login = document.createElement("Login");
    QDomElement user = document.createElement("Username");

    QDomText logintxt = document.createTextNode(logininfo);

    user.appendChild(logintxt);
    login.appendChild(user);
    root.appendChild(login);
    document.appendChild(root);

    QString message = document.toString();
    return message;
}
