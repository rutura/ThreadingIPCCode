/*
 *          This example is the client side of our example of dbus, exposing
 *          a calculator in the server part and using it in the client.We show
 *          how you can connect signals to slots across processes. Signlas are emited
 *          in the server and consumed in the client.
 *
 *              . We add the signals in the slavecalculator class in the server
 *
 *              . We generate the xml descriptor file . See command to generate xml in server
 *                widget.h file. You can also peak in the cpp2xml file you have on your
 *                desktop(linux ubuntu).
 *
 *
 *              . We use the xml file to generate adaptor in server, and interface in
 *                client.
 *
 *              . We connect to signals from the server in the client using the syntax :
 *                      bool connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                          "com.blikoon.CalculatorInterface","productResult","d",
                                          this,SLOT(gotProduct(double)));
                        qDebug() << "product signal connected : " << connected;

                        connected  = QDBusConnection::sessionBus().connect(QString(),QString(),
                                              "com.blikoon.CalculatorInterface","divisionResult","d",
                                              this,SLOT(gotQuotient(double)));
                        qDebug() << "product signal connected : " << connected;


 *
 * */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "calculatorINterface.h"

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
    com::blikoon::CalculatorInterface * calculatorHandle;
};

#endif // WIDGET_H
