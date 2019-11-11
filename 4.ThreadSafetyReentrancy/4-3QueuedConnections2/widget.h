#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "producer.h"
#include "consumer.h"
#include "thread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    Producer * producer;
    Consumer * consumer;
    Thread * thread;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // WIDGET_H
