#include "producer.h"

Producer::Producer(const QVector<int> & dataSource,  int * buffer,
                   int bufferSize,QSemaphore *freeSpace,
                   QSemaphore *availableSpace, bool *atEnd,QObject *parent) :
    QThread(parent),
    m_data_source(dataSource),
    m_buffer(buffer),
    m_BUFFER_SIZE(bufferSize),
    m_free_space(freeSpace),
    m_available_space(availableSpace),
    m_at_end(atEnd)
{

}

void Producer::run()
{
    for(int i{0} ; i < m_data_source.length() ; i++){

        m_free_space->acquire();
        //WRITE DATA

        m_buffer[ i % m_BUFFER_SIZE] = m_data_source.at(i);

        if(i == m_data_source.length() -1)
            *m_at_end = true;


        m_available_space->release();
    }

}
