#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_watcher(new QFileSystemWatcher(this))

{
    ui->setupUi(this);
    setWindowTitle("Consumer Process | Files");
    createFileIfNotExist();
    m_watcher->addPath(QString(QDir::tempPath() + "/sharedFile"));

    connect(m_watcher, &QFileSystemWatcher::fileChanged, this, &Widget::reloadFile);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::reloadFile()
{

    QFile inFile(QString(QDir::tempPath() + "/sharedFile"));
    QString transferedStr;
    if (!inFile.open(QFile::ReadOnly)){
        qDebug() << "Consumer , can't find file :" << inFile.fileName();
        return;

    }

    qDebug() <<"Found file : " << inFile.fileName();
    QDataStream in(&inFile);

    ui->textEdit->clear();

    while(!in.atEnd()){
           in >> transferedStr;
           ui->textEdit->append(transferedStr);
       }

    qDebug() << "Consumer done appending data";
}

void Widget::createFileIfNotExist()
{
    QFile file(QString(QDir::tempPath() + "/sharedFile"));
    if(!file.exists()){
        //Just opening the file will create it if it doesn't exist yet.
        file.open(QFile::WriteOnly| QIODevice::Append);
    }

}
