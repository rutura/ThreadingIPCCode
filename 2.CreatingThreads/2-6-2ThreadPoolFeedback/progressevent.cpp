#include "progressevent.h"

ProgessEvent::ProgessEvent(int progress) : QEvent(static_cast<Type>(EventId)),
    m_progress(progress)
{

}

int ProgessEvent::progress() const
{
    return m_progress;
}
