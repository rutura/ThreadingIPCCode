#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QApplication>
#include <QCloseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Ui thread : " << QThread::currentThread();

    producer = new Producer(this);
    ui->verticalLayout->addWidget(producer);

    consumer = new Consumer();

    thread = new QThread(this);

    connect(producer, &Producer::data, consumer, &Consumer::data);
    connect(thread,&QThread::started,producer,&Producer::startProduction);
    connect(thread, &QThread::finished,consumer, &QObject::deleteLater);

    consumer->moveToThread(thread);

    thread->start();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    //Quit thread before killing app
    thread->quit();

    event->accept();
}
