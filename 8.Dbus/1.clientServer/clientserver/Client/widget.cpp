#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    calculatorHandle = new com::blikoon::CalculatorInterface("com.blikoon.CalculatorService",
                                                             "/CalcServicePath",
                                                             QDBusConnection::sessionBus());
}

Widget::~Widget()
{
    delete ui;
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
