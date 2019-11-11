#ifndef PRODUCER_H
#define PRODUCER_H

#include <QPushButton>
#include "customdata.h"

class Producer : public QPushButton
{
    Q_OBJECT
public:
    explicit Producer(QWidget *parent = nullptr);

signals:
    void data(const CustomData &);

public slots:
    void sendData();

private:
    int m_integer;
};

#endif // PRODUCER_H
