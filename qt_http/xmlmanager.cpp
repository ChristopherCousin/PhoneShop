#include "xmlmanager.h"

Xmlmanager::Xmlmanager()
{

}


void Xmlmanager::loadXmls()
{
    QFile f("newOrder.xml");
    if (!f.open(QIODevice::ReadOnly))
    {
        // Error
        std::cerr << "Error while loading file" << std::endl;
    }

    newOrderXML.setContent(&f);

    f.close();

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

std::tuple<QString, QString, QString> Xmlmanager::readNewOrder()
{
    QDomElement root = newOrderXML.documentElement();
    QDomElement Component = root.firstChild().toElement();
    QString idorder;
    QString repair;
    QString phone;
    while (!Component.isNull())
    {
        if (Component.tagName() == "Order")
        {
            QDomElement Child = Component.firstChild().toElement();

            while (!Child.isNull())
            {
                if (Child.tagName() == "IdOrder")
                    idorder = Child.firstChild().toText().data();
                if (Child.tagName() == "repair")
                    repair = Child.firstChild().toText().data();
                if (Child.tagName() == "Phone")
                    phone = Child.firstChild().toText().data();

                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();
    }
    qDebug() << phone <<repair <<idorder;
    return std::make_tuple(phone,repair,idorder);
}
