/*
 *          This example is the client side of our example of dbus, exposing
 *          a calculator in the server part and using it in the client.
 *
 *              . The client uses the interface exposed from the server to call
 *                stuff on the server object.
 *
 *              . Interface class is generated from xml interface descriptor file,
 *                see info in comments in server widget.h.
 *
 *
 *              . We instantiate the interface in the constructor and give it clear
 *                information on the , service, path and dbus connection.
 *
 *              . For the rest, make sure you just explain the concepts of dbus in
 *                the slides you're going to put together.
 *
 * */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <calculatorInterface.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();



private slots:
    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

private:
    Ui::Widget *ui;
    com::blikoon::CalculatorInterface * calculatorHandle;
};

#endif // WIDGET_H
