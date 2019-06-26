#include "cast_helpers.h"

#include "SignValue.h"
#include "StringValue.h"

int get_sign_value(const std::shared_ptr<ValueCalc>& pValueContainer)
{
    auto pValue = pValueContainer->calculate();

    auto pSignValue = std::dynamic_pointer_cast<SignValue>(pValue);
    if(pSignValue)
        return pSignValue->value();

    auto pStringValue = std::dynamic_pointer_cast<StringValue>(pValue);
    if(pStringValue)
        return std::stoi(pStringValue->value());

    return 0;
}

std::string get_string_value(const std::shared_ptr<ValueCalc>& pValueContainer)
{
    auto pValue = pValueContainer->calculate();

    auto pSignValue = std::dynamic_pointer_cast<SignValue>(pValue);
    if(pSignValue)
        return std::to_string(pSignValue->value());

    auto pStringValue = std::dynamic_pointer_cast<StringValue>(pValue);
    if(pStringValue)
        return pStringValue->value();

    return 0;
}