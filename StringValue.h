#pragma once

#include "ValueCalc.h"

#include <string>

bool is_string_value(const std::string& str);

class StringValue : public ValueCalc
{
public:
    explicit StringValue(const std::string& strValue);

    std::shared_ptr<ValueCalc> calculate() const;

    std::string value() const;
private:
    std::string m_strValue;
};
