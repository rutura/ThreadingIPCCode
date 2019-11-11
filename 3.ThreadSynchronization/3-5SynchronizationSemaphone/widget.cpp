#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    dataSource << 1 << 2 << 34 <<55 << 4<< 11 << 22 << 34 <<55 <<
                      4<< 1 << 2 << 34 <<55 << 4<< 1 << 2 << 34 <<55 << 4<<2222;

    atEnd = false;


    freeSpace = new QSemaphore(BUFFER_SIZE);

    avSpace = new QSemaphore(0);

    producer = new Producer(dataSource,bufferArray,BUFFER_SIZE,freeSpace,avSpace,&atEnd);
    consumer = new Consumer(bufferArray,BUFFER_SIZE,freeSpace,avSpace,&atEnd);
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

    atEnd = false;

}
