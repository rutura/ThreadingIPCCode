#include "incrementworker.h"

IncrementWorker::IncrementWorker(bool * stop,PrintDevice * printDevice,
                                 QObject *parent) : QThread(parent),
    m_print_device(printDevice),
    m_stop(stop)
{

}

void IncrementWorker::run()
{
        while (!(*m_stop)) {
            msleep(1500);
            m_print_device->increment();
        }

}
