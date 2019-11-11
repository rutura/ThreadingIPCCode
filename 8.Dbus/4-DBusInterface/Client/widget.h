/*
 *          This example shows different ways you can use raw QDBusInterface to call
 *          methods in another process , and connect to signals coming from that
 *          process, like you would in a single Qt app.
 *
 *                   . QDBusReply<double> reply = interface->call("divide",ui->number1SpinBox->value(),ui->number2SpinBox->value());
 *
 *                   . QDBusReply<double> reply = interface->callWithArgumentList(QDBus::Block,"multiply",args);
 *
 *                   . interface->callWithCallback("multiply",args,this,SLOT(gotProduct(double)));
 *
 *                   . connect(interface,SIGNAL(productResult(double)),this,SLOT(gotProduct(double)));
 *              
                     . Do a lecture on introspection (https://techbase.kde.org/Development/Tutorials/D-Bus/Accessing_Interfaces),
                       in slide, and show that qdbus and qdbus viewer use this same tech. Get sections from the source code
                        when making slides.

 *
 * */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDBusInterface>


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

private:
    Ui::Widget *ui;
    QDBusInterface *interface;
};

#endif // WIDGET_H
