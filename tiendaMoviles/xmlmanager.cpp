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
}
