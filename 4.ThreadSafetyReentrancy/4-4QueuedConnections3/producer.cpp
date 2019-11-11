#include "producer.h"
#include <QDebug>
#include <QThread>

Producer::Producer(QWidget *parent) : QPushButton(parent)
{
    connect(this,&Producer::clicked,this,&Producer::sendData);
    m_integer = 10;
    setText("Produce");

    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,[=](){

        CustomData cd(22, &m_integer, "Produced data");
        emit data(cd);

    });
}

void Producer::sendData()
{
    qDebug() << "Producer producing data , thread :" << QThread::currentThread();
    CustomData cd(10, &m_integer, "Produced data");
    emit data(cd);
}

void Producer::startProduction()
{
    m_timer->start(1000);
}
