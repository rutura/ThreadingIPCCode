#include "widget.h"
#include "ui_widget.h"
#include <QtConcurrent>
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread : " <<QThread::currentThread();

    //Populate int list with numbers
    for(int i{0} ; i < 100 ; i++){
        intList << QRandomGenerator::global()->bounded(1000);
    }

    qDebug() << "Before , item count : " << intList.count();

    //Clear the lists
    ui->originalList->clear();
    ui->filteredList->clear();


    //Populate original ui listWidget
    foreach (int value, intList) {
        ui->originalList->addItem(QString::number(value));
    }

    //Monitor work using QFutureWatcher

    connect(&futureWatcher, &QFutureWatcher<void>::started,[=](){

        qDebug() << "asynchronous : Work started.";

    });

    connect(&futureWatcher, &QFutureWatcher<void>::finished,[=](){

        qDebug() << "asynchronous : Work finished.";

        //Get the results and use them
        QList<int> newList = future.results();

        qDebug() << "After , item count : " << newList.count();

        foreach (int value, newList) {
            ui->filteredList->addItem(QString::number(value));
        }


    });

    filterValue = ui->filterSpinBox->value();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_filterButton_clicked()
{

    auto filter = [=](const int value){

        if(value >= filterValue){
            qDebug() << "Thread " << QThread::currentThread() << ". Value " << value << " greater that threshold " <<filterValue << " filtering out.";
            return false;
        }
        return true;
    };


    //Clear filtered list
    ui->filteredList->clear();

    future = QtConcurrent::filtered(intList,filter);

    future.waitForFinished();

    qDebug() << "synchronous : Work finished.";

    //Get the results and use them
    QList<int> newList = future.results();

    qDebug() << "After , item count : " << newList.count();

    foreach (int value, newList) {
        ui->filteredList->addItem(QString::number(value));
    }

   // futureWatcher.setFuture(future);


}

void Widget::on_filterSpinBox_valueChanged(int arg1)
{
    filterValue = arg1;
}
