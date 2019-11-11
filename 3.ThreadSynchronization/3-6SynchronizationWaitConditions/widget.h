#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWaitCondition>
#include <QMutex>
#include "producer.h"
#include "consumer.h"

namespace Ui {
class Widget;
}

const int M_BUFFER_SIZE = 6000;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();

private:
    Ui::Widget *ui;

    int totalData;
    char buffer[M_BUFFER_SIZE];
    QWaitCondition bufferFull;
    QWaitCondition bufferEmpty;
    QMutex mutex;
    int usedSlots;
    Producer * producer;
    Consumer * consumer;
};

#endif // WIDGET_H
