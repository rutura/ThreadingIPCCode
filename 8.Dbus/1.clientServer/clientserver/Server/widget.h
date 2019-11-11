/*
 *
 *          This example shows how to use DBus to communicate between processes on linux
 *
 *              . DBus allows you to expose objects from one application, so that other applications
 *                (processes) can call methods on them.
 *
 *              . We will build two apps as part of one subdirs project
 *
 *              . one is the server, providing a service of a calculator.
 *                it can multiply and divide numbers
 *
 *              . We write our server object(slavecalculator), and put in the methods
 *                we want to be callable from other applications as public slots. There
 *                are many ways you can expose method, signals and properties , but we'll
 *                keep it simple in this demo.
 *
 *              . Once we have our object to expose ready, we have to make our intent, clear
 *                and say that it will be exposed as an interface other applications can
 *                consume.We do that with this line in the slavecalculator class
 *
 *                      Q_CLASSINFO("D-Bus Interface", "com.blikoon.CalculatorInterface")
 *
 *              . The reverse domain name formatted interface name will be seen by whatever
 *                application is interested in what our process has to offer.
 *
 *              . Four the code from our object to be exposed, we need to put together, an
 *                  adaptor and an interface.
 *                  . The adaptor will be used by the server process ( exposing features),
 *                    to take our features and expose them to the session dbus. When we
 *                     use the adaptor in code, see Server widget.cpp file, we have to
 *                     give it the pointer to the real object we are exposing
 *
 *
 *                  . The interface will be used in client code, to allow client apps , to
 *                    call code from the exposed object as if it is directly defined in the
 *                    client.
 *
 *              . Because adaptor and interface are fairly standard, Qt has tools to automate
 *                the process of generating them, so that app developers can just focus on the
 *                features they are exposing.
 *
 *                  . One such tool is /home/gakwaya/Qt5.12.3/5.12.3/gcc_64/bin/qdbuscpp2xml,
 *                    that we use to generate interface xml descriptor file. The command is something
 *                   like
 *
 *                      /home/gakwaya/Qt5.12.3/5.12.3/gcc_64/bin/qdbuscpp2xml -M -s calculator.h -o com.blikoon.Calculator.xml
 *
 *                    and you can invoke the tool with -h flag to see the documentation.
 *
 *
 *
 *                  . The other tool is /home/gakwaya/Qt5.12.3/5.12.3/gcc_64/bin/qdbusxml2cpp
 *                    and below are example usages to generate Adaptor and Interface
 *
 *                      //adaptor
                            qdbusxml2cpp -a test_adap mainwindow.xml

                        //interface
                            qdbusxml2cpp -p test_interface mainwindow.xml

                     you can also invoke the tool with -h flag to see the documentation


                   . We use the cpp2xmp version to get an xml interface descriptor file. ONce we have it,
                     we edit the node to make it have a name, the rest we leave as is

                   . Then we generate an adaptor, for use in the server part, see calculatoradaptor, and generate an interface, for
                      use in the client side, see calculatorinterface.


                   . In server widget.cpp file, instantiate your object and expose it as shown below

                         //Create actual calculator
                         slaveCalculator = new SlaveCalculator(this);


                        //Adaptor is used in the class exposing the service.
                        //You have to pass the object you want to expose to DBus in the parameter
                        //because methods will be called on it
                        new CalculatorInterfaceAdaptor(slaveCalculator);



                        QDBusConnection connection = QDBusConnection::sessionBus();//Gives us a handle to the session bus

                        //Here you pass in the object that you want expose to Dbus
                        connection.registerObject("/CalcServicePath", slaveCalculator);
                        //connection.registerService("com.example.CarExample");
                        connection.registerService("com.blikoon.CalculatorService");

 *
 *
 *


 *
 * */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "slavecalculator.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    SlaveCalculator * slaveCalculator;
};

#endif // WIDGET_H
