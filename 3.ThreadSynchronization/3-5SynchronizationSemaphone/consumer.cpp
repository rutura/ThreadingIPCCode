#include "consumer.h"
#include <QDebug>

Consumer::Consumer(int *buffer, int bufferSize,QSemaphore * freeSpace,
                   QSemaphore * availableSpace,
                   bool * atEnd,QObject *parent) :
    QThread(parent),
    m_buffer(buffer),m_BUFFER_SIZE(bufferSize),
    m_free_space(freeSpace),
    m_available_space(availableSpace),
    m_at_end(atEnd)
{

}

void Consumer::run()
{

    int i{0};

       while(!(*m_at_end) || m_available_space->available()){
           m_available_space->acquire();
           //READ DATA

           qDebug() << "[" << i << "]" << m_buffer[i];//Consume data

           i =((i+1) % (m_BUFFER_SIZE));

           m_free_space->release();

       }

}
