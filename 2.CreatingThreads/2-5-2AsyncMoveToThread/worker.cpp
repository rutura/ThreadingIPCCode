#include "worker.h"
#include <QTimer>
#include <QDebug>
#include <QThread>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker:: ~Worker(){
    qDebug() << "Worker destructor running in thread : " << QThread::currentThread();
}




void Worker::doWork()
{

    QTimer * timer = new QTimer();
    connect(timer,&QTimer::timeout,[](){
        qDebug() << "Time out . Running in thread : " << QThread::currentThread();
    });
    timer->setInterval(1000);
    timer->start();

}
