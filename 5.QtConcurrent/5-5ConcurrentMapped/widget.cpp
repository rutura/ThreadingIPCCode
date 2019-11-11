#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "GUI Thread : " << QThread::currentThread();
    //Populate list
    for(int i {0} ;  i < 30000 ; i++){
        list << i;
    }


    //Monitor work using QFutureWatcher

    connect(&futureWatcher, &QFutureWatcher<void>::started,[=](){

        qDebug() << "asynchronous : Work started.";

    });

    connect(&futureWatcher, &QFutureWatcher<void>::finished,[=](){

        qDebug() << "asynchronous : Work finished.";

        qDebug() << "Result count : " << future.resultCount();

        //qDebug() << future.results();

        for( int i{0} ; i < future.resultCount(); i ++){
            qDebug() << "Result " << i << " :" << future.resultAt(i);
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

int Widget::modify(const int &value)
{
    qDebug() << "Modifying " << value << " result : " << value * 10
             << " Thread :" << QThread::currentThread();
    return value * 10;
}

void Widget::on_modifyButton_clicked()
{

    /*
    std::function<int(const int &)> modify = [](const int & value){
        qDebug() << "Modifying " << value << " result : " << value * 10
                 << " Thread :" << QThread::currentThread();
        return value * 10;
    };

    */


    //Synchronous
    future = QtConcurrent::mapped(list,modify);

    future.waitForFinished();

    qDebug() << "asynchronous : Work finished.";

    qDebug() << "Result count : " << future.resultCount();

    //qDebug() << future.results();

    for( int i{0} ; i < future.resultCount(); i ++){
        qDebug() << "Result " << i << " :" << future.resultAt(i);
    }



    //futureWatcher.setFuture(future);
}

void Widget::on_seeValuesButton_clicked()
{
    qDebug() << "Original list " << list;
}
