/*
 *          This example shows how to use QDBubMessage to carry out calls
 *          to methods living in an object inside another process.
 *
 *
 *              . We use QDBusConnection::sessionBus().send(m) if we don't need
 *                a return value
 *              . We use QDBusConnection::sessionBus().call(m) if we need a
 *                return value.
 *
 *              . Show how to parse for the response if you need that.
 *
 *              . Show how you can send signals using the QDBusMessage::createSignal()
 *                method in client process,  and how you can receive the signal in server.
 *                We add a button to send the message to the server for this purpose.
 *
 *


 *
 * */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include "calculatorINterface.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:
    void gotProduct(double value);
    void gotQuotient(double value);


private slots:
    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

    void on_messageToServerButton_clicked();

private:
    Ui::Widget *ui;
    //com::blikoon::CalculatorInterface * calculatorHandle;
};

#endif // WIDGET_H
