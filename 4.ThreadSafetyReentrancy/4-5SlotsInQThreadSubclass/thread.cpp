#include "thread.h"
#include <QDebug>

Thread::Thread(QObject *parent) : QThread(parent),
    m_count(0)
{
    qDebug()  << "Thread constructor on thread : " << QThread::currentThread();
}

void Thread::increment()
{
    qDebug() << "Increment called on thread : " << QThread::currentThread();
    m_count++;

    if(m_count == 5){
        m_timer->stop();
        thread()->quit();
    }

}

void Thread::run() {
    //Managed thread

    qDebug() << "Run called on thread : " << QThread::currentThread();
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,&Thread::increment);
    m_timer->start(1000);
    exec();
}
