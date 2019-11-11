#include "producer.h"
#include <QRandomGenerator>

Producer::Producer(char * buffer, int bufferSize,
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

void Producer::run() {


     for (int i = 0; i < m_total_data; ++i) {
         m_mutex->lock();

         if((*m_used_slots) == m_buffer_size){
             m_buffer_full->wait(m_mutex);
         }
         m_mutex->unlock();

         //Write data to the buffer
         m_buffer[i % m_buffer_size] = "BACK"[QRandomGenerator::global()->bounded(4)];

         m_mutex->lock();
         ++(*m_used_slots);
         m_buffer_empty->wakeAll();
         m_mutex->unlock();
     }

}
