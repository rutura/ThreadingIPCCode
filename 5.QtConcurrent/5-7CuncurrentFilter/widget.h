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

private slots:
    void on_filterButton_clicked();

    void on_filterSpinBox_valueChanged(int arg1);

private:
    Ui::Widget *ui;
    int filterValue;
    QList<int> intList;
    QFuture<void> future;
    QFutureWatcher<void> futureWatcher;
};

#endif // WIDGET_H
