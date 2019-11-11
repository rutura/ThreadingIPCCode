#ifndef WORKER_H
#define WORKER_H

#include <QRunnable>
#include <QObject>

class Worker : public QRunnable
{

public:
    explicit Worker(QObject * receiver);
    ~Worker() override;


    // QRunnable interface
public:
    void run() override;

private:
    QObject * m_receiver;
};

#endif // WORKER_H
