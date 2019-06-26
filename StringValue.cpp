#include "StringValue.h"

#include <memory>
#include <string>

bool is_string_value(const std::string& str)
{
    return str.front() == '"';
}

StringValue::StringValue(const std::string& strValue)
        : m_strValue(strValue)
{
}

std::shared_ptr<ValueCalc> StringValue::calculate() const
{
    return std::make_shared<StringValue>( value() );
}

std::string StringValue::value() const
{
    return m_strValue;
}
