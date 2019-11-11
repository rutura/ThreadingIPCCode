#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

public slots :
    void gotUpdate(int value);

private slots:
    void on_startButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::Widget *ui;

    // QObject interface
public:
    bool event(QEvent *event) override;
};

#endif // WIDGET_H
