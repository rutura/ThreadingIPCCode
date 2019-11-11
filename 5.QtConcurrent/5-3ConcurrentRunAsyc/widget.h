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

  static  QFuture<QVector<int>> heavyWorkWithReturn();

private slots:
    void on_startButton_clicked();

    void on_cancelButton_clicked();

    void on_pauseButton_clicked();

    void on_resumeButton_clicked();

private:
    Ui::Widget *ui;
    QFuture<QVector<int>> future;
    QFutureWatcher<QVector<int>> watcher;
};

#endif // WIDGET_H
