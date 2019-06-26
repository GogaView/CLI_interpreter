#include "SignValue.h"

#include <memory>
#include <string>

bool is_sign_value(const std::string& str)
{
    try
    {
        std::stoi(str);
        return true;
    }
    catch(std::exception)
    {
        return false;
    }
}

SignValue::SignValue(const std::string& strValue)
        :m_iValue(std::stoi(strValue))
{
}

SignValue::SignValue(int iValue)
    :m_iValue(iValue)
{
}

std::shared_ptr<ValueCalc> SignValue::calculate() const
{
    return std::make_shared<SignValue>(value());
}

int SignValue::value() const
{
    return m_iValue;
}