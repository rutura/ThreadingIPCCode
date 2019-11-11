#ifndef CUSTOMDATA_H
#define CUSTOMDATA_H

#include <QString>
#include <QObject>

class CustomData
{
public:
    CustomData();
    CustomData(int integerArg, int* pointerArg, const QString& stringArg);


    int m_integer;
    int *m_pointer;
    QString m_string;
};
Q_DECLARE_METATYPE(CustomData)

#endif // CUSTOMDATA_H
