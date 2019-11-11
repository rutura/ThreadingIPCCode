#ifndef PROGESSEVENT_H
#define PROGESSEVENT_H

#include <QEvent>

class ProgessEvent : public QEvent
{
public:
    enum {EventId = QEvent::User +1};
    ProgessEvent( int progress = 0);



    int progress() const;

private:
    int m_progress;
};

#endif // PROGESSEVENT_H
