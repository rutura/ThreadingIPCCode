#ifndef PRODUCER_H
#define PRODUCER_H

#include <QPushButton>
#include <QTimer>
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
    void startProduction();

private:
    int m_integer;
    QTimer * m_timer;
};

#endif // PRODUCER_H
