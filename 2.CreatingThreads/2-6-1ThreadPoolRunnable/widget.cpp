#include "widget.h"
#include "ui_widget.h"
#include "worker.h"
#include <QThreadPool>
#include <QDebug>

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

void Widget::on_startButton_clicked()
{
    Worker * worker = new Worker();

    QThreadPool::globalInstance()->start(worker);
}

void Widget::on_infoButton_clicked()
{

}
