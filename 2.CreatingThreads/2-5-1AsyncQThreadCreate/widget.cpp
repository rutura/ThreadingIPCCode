#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread : " << QThread::currentThread();

    thread = QThread::create([](){

        QTimer * timer = new QTimer();
        connect(timer,&QTimer::timeout,[](){
            qDebug() << "Time out . Running in thread : " << QThread::currentThread();
        });
        timer->start(1000);

    });

    connect(thread,&QThread::started,[](){
        qDebug() << "Thread started";
    });

    connect(thread,&QThread::finished,[](){
        qDebug() << "Thread finished";
    });

  //  thread->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    thread->start();
}
