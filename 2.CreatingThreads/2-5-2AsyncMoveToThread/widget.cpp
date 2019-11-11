#include "widget.h"
#include "ui_widget.h"
#include "worker.h"
#include <QDebug>
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui thread : " << QThread::currentThread();

    thread = new QThread(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    Worker * worker = new Worker;

    worker->moveToThread(thread);

    connect(thread,&QThread::started,worker,&Worker::doWork);
    connect(thread,&QThread::finished,[](){
        qDebug() << "Thread finished";
    });
    connect(thread,&QThread::finished,worker,&Worker::deleteLater);

    thread->start();

}

void Widget::on_stopButton_clicked()
{
    thread->exit();
}

void Widget::on_infoButton_clicked()
{
    qDebug() << "Thread running : " << thread->isRunning();
}
