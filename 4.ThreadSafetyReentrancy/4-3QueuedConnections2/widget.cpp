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

    thread = new Thread(producer);

    connect(thread,&QThread::finished,[=](){
        qDebug() << "Application about to be killed , thread : " << QThread::currentThread();
        QApplication::quit();

    });

    thread->start();

    producer->startProduction();


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
