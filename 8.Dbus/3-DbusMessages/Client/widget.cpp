#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDBusConnection>
#include <QDBusMessage>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    bool
    connect(const QString &service, const QString &path, const QString &interface,
            const QString &name, QObject *receiver, const char *slot)

            */
    bool connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                                            "com.blikoon.CalculatorInterface","productResult","d",
                                                            this,SLOT(gotProduct(double)));
    qDebug() << "product signal connected : " << connected;

    connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                                       "com.blikoon.CalculatorInterface","divisionResult","d",
                                                       this,SLOT(gotQuotient(double)));
    qDebug() << "product signal connected : " << connected;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::gotProduct(double value)
{
    qDebug() << "Client got server signal for product : " << value;
}

void Widget::gotQuotient(double value)
{
    qDebug() << "Client got server signal for quotient : " << value;
}



void Widget::on_multiplyButton_clicked()
{
    /*
    QDBusMessage::createMethodCall(const QString &service,
            const QString &path,
            const QString &interface,
            const QString &method)
    */
    QDBusMessage m = QDBusMessage::createMethodCall("com.blikoon.CalculatorService",
                                                    "/CalcServicePath",
                                                    "com.blikoon.CalculatorInterface",
                                                    "multiply");
    //First way to pass arguments
    m << ui->number1SpinBox->value() << ui->number2SpinBox->value();
    /*
    //Second way to pass arguments
    QList<QVariant> args;

    args.append(ui->number1SpinBox->value());
    args.append((ui->number2SpinBox->value()));

    m.setArguments(args);
    */
    /*
    //Send doesn't give us response

    bool queued = QDBusConnection::sessionBus().send(m);
    qDebug() << "Message queued : " << queued;
    */
    //Call gives a response
    QDBusMessage response = QDBusConnection::sessionBus().call(m);

    if(response.type() == QDBusMessage::ReplyMessage){
        qDebug() << "Got a reply from the server" << response.arguments();
        if(response.arguments().count() ==1){
            ui->resultLineEdit->setText(QString::number(response.arguments()[0].toInt()));
        }
    }
}

void Widget::on_divideButton_clicked()
{

    QDBusMessage m = QDBusMessage::createMethodCall("com.blikoon.CalculatorService",
                                                    "/CalcServicePath",
                                                    "com.blikoon.CalculatorInterface",
                                                    "divide");
    m << ui->number1SpinBox->value() << ui->number2SpinBox->value();

    QDBusMessage response = QDBusConnection::sessionBus().call(m);

    if(response.type() == QDBusMessage::ReplyMessage){
        qDebug() << "Got a reply from the server" << response.arguments();
        if(response.arguments().count() ==1){
            ui->resultLineEdit->setText(QString::number(response.arguments()[0].toInt()));
        }

    }
}

void Widget::on_messageToServerButton_clicked()
{
    QDBusMessage msg = QDBusMessage::createSignal("/CalcServicePath",
                                                  "com.blikoon.CalculatorInterface",
                                                  "message");
    msg << "Hello there";
    QDBusConnection::sessionBus().send(msg);
}
