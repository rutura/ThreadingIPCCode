#include "printdevice.h"
#include <QDebug>
#include <QMutexLocker>

PrintDevice::PrintDevice()
{
    m_count = 0;
}

void PrintDevice::print(const QString &text)
{
    QMutexLocker locker(&m_mutex);
    qDebug() << text << "Called , count : " << m_count++ ;
}
