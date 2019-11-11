#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Server| Data receiver");

    m_socket = nullptr;


    m_server.listen(QHostAddress::LocalHost, 4040);
    connect(&m_server,&QTcpServer::newConnection,this,&Widget::gotConnection);

}

Widget::~Widget()
{

    if (m_socket) {
        qDebug() << "Closing socket :" << (m_socket==nullptr);
        m_socket->close();
        m_socket->deleteLater();
    }
    m_server.close();
    delete ui;
}

void Widget::gotConnection()
{
    qDebug() << "Server got new connection";
    m_socket = m_server.nextPendingConnection();
    connect(m_socket,&QTcpSocket::readyRead,this,&Widget::readData);

}

void Widget::readData()
{
    QDataStream in(m_socket);

    in.startTransaction();


    QString rcvString;
    in >> rcvString;

    if(!in.commitTransaction()){
        return; //Wait for more data
    }

    ui->textEdit->append(rcvString);

}
