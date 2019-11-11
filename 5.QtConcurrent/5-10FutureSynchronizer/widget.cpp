#include "widget.h"
#include "ui_widget.h"
#include <QtConcurrent>
#include <QFutureSynchronizer>
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



    filterValue = ui->filterSpinBox->value();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::reduce(int &sum, int value)
{
    sum  += value;
}

void Widget::on_filterButton_clicked()
{

    QFutureSynchronizer<void> synchronizer;

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

    QFuture <int> futureReduce = QtConcurrent::filteredReduced(intList,filter,reduce);

    synchronizer.addFuture(future);
    synchronizer.addFuture(futureReduce);


   // future.waitForFinished();

    qDebug() << "synchronous : Work finished.";

    //Get the results and use them
    QList<int> newList = future.results();

    qDebug() << "After , item count : " << newList.count();

    foreach (int value, newList) {
        ui->filteredList->addItem(QString::number(value));
    }

   // futureReduce.waitForFinished();
    qDebug() << "The sum is : " << futureReduce.result();
    ui->sumLabel->setText(QString::number(futureReduce.result()));
}

void Widget::on_filterSpinBox_valueChanged(int arg1)
{
    filterValue = arg1;
}
