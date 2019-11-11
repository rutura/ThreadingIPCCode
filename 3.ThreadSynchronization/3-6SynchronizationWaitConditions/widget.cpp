#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    totalData = 100000;
    usedSlots = 0;


    producer = new Producer(buffer,M_BUFFER_SIZE,&usedSlots,totalData,
                                 &mutex,&bufferFull,&bufferEmpty);

    consumer = new Consumer(buffer,M_BUFFER_SIZE,&usedSlots,totalData,
                                 &mutex,&bufferFull,&bufferEmpty);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    producer->start();
    consumer->start();

    producer->wait();
    consumer->wait();

}
