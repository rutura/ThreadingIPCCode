#include "consumer.h"
#include <QDebug>

Consumer::Consumer(char * buffer, int bufferSize,
                   int * usedSlots, int totalData,
                   QMutex * mutex,
                   QWaitCondition * bufferFull,QWaitCondition * bufferEmpty,
                   QObject *parent) : QThread(parent),
    m_buffer(buffer), m_buffer_size(bufferSize),
    m_used_slots(usedSlots),m_total_data(totalData),
    m_mutex(mutex),
    m_buffer_full(bufferFull),
    m_buffer_empty(bufferEmpty)
{

}
void Consumer::run(){

    for (int i = 0; i < m_total_data; ++i) {
        m_mutex->lock();

        if((*m_used_slots) == 0){
            m_buffer_empty->wait(m_mutex);//FREEZE CODE EXECUTION IN THE THEAD
        }

        m_mutex->unlock();

        //Write data to console
        qDebug() << "Consumer data : " << m_buffer[i % m_buffer_size];


        m_mutex->lock();
        --(*m_used_slots);
        m_buffer_full->wakeAll();
        m_mutex->unlock();
    }
}
