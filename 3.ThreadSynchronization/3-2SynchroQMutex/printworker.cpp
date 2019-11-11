#include "printworker.h"
#include <QDebug>
#include <QMutexLocker>

PrintWorker::PrintWorker(QString name, bool * stop, QMutex * mutex,
                         QObject *parent) : QThread(parent) ,
    m_name(name),
    m_stop(stop),
    m_mutex(mutex)
{

}

PrintWorker::~PrintWorker()
{

}

void PrintWorker::run()
{
    while (!(*m_stop)) {

       // m_mutex->lock();
        QMutexLocker locker(m_mutex);

        if(*m_stop){
           // m_mutex->unlock();
            return;
        }

        qDebug() << m_name;
        sleep(1);


        //m_mutex->unlock();

    }

}
