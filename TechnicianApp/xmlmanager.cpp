#include "xmlmanager.h"

Xmlmanager::Xmlmanager()
{

}


QString Xmlmanager::makeFiles(QString fileName, QString message)
{
    QTemporaryFile randomName;
    randomName.open();
    QString pathName = randomName.fileName();
    pathName.append(".xml");


    if (fileName == "find")
    {
        QFile findOrderFile(pathName);
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
        return findOrderFile.fileName();
    }
    if (fileName == "orders")
    {

        QFile OrdersXMLFile(pathName);
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
        return OrdersXMLFile.fileName();
    }

    if (fileName == "validate")
    {
        QFile file(pathName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&file);
            stream << message;
            file.close();
        }
        return file.fileName();
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


    QDomElement order = document.createElement("Order");
    QDomElement action = document.createElement("Action");
    QDomElement messag = document.createElement("Message");
    QString messageorder = "Resquest Orders";
    QString actiontxt = "orders";
    QDomText actionData = document.createTextNode(actiontxt);
    QDomText logintxt = document.createTextNode(messageorder);

    action.appendChild(actionData);
    messag.appendChild(logintxt);
    order.appendChild(action);
    order.appendChild(messag);
    root.appendChild(order);
    document.appendChild(root);

    QString message = document.toString();
    return message;
}

QString Xmlmanager::writeNewOrderStatus(QString idorder, QString newStatus)
{
    QDomDocument document;
    QDomElement root = document.createElement("Orders");


    QDomElement order = document.createElement("Order");
    QDomElement action2 = document.createElement("Action");
    QDomElement action = document.createElement("IdOrder");
    QDomElement messag = document.createElement("Status");
    QString action2txt = "newOrderStatus";
    QString messageorder = newStatus;
    QString actiontxt = idorder;
    QDomText action2Data = document.createTextNode(action2txt);
    QDomText actionData = document.createTextNode(actiontxt);
    QDomText logintxt = document.createTextNode(messageorder);


    action.appendChild(actionData);
    action2.appendChild(action2Data);
    messag.appendChild(logintxt);
    order.appendChild(action2);
    order.appendChild(action);
    order.appendChild(messag);
    root.appendChild(order);
    document.appendChild(root);

    QString message = document.toString();
    return message;
}


QString Xmlmanager::xmlMessage(QString xml)
{
    QXmlStreamReader xmlmessage(xml);
    QString message{""};

       while (!xmlmessage.atEnd())
       {
            xmlmessage.readNextStartElement();
            if(xmlmessage.name() == "Action")
            {
                message = xmlmessage.readElementText();
            }
       }

        return message;
}

std::tuple<std::vector<QString>, std::vector<QString>, std::vector<QString>, std::vector<QString>, std::vector<QString>> Xmlmanager::readOrdersXML(QString xml)
{

    QXmlStreamReader xmlmessage(xml);
    std::vector<QString> idorder;
    std::vector<QString> phone;
    std::vector<QString> repair;
    std::vector<QString> date;
    std::vector<QString> status;

       while (!xmlmessage.atEnd())
       {
            xmlmessage.readNextStartElement();
            if(xmlmessage.name() == "IdOrder")
            {
                idorder.push_back(xmlmessage.readElementText());
            }
            if(xmlmessage.name() == "Phone")
            {
                phone.push_back(xmlmessage.readElementText());
            }
            if(xmlmessage.name() == "Repair")
            {
                repair.push_back(xmlmessage.readElementText());
            }
            if(xmlmessage.name() == "Date")
            {
                date.push_back(xmlmessage.readElementText());
            }
            if(xmlmessage.name() == "Status")
            {
                status.push_back(xmlmessage.readElementText());
            }
       }

        return std::make_tuple(idorder, phone, repair, date, status);
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
