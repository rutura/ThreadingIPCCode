#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSharedMemory>

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
    void on_loadImageButton_clicked();

    void on_loadShareMemoryButton_clicked();

    void detach();

private:
    Ui::Widget *ui;
    QSharedMemory sharedMemory;

};

#endif // WIDGET_H
