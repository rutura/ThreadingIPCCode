#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected slots :
    void gotConnection();
    void readData();

private:
    Ui::Widget *ui;
    QTcpServer m_server;
    QTcpSocket *m_socket;
};

#endif // WIDGET_H
