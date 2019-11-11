#include "slavecalculator.h"

SlaveCalculator::SlaveCalculator(QObject *parent) : QObject(parent)
{

}

double SlaveCalculator::multiply(double factor1, double factor2)
{
    double product = factor1 * factor2;
    emit productResult(product);
    return product;
}

double SlaveCalculator::divide(double divident, double divisor)
{
    double quotient = divident / divisor;
    emit divisionResult(quotient);
    return quotient;
}
