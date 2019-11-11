#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void currentCount(int value);
    void countDone();
public slots:
    void doCounting();
};

#endif // WORKER_H
