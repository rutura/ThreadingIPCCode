#include "worker.h"
#include <QDebug>
#include <QThread>
#include <QApplication>
#include <QMetaObject>
#include <QVariant>
#include "progressevent.h"

Worker::Worker(QObject * receiver) : m_receiver(receiver)
{
    qDebug() << "Worker constructor running in thread : " << QThread::currentThread();
}

Worker::~Worker(){
    qDebug() << "Worker destructor running in thread : " << QThread::currentThread();

}

void Worker::run()
{
    qDebug() << "Worker run method running in thread : " << QThread::currentThread();

    for(int i{0} ; i < 1000000001 ; i++){

        if((i%100000) == 0){

            double percentage = ((i/1000000000.0)) * 100;
           // qDebug() << "Current percentage : " << percentage;

            /*
            QApplication::postEvent(m_receiver,
                         new ProgessEvent(QVariant::fromValue(percentage).toInt()));

            */
            QMetaObject::invokeMethod(m_receiver,"gotUpdate",
                                      Qt::QueuedConnection,
                                      Q_ARG(int,QVariant::fromValue(percentage).toInt()));
        }
    }
}
