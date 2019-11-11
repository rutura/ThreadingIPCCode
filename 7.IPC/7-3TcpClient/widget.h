#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots :
    void socketReady();
    void stateChanged(QAbstractSocket::SocketState socketState);

    void on_lineEdit_textChanged(const QString &newText);

private:
    Ui::Widget *ui;
    QTcpSocket *m_socket;
    bool m_socketReady;
};

#endif // WIDGET_H
