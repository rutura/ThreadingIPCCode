#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemWatcher>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots :
    void reloadFile();

private:
    void createFileIfNotExist();
    Ui::Widget *ui;
    QFileSystemWatcher *m_watcher;
};

#endif // WIDGET_H
