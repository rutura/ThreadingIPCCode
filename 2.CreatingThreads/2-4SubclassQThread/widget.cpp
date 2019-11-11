#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui thread : " << QThread::currentThread();

    workerThread = new WorkerThread(this);
    connect(workerThread,&WorkerThread::currentCount,this,&Widget::currentCount);

    connect(workerThread,&QThread::started,[](){
        qDebug() << "Thread started";
    });

    connect(workerThread,&QThread::finished,[](){
        qDebug() << "Thread finished";
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    workerThread->start();
}

void Widget::on_infoButton_clicked()
{
    qDebug() << "Thread  is running : " << workerThread->isRunning();
}

void  Widget::currentCount(int value){

    ui->progressBar->setValue(value);
    ui->infoLabel->setText(QString::number(value));

}
