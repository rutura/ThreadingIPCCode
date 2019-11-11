#ifndef PRINTWORKER_H
#define PRINTWORKER_H

#include <QThread>
#include "printdevice.h"

class PrintWorker : public QThread
{
    Q_OBJECT
public:
    explicit PrintWorker(QString name, bool * stop, PrintDevice * worker,QObject *parent = nullptr);

signals:

public slots:
private:
    QString m_name;
    bool * m_stop;
    PrintDevice * m_print_device;

    // QThread interface
protected:
    void run() override;
};

#endif // PRINTWORKER_H
