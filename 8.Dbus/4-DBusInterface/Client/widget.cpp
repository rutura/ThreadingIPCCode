#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Look at the signature in the docs
    
    interface = new QDBusInterface("com.blikoon.CalculatorService",
                                                   "/CalcServicePath",
                                                   "com.blikoon.CalculatorInterface");
    interface->setParent(this);//For memory management

    //Connect to signal from server process
    connect(interface,SIGNAL(productResult(double)),this,SLOT(gotProduct(double)));




    /*
    bool connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                                            "com.blikoon.CalculatorInterface","productResult","d",
                                                            this,SLOT(gotProduct(double)));
    qDebug() << "product signal connected : " << connected;
    
    connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                                       "com.blikoon.CalculatorInterface","divisionResult","d",
                                                       this,SLOT(gotQuotient(double)));
    qDebug() << "product signal connected : " << connected;
    */
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::gotProduct(double value)
{
    qDebug() << "Client got server signal for product : " << value;
    ui->resultLineEdit->setText(QString::number(value));
}

void Widget::gotQuotient(double value)
{
    qDebug() << "Client got server signal for quotient : " << value;
}



void Widget::on_multiplyButton_clicked()
{
    /*
//    QDBusInterface *interface = new QDBusInterface("com.blikoon.CalculatorService",
//                                                   "/CalcServicePath",
//                                                   "com.blikoon.CalculatorInterface");


    if(interface->isValid()){
        qDebug() << "Interface is valid";
    }else{
        qDebug() << "Interface is not valid , getting out";
        return;


    }

  */

    QList<QVariant> args;

    args.append(ui->number1SpinBox->value());
    args.append((ui->number2SpinBox->value()));

    /*
    //Can pas up to 8 parameters this way
    //QDBusReply<double> reply = interface->call("multiply",ui->number1SpinBox->value(),
      //                                         ui->number2SpinBox->value());

    //Can use an arg list if we want
    QDBusReply<double> reply = interface->callWithArgumentList(QDBus::Block,"multiply",args);

    if(reply.isValid()){
        ui->resultLineEdit->setText(QString::number(reply.value()));
        qDebug() << "Got a valid reply for multiplication : " << reply.value();
    }
    */

    //Can call asynchronously, a slot. This can conflict with the connection we do
    //in the constructor, make sure you only use one or the other
    interface->callWithCallback("multiply",args,this,SLOT(gotProduct(double)));

    /*
    //This uses the connection in the constructor to fire the operation in server
    //interface->call("multiply",ui->number1SpinBox->value(),ui->number2SpinBox->value());
    */
}

void Widget::on_divideButton_clicked()
{



    if(interface->isValid()){
        qDebug() << "Interface is valid";
    }else{
        qDebug() << "Interface is not valid , getting out";
        return;
    }

    QDBusReply<double> reply = interface->call("divide",ui->number1SpinBox->value(),ui->number2SpinBox->value());

    if(reply.isValid()){
        ui->resultLineEdit->setText(QString::number(reply.value()));
        qDebug() << "Got a valid reply for division : " << reply.value();
    }
}
