#include "workerthread.h"
#include <QTimer>
#include <QDebug>

WorkerThread::WorkerThread(QObject *parent) : QThread(parent)
{
    qDebug () << "Worker thread constructor running in thread : " << QThread::currentThread();

}

WorkerThread::~ WorkerThread() {
    qDebug () << "Worker thread destructor running in thread : " << QThread::currentThread();

}

void WorkerThread:: run() {

    qDebug () << "Workerthread run method running in thread : " << QThread::currentThread();


    QTimer * timer = new QTimer();
    connect(timer,&QTimer::timeout,[](){
        qDebug() << "Time out . Running in thread : " << QThread::currentThread();
    });
    timer->setInterval(1000);
    timer->start();

    exec();

}
