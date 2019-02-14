#include "xmlmanager.h"

Xmlmanager::Xmlmanager()
{
}


QString Xmlmanager::makeFiles(QString fileName, QString message)
{
    QTemporaryFile randomName;
    randomName.open();
    QString pathName = randomName.fileName();
    qDebug() << pathName;
    pathName.append(".xml");

    if (fileName == "order")
    {
        QFile newOrderFile(pathName);
        if (!newOrderFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&newOrderFile);
            stream << message;
            newOrderFile.close();
        }
        newOrderXML.setContent(&newOrderFile);
        return newOrderFile.fileName();
    }

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
    if (fileName == "login")
    {
        QFile LoginFile(pathName);
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
        return LoginFile.fileName();
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
    if (fileName == "newOrderStatus")
    {

        QFile newOrderStatusXMLFile(pathName);
        if (!newOrderStatusXMLFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writting";
        }
        else
        {
            QTextStream stream(&newOrderStatusXMLFile);
            stream << message;
            newOrderStatusXMLFile.close();
        }
        newOrderStatusXML.setContent(&newOrderStatusXMLFile);
        return newOrderStatusXMLFile.fileName();
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


QString Xmlmanager::writeOrderStatusXml(QString orderStatus)
{
    QDomDocument document;
    QDomElement root = document.createElement("FoundedOrder");


    QDomElement order = document.createElement("Order");
    QDomElement action = document.createElement("Action");
    QDomElement status = document.createElement("Status");

    QString actiontxt = "findOrder";

    QDomText actionData = document.createTextNode(actiontxt);
    QDomText statustxt = document.createTextNode(orderStatus);

    action.appendChild(actionData);
    status.appendChild(statustxt);
    order.appendChild(action);
    order.appendChild(status);
    root.appendChild(order);
    document.appendChild(root);

    QString message = document.toString();
    return message;
}

QString Xmlmanager::writeOrdersXml(QSqlQuery query)
{
    QDomDocument document;
    QDomElement root = document.createElement("Orders");


    while(query.next())
    {

        QDomElement order = document.createElement("Order");
        QDomElement idorder = document.createElement("IdOrder");
        QDomElement phone = document.createElement("Phone");
        QDomElement repair = document.createElement("Repair");
        QDomElement date = document.createElement("Date");
        QDomElement status = document.createElement("Status");
        QDomElement action = document.createElement("Action");

        QString idordertxt = query.value(3).toString();
        QString phonetxt = query.value(1).toString();
        QString repairtxt = query.value(2).toString();
        QString datetxt = query.value(4).toString();
        QString statustxt = query.value(0).toString();
        QString actiontxt = "orders";

        QDomText idorderData = document.createTextNode(idordertxt);
        QDomText phoneData = document.createTextNode(phonetxt);
        QDomText repairData = document.createTextNode(repairtxt);
        QDomText dateData = document.createTextNode(datetxt);
        QDomText statusData = document.createTextNode(statustxt);
        QDomText actionData = document.createTextNode(actiontxt);

        //------- añadimos ------//
        order.appendChild(action);
        order.appendChild(idorder);
        order.appendChild(phone);
        order.appendChild(repair);
        order.appendChild(date);
        order.appendChild(status);
        action.appendChild(actionData);
        idorder.appendChild(idorderData);
        phone.appendChild(phoneData);
        repair.appendChild(repairData);
        date.appendChild(dateData);
        status.appendChild(statusData);
        root.appendChild(order);
    }

    document.appendChild(root);

    QString message = document.toString();
    return message;
}

QString Xmlmanager::writeLoginXml(QString logininfo)
{
    QDomDocument document;
    QDomElement root = document.createElement("LoginInfo");


    QDomElement login = document.createElement("Login");
    QDomElement action = document.createElement("Action");
    QDomElement user = document.createElement("Username");

    QDomText actionData = document.createTextNode("login");
    QDomText logintxt = document.createTextNode(logininfo);

    user.appendChild(logintxt);
    action.appendChild(actionData);
    login.appendChild(action);
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
    return std::make_tuple(phone, repair, idorder);
}

QString Xmlmanager::readFindOrder()
{
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

std::tuple<QString, QString> Xmlmanager::readNewOrderStatus(QString xml)
{
    QXmlStreamReader xmlmessage(xml);
    QString idorder{""};
    QString status{""};

       while (!xmlmessage.atEnd())
       {
            xmlmessage.readNextStartElement();
            if(xmlmessage.name() == "IdOrder")
            {
                idorder = xmlmessage.readElementText();
            }
            if(xmlmessage.name() == "Status")
            {
                status = xmlmessage.readElementText();
            }
       }

         return std::make_tuple(idorder, status);
}
