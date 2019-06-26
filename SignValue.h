#pragma once

#include "ValueCalc.h"

bool is_sign_value(const std::string&);

class SignValue : public ValueCalc
{
public:
    explicit SignValue(const std::string& strValue);
    explicit SignValue(int);

    std::shared_ptr<ValueCalc> calculate() const;

    int value() const;
private:
    int m_iValue;
};
