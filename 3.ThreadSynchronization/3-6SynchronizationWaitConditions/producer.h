#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QWaitCondition>
#include <QMutex>

class Producer : public QThread
{
    Q_OBJECT
public:
    explicit Producer(char * buffer, int bufferSize,
                      int * usedSlots, int totalData,
                      QMutex * mutex,
                      QWaitCondition * bufferFull,QWaitCondition * bufferEmpty,
                      QObject *parent = nullptr);

signals:

public slots:

    // QThread interface
protected:
    void run() override;

private:
    char * m_buffer;
    int m_buffer_size;
    int * m_used_slots;
    int m_total_data;
    QMutex * m_mutex;
    QWaitCondition * m_buffer_full;
    QWaitCondition * m_buffer_empty;
};

#endif // PRODUCER_H
