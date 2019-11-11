#include "customdata.h"

CustomData::CustomData() :
    m_integer(-1),m_pointer(nullptr),m_string()
{

}

CustomData::CustomData(int integerArg, int *pointerArg, const QString &stringArg) :
    m_integer(integerArg), m_pointer(pointerArg),m_string(stringArg)
{

}
