#ifndef PRINTWORKER_H
#define PRINTWORKER_H

#include <QThread>
#include <QMutex>

class PrintWorker : public QThread
{
    Q_OBJECT
public:
    explicit PrintWorker(QString name, bool * stop, QMutex * mutex,
                         QObject *parent = nullptr);
    ~PrintWorker() override;

signals:

public slots:

    // QThread interface
protected:
    void run() override;
private:
    QString m_name;
    bool * m_stop;
    QMutex * m_mutex;
};

#endif // PRINTWORKER_H
