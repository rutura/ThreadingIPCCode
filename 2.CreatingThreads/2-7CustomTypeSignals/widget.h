#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "numberedstring.h"

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

    void on_infoButton_clicked();

    void countDone();

    void currentCount(int value);

    void threadFinished();

    void currentNumberString(NumberedString ns);

private:
    Ui::Widget *ui;
    QThread * workerThread;
};

#endif // WIDGET_H
