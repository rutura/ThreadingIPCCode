#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSemaphore>
#include <QVector>
#include "producer.h"
#include "consumer.h"

const int BUFFER_SIZE = 6;

namespace Ui {
class Widget;
}

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
    bool atEnd;
    QSemaphore * freeSpace;
    QSemaphore * avSpace;
    QVector<int> dataSource;
    int  bufferArray [BUFFER_SIZE];
    Producer * producer;
    Consumer * consumer;
};

#endif // WIDGET_H
