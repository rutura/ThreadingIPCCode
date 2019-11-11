#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

void counting1(int count){
    for(int i{0} ; i < count ; i ++){
        qDebug() << "Counting : " << i << "thread : " <<  QThread::currentThread();
    }
}



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Main thread " << QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::counting()
{
    for(int i{0} ; i < 10000 ; i ++){
            qDebug() << "Counting method called : " << i <<
                        " thread :" << QThread::currentThread() << " id : " <<
                        QThread::currentThreadId() <<
                        "Thread is running : " << thread->isRunning();
        }
}

void Widget::on_startButton_clicked()
{


    /*
    //0.Freeze the UI
    for(int i{0} ; i < 1000000 ; i ++){
        qDebug() << " counting in ui thread...";
        qDebug() << "Counting : " << i <<
                    " thread :" << QThread::currentThread() << " id : " <<
                    QThread::currentThreadId();
    }

    */


    /*
    //1 .Global function
    thread = QThread::create(counting1,10000);
    */



    /*
    //2.Named lambda function

    auto countlambda = [](int count){
        for(int i{0} ; i < count ; i ++){
            qDebug() << "countlambda counting...";
            qDebug() << "Counting : " << i <<
                        " thread :" << QThread::currentThread() << " id : " <<
                        QThread::currentThreadId();
        }
    };

    thread = QThread::create(countlambda,1000000);
    */

    //3. Non named lambda function

    thread = QThread::create([](){
        for(int i{0} ; i < 100000 ; i ++){
            qDebug() << "Counting : " << i <<
                        " thread :" << QThread::currentThread() << " id : " <<
                        QThread::currentThreadId();
        }

    });


    //4.Member function, call from lamba function
    thread = QThread::create([=](){
        counting();
    });


    connect(thread,&QThread::started,[](){
        qDebug() << "Thread started";
    });

    connect(thread,&QThread::finished,[](){
        qDebug() << "Thread finished";
    });


    connect(thread,&QThread::finished,thread,&QThread::deleteLater);

    thread->start();




    qDebug() << "Clicked on the start button";

}
