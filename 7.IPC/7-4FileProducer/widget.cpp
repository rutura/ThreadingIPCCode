#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("File Producer");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &text)
{

    QFile outFile(QString(QDir::tempPath() + "/sharedFile"));
    qDebug() << "File path : " << outFile.fileName();
    outFile.open(QFile::WriteOnly| QIODevice::Append);
    QDataStream out(&outFile);
    out << text;

}
