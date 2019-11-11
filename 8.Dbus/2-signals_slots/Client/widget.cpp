#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    calculatorHandle = new com::blikoon::CalculatorInterface("com.blikoon.CalculatorService","/CalcServicePath",
                                                             QDBusConnection::sessionBus());

    /*
    bool
    connect(const QString &service, const QString &path, const QString &interface,
            const QString &name, QObject *receiver, const char *slot)

            */
    bool connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                                            "com.blikoon.CalculatorInterface",
                                                            "productResult","d",
                                                            this,SLOT(gotProduct(double)));
    qDebug() << "product signal connected : " << connected;

    connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                                       "com.blikoon.CalculatorInterface",
                                                       "divisionResult","d",
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
    if(calculatorHandle->isValid()){
        double result = calculatorHandle->multiply(ui->number1SpinBox->value(),ui->number2SpinBox->value());
        ui->resultLineEdit->setText(QString::number(result));
    }else{
        qCritical() << "Calculator Interface is not valid";
    }

}

void Widget::on_divideButton_clicked()
{
    if(calculatorHandle->isValid()){
        double result = calculatorHandle->divide(ui->number1SpinBox->value(),ui->number2SpinBox->value());
        ui->resultLineEdit->setText(QString::number(result));
    }else{
        qCritical() << "Calculator Interface is not valid";
    }
}
