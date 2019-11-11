#include "widget.h"
#include "ui_widget.h"
#include "worker.h"
#include "progressevent.h"
#include <QThreadPool>
#include <QDebug>
#include <QEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread :" << QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::gotUpdate(int value)
{
    ui->progressBar->setValue(value);
}

void Widget::on_startButton_clicked()
{
    Worker * worker = new Worker(this);

    QThreadPool::globalInstance()->start(worker);
}

void Widget::on_infoButton_clicked()
{
    qDebug() << "ThreadPool max thread count : " << QThreadPool::globalInstance()->maxThreadCount();

    qDebug()  << " Ideal thread count : " << QThread::idealThreadCount();
}

bool Widget::event(QEvent *event)
{
    if(event->type() == static_cast<QEvent::Type>(ProgessEvent::EventId)){

        ProgessEvent * progressEvent = static_cast<ProgessEvent *>(event);

        //qDebug() << "Widget , progress is : " << progressEvent->progress();

        ui->progressBar->setValue(progressEvent->progress());

        return  true;
    }

    return QWidget::event(event);


}
