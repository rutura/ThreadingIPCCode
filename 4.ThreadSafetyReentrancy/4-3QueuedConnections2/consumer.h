#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <customdata.h>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);

signals:

public slots:
    void data(const CustomData &cd);
private:
    int m_counter;
};

#endif // CONSUMER_H
