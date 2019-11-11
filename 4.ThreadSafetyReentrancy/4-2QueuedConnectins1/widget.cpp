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

    connect(thread,&QThread::finished,[=](){
        qDebug() << "Application about to be killed , thread : " << QThread::currentThread();
        QApplication::quit();

    });


    //Do queued connection
    connect(producer,&Producer::data,consumer,&Consumer::data);

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
