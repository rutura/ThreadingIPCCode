#include "widget.h"
#include "ui_widget.h"
#include "calculatoradaptor.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Create actual calculator
    slaveCalculator = new SlaveCalculator(this);


    //Adaptor is used in the class exposing the service.
    //You have to pass the object you want to expose to DBus in the parameter
    //because methods will be called on it
    new CalculatorInterfaceAdaptor(slaveCalculator);



    QDBusConnection connection = QDBusConnection::sessionBus();

    //Here you pass in the object that you want expose to Dbus. Take note of this info, it is used in client.
    connection.registerObject("/CalcServicePath", slaveCalculator);

    //Here you pass in the service name. Take note of this as it is also needed for clients to reach our exposed object.
    connection.registerService("com.blikoon.CalculatorService");

    QDBusConnection::sessionBus().connect(QString(), QString(),
                                          "com.blikoon.CalculatorInterface",
                                          "message", this, SLOT(messageSlot(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::messageSlot(QString message)
{
    qDebug() << "Server got signal from client, parameter : " << message;
}




