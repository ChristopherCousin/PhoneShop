#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadXML()
{
    // Cargar el XML como RAW Data
    QFile f("AvailablePhones.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error
        std::cerr << "Error while loading file" << std::endl;
    }

    // Ponemos la data dentro del QDomDocument antes de procesarlo
    xmlBOM.setContent(&f);
    f.close();


}

void MainWindow::readXML()
{
    // Extraemos el root markup
    QDomElement root = xmlBOM.documentElement();

    // COgemos el primer hijo del root
    QDomElement Component = root.firstChild().toElement();


    // Loop mientras haya un hijo
    while(!Component.isNull())
    {

        // Si el tag del nombre del hijo es PHONE
        if (Component.tagName() == "Phone")
        {

            // Cogemos el primer hijo de phone
            QDomElement Child = Component.firstChild().toElement();

            QString Name;

            // leemos cada hijo del componente nodo
            while (!Child.isNull())
            {

                // leemos el nombre
                if (Child.tagName()=="Name") Name = Child.firstChild().toText().data();

                // siguiente hijo
                Child = Child.nextSibling().toElement();
            }

            // ponemos en el comboBox los moviles disponibles
            ui->comboBox->addItem(Name.toStdString().c_str());

        }


        // Siguiente componente
        Component = Component.nextSibling().toElement();
    }

}


void MainWindow::on_pushButton_clicked()
{
    loadXML();
    readXML();


    web.onConnected();
    web.onTextMessageReceived("asd");
}
