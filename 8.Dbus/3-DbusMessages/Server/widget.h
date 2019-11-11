/*
 *
 *          Command to generate xml : /home/gakwaya/Qt5.12.3/5.12.3/gcc_64/bin/qdbuscpp2xml -M -S slavecalculator.h -o slavecalculator.xml
 *
 *
 *


 *
 * */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "slavecalculator.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void messageSlot(QString message);

private:
    Ui::Widget *ui;
    SlaveCalculator * slaveCalculator;
};

#endif // WIDGET_H
