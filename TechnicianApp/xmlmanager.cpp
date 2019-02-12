#include "xmlmanager.h"

Xmlmanager::Xmlmanager()
{
}


void Xmlmanager::makeFiles(QString fileName, QString message)
{
    if (fileName == "orders")
    {
        QFile OrdersXMLFile("OrdersXML.xml");
        if (!OrdersXMLFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&OrdersXMLFile);
            stream << message;
            OrdersXMLFile.close();
        }
        OrdersXML.setContent(&OrdersXMLFile);
    }
    if (fileName == "find")
    {
        QFile findOrderFile("findOrder.xml");
        if (!findOrderFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&findOrderFile);
            stream << message;
            findOrderFile.close();
        }
        findOrderXML.setContent(&findOrderFile);
    }
    if (fileName == "login")
    {
        QFile LoginFile("Login.xml");
        if (!LoginFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&LoginFile);
            stream << message;
            LoginFile.close();
        }
        LoginXML.setContent(&LoginFile);
    }
}

void Xmlmanager::loadXmls()
{
    QFile OrdersXMLFile("OrdersXML.xml");
    if (!OrdersXMLFile.open(QIODevice::ReadOnly))
    {
        // Error
        std::cerr << "Error while loading file" << std::endl;
    }

    OrdersXML.setContent(&OrdersXMLFile);
    OrdersXMLFile.close();


    QFile findOrderFile("findOrder.xml");
    if (!findOrderFile.open(QIODevice::ReadOnly))
    {
        // Error
        std::cerr << "Error while loading file" << std::endl;
    }
    findOrderXML.setContent(&findOrderFile);
    findOrderFile.close();


    QFile LoginFile("Login.xml");
    if (!LoginFile.open(QIODevice::ReadOnly))
    {
        // Error
        std::cerr << "Error while loading file" << std::endl;
    }

    LoginXML.setContent(&LoginFile);
    LoginFile.close();
}

QString Xmlmanager::writeRequestOrdersXml()
{
    QDomDocument document;
    QDomElement root = document.createElement("Orders");


    QDomElement login = document.createElement("Order");
    QDomElement user = document.createElement("Message");
    QString messageorder = "Resquest Orders";
    QDomText logintxt = document.createTextNode(messageorder);

    user.appendChild(logintxt);
    login.appendChild(user);
    root.appendChild(login);
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

std::tuple<QString, QString, QString> Xmlmanager::readOrders()
{
    loadXmls();
    QDomElement root = OrdersXML.documentElement();
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
    return std::make_tuple(phone, repair, idorder);
}

QString Xmlmanager::readFindOrder()
{
    loadXmls();
    QDomElement root = findOrderXML.documentElement();
    QDomElement Component = root.firstChild().toElement();
    QString idorder{ "" };
    while (!Component.isNull())
    {
        if (Component.tagName() == "Order")
        {
            QDomElement Child = Component.firstChild().toElement();

            while (!Child.isNull())
            {
                if (Child.tagName() == "IdOrder")
                    idorder = Child.firstChild().toText().data();

                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();
    }

    return idorder;
}

std::tuple<QString, QString> Xmlmanager::readLogin()
{
    loadXmls();
    QDomElement root = LoginXML.documentElement();
    QDomElement Component = root.firstChild().toElement();
    QString username;
    QString password;
    while (!Component.isNull())
    {
        if (Component.tagName() == "Login")
        {
            QDomElement Child = Component.firstChild().toElement();

            while (!Child.isNull())
            {
                if (Child.tagName() == "Username")
                    username = Child.firstChild().toText().data();
                if (Child.tagName() == "Password")
                    password = Child.firstChild().toText().data();

                Child = Child.nextSibling().toElement();
            }
        }
        Component = Component.nextSibling().toElement();
    }

    return std::make_tuple(username, password);
}


bool Xmlmanager::validatexml(QString xml, QString xsd)
{
    QFile file(xsd);
    file.open(QIODevice::ReadOnly);

    QXmlSchema schema;
    schema.load(&file, QUrl::fromLocalFile(file.fileName()));

    if (schema.isValid())
    {
        QFile file2(xml);
        file2.open(QIODevice::ReadOnly);

        QXmlSchemaValidator validator(schema);
        if (validator.validate(&file2, QUrl::fromLocalFile(file2.fileName())))
        {
            qDebug() << "instance document is valid";
            return true;
        }
        else
        {
            qDebug() << "instance document is invalid";
            return false;
        }
    }
    else
    {
        qDebug() << "schema is invalid";
    }
}
