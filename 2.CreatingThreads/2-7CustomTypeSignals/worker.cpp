#include "worker.h"
#include <QVariant>
#include <QThread>
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{
    qDebug() << "Worker constructor running in thread : " << QThread::currentThread();
}

Worker::~Worker()
{
    qDebug() << "Worker destroyed, destructor running in thread : " << QThread::currentThread();
}

void Worker::doCounting()
{

    qDebug() << "Worker counting method running in thread : " << QThread::currentThread();
    //Code here is going to run in secondary/background thread

    for(int i{0} ; i < 1000000001 ; i++){

        double percentage = (i/ 1000000000.0) * 100.0;

        //qDebug() << "Percentage : " << percentage;

        if((i% 100000) ==0){

            QString txt = "Hello " +QString::number(QVariant::fromValue(percentage).toInt());

            NumberedString ns(QVariant::fromValue(percentage).toInt(),txt);

            emit currentNumberString(ns);
        }
    }
    emit countDone();
}
