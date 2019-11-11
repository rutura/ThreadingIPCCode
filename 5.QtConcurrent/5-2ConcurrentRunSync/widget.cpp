#include "widget.h"
#include "ui_widget.h"
#include <QtConcurrent>
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread : " << QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::heavyWork()
{

    qDebug() << "Heavy work running in thread : " << QThread::currentThread();
    for(int i{0} ; i < 1000000001 ; i++){

        if((i%100000) == 0){

            double percentage = ((i/1000000000.0)) * 100;
                       qDebug() << "Percentage : " << QVariant::fromValue(percentage).toInt()
                                << " | Thread : " << QThread::currentThread();
        }
    }
}

void Widget::on_startButton_clicked()
{
   future = QtConcurrent::run(heavyWork);

   future.waitForFinished();

   qDebug() << "Computation done!";
}

void Widget::on_cancelButton_clicked()
{
    future.cancel();
}

void Widget::on_pauseButton_clicked()
{
    future.pause();
}

void Widget::on_resumeButton_clicked()
{
    future.resume();
}
