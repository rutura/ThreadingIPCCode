#ifndef SLAVECALCULATOR_H
#define SLAVECALCULATOR_H

#include <QObject>

class SlaveCalculator : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.blikoon.CalculatorInterface")
public:
    explicit SlaveCalculator(QObject *parent = nullptr);

public slots:
    double multiply(double factor1, double factor2);
    double divide(double divident, double divisor);
};

#endif // SLAVECALCULATOR_H
