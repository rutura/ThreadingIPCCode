#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QSemaphore>
#include <QVector>

class Producer : public QThread
{
    Q_OBJECT
public:
    explicit Producer(const QVector<int> & dataSource,
                      int * buffer,int bufferSize,QSemaphore * freeSpace,
                     QSemaphore * availableSpace,
                     bool * atEnd,QObject *parent = nullptr);

signals:

public slots:

    // QThread interface
protected:
    void run() override;

private:
    QVector<int> m_data_source;
    int * m_buffer;
    int m_BUFFER_SIZE;
    QSemaphore * m_free_space;// Space where the producer can write data
    QSemaphore * m_available_space;//Space where consumer can read data from
    bool * m_at_end;
};

#endif // PRODUCER_H
