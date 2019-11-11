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
    static void modify(int & value);

private slots:
    void on_modifyButton_clicked();

    void on_seeValuesButton_clicked();

private:
    Ui::Widget *ui;
    QList<int> list;
    QFuture<void> future;
    QFutureWatcher<void> futureWatcher;
};

#endif // WIDGET_H
