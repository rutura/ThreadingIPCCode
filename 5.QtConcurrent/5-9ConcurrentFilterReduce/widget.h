#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFuture>
#include <QFutureWatcher>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    static void reduce(int & sum, int value);

private slots:
    void on_filterButton_clicked();

    void on_filterSpinBox_valueChanged(int arg1);

private:
    Ui::Widget *ui;
    int filterValue;
    QList<int> intList;
    QFuture<int> future;
    QFutureWatcher<int> futureWatcher;


};

#endif // WIDGET_H
