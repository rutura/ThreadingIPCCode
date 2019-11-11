#include "numberedstring.h"

NumberedString::NumberedString()
{

}

NumberedString::NumberedString(int number, QString string) :
m_number(number), m_string(string)
{

}

int NumberedString::number() const
{
    return m_number;
}

QString NumberedString::string() const
{
    return m_string;
}
