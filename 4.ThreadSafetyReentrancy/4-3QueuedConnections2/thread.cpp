#include "thread.h"
#include "consumer.h"

Thread::Thread(Producer * producer , QObject *parent) : QThread(parent),
    m_producer(producer)
{

}

void Thread::run()
{
    Consumer consumer;
    connect(m_producer,&Producer::data,&consumer,&Consumer::data);

    //Start our own event loop
    exec();
}
