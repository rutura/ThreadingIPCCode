#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_socket(new QTcpSocket(this)),
    m_socketReady(false)

{
    ui->setupUi(this);

    setWindowTitle("Client | Data Sender");

    m_socket->connectToHost("localhost", 4040);

    connect(m_socket, &QTcpSocket::connected, this, &Widget::socketReady);
    connect(m_socket,&QTcpSocket::stateChanged,this,&Widget::stateChanged);

}

Widget::~Widget()
{
    m_socket->close();
    delete ui;
}

void Widget::socketReady()
{
    m_socketReady = true;
}

void Widget::stateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << socketState;
}

void Widget::on_lineEdit_textChanged(const QString &newText)
{
    if(m_socketReady){
        QDataStream out(m_socket);
        out << newText;
    }
}
