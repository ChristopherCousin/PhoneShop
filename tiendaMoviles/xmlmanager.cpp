#include "xmlmanager.h"

Xmlmanager::Xmlmanager()
{

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

       //Esto es una guarreria pero no tengo tiempo..
       if(message == "")
       {
           message = xml;
       }
        return message;
}

std::tuple<QString, QString> Xmlmanager::readOrdersXML(QString xml)
{

    QXmlStreamReader xmlmessage(xml);
    QString idorder;
    QString status;


       while (!xmlmessage.atEnd())
       {
            xmlmessage.readNextStartElement();
            if(xmlmessage.name() == "IdOrder")
            {
                idorder.push_back(xmlmessage.readElementText());
            }
            if(xmlmessage.name() == "Status")
            {
                status.push_back(xmlmessage.readElementText());
            }
       }

        return std::make_tuple(idorder, status);
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
        return findOrderFile.fileName();
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
        return newOrderStatusXMLFile.fileName();
    }
}
