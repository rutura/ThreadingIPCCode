#ifndef PRINTDEVICE_H
#define PRINTDEVICE_H

#include <QString>
#include <QMutex>

class PrintDevice
{
public:
    PrintDevice();

    void print(const QString & text);

private:
    int m_count;
    QMutex m_mutex;
};

#endif // PRINTDEVICE_H
