#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "producer.h"
#include "consumer.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Producer * producer;
    Consumer * consumer;
    QThread * thread;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // WIDGET_H
