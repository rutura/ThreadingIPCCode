#include "widget.h"
#include "ui_widget.h"
#include "calculatoradaptor.h"

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
}

Widget::~Widget()
{
    delete ui;
}




