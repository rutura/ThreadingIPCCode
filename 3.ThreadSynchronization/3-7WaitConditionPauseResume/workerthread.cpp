#include "workerthread.h"
#include <QDebug>

WorkerThread::WorkerThread(QObject *parent) : QThread(parent)
{
    m_pause = false;
    qDebug() << "WorkerThread object constructed thread : " << QThread::currentThread();

}

WorkerThread::~WorkerThread()
{
    qDebug() << "WorkerThread object destroyed thread : " << QThread::currentThread();
}

void WorkerThread::pause()
{
    qDebug() << "Pause method running in thread : " << QThread::currentThread();
    m_mutex.lock();

    m_pause = true;
    m_mutex.unlock();

}

void WorkerThread::resume()
{
    qDebug() << "Resume method running in thread : " << QThread::currentThread();

    m_mutex.lock();

    m_pause = false;

    m_mutex.unlock();
    m_pause_condition.wakeAll();


}

void WorkerThread::run()
{
    qDebug() << "Run method running in thread : " << QThread::currentThread();


    for(int i{0} ; i < 1000000001 ; i++){


        m_mutex.lock();

        if(m_pause)
            m_pause_condition.wait(&m_mutex);//Freeze code execution in this thread

        m_mutex.unlock();

        /*
                 * Only emit signal to send info to ui at 100000 intervals. UI can handle this.
                 * Otherwise it is going to freeze.
                 * */
        if((i%100000) == 0){
            double percentage = ((i/1000000000.0)) * 100;
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }

    }

}
