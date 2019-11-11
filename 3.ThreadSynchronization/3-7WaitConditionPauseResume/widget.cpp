#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui thread : " << QThread::currentThread();

    workerThread = new WorkerThread(this);
    connect(workerThread,&WorkerThread::currentCount,this,&Widget::currentCount);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    workerThread->start();
}

void Widget::on_pauseButton_clicked()
{
    workerThread->pause();
}

void Widget::on_resumeButton_clicked()
{
    workerThread->resume();
}

void Widget::currentCount(int value)
{
    ui->progressBar->setValue(value);
}
