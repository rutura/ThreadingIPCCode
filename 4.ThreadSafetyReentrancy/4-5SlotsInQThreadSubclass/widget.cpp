#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "GUI thread : " << QThread::currentThread();

    thread = new Thread(this);
    thread->start();
}

Widget::~Widget()
{
    delete ui;
}
