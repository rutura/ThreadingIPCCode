#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>
#include <QtConcurrent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "GUI Thread : " << QThread::currentThread();
    //Populate list
    for( int i {0} ;  i < 10000 ; i++){
        list << i;
    }


    qDebug() << "Original value : " << list.last();

    connect(&futureWatcher, &QFutureWatcher<void>::started,[=](){
        qDebug() << "asynchronous : Work started.";
    });

    connect(&futureWatcher, &QFutureWatcher<void>::finished,[=](){
        qDebug() << "asynchronous : Work done.";
    });

    connect(&futureWatcher, &QFutureWatcher<void>::progressValueChanged,[=](int value){
        qDebug() << "Progress : " << value;
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::modify(int &value)
{
    qDebug() << "Modifying " << value << " result : " << value * 10
             << " Thread :" << QThread::currentThread();
    value = value * 10;
}

void Widget::on_modifyButton_clicked()
{

    /*
    //Lambda function
    auto modify = [](int &value){
            qDebug() << "Modifying " << value << " result : " << value * 10
                     << " Thread :" << QThread::currentThread();
            value = value * 10;
        };
    */

    future = QtConcurrent::map(list,modify);

    futureWatcher.setFuture(future);
}

void Widget::on_seeValuesButton_clicked()
{
    qDebug() << "Modified value : " << list.last();
}
