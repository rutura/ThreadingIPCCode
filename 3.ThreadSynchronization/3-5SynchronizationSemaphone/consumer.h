#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QSemaphore>

class Consumer : public QThread
{
    Q_OBJECT
public:
    explicit Consumer(int *buffer, int bufferSize,QSemaphore * freeSpace,
                      QSemaphore * availableSpace,
                      bool * atEnd,QObject *parent = nullptr);

signals:

public slots:

    // QThread interface
protected:
    void run() override;

private:
    int * m_buffer;
    int m_BUFFER_SIZE;
    QSemaphore * m_free_space;// Space where the producer can write data
    QSemaphore * m_available_space;//Space where consumer can read data from
    bool * m_at_end;
};

#endif // CONSUMER_H
