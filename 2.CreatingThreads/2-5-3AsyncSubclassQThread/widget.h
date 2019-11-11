#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "workerthread.h"

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
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::Widget *ui;
    WorkerThread * thread;
};

#endif // WIDGET_H
