#ifndef PRINTDEVICE_H
#define PRINTDEVICE_H

#include <QString>
#include <QReadWriteLock>

class PrintDevice
{
public:
    PrintDevice();

    void print(const QString  & text);

    void increment();

private:
    int m_count;
    QReadWriteLock m_read_write_lock;
};

#endif // PRINTDEVICE_H
