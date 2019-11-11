#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "numberedstring.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void currentCount(int value);
    void currentNumberString(NumberedString ns);
    void countDone();
public slots:
    void doCounting();
};

#endif // WORKER_H
