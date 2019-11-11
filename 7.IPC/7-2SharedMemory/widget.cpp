#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QBuffer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    sharedMemory("SharedMemoryDemoApp")
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loadImageButton_clicked()
{
    if (sharedMemory.isAttached()){
        qDebug() << "Memory is attached, detaching";
        detach();
    }

    ui->imageLabel->setText(tr("Select an image file"));
    QString fileName = QFileDialog::getOpenFileName(nullptr, QString(), QString(),
                                                    tr("Images (*.png *.xpm *.jpg)"));
    QImage image;
    if (!image.load(fileName)) {
        ui->imageLabel->setText(tr("Selected file is not an image, please select another."));
        return;
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));


    // load into shared memory
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << image;
    int size =  buffer.size();


    qDebug() << "Size : " << size;
    if (!sharedMemory.create(size)) {
        ui->imageLabel->setText(tr("Unable to create shared memory segment."));
        qDebug() << sharedMemory.errorString();
        qDebug()  << "Is attached : " << sharedMemory.isAttached();
        return;
    }

    sharedMemory.lock();

    char *to = (char*)sharedMemory.data();
    const char *from = buffer.data().data();

    memcpy(to,from,qMin(sharedMemory.size(), size));

    sharedMemory.unlock();

}

void Widget::on_loadShareMemoryButton_clicked()
{

    if (!sharedMemory.attach()) {
        ui->imageLabel->setText(tr("Unable to attach to shared memory segment.\n" \
                                   "Load in the data first."));
        return;
    }


    QBuffer buffer;
    QDataStream in(&buffer);
    QImage image;

    sharedMemory.lock();

    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >> image;
    sharedMemory.unlock();

    sharedMemory.detach();

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));


}

void Widget::detach()
{
    if(!sharedMemory.detach()){
        ui->imageLabel->setText("Can not detach from the shared memory");
    }
}
