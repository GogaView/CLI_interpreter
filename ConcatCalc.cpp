#include "ConcatCalc.h"
#include "cast_helpers.h"
#include "StringValue.h"

#include <string>

const std::string& ConcatCalc::name()
{
    static std::string strName("concat");
    return strName;
}

ConcatCalc::ConcatCalc(const std::string& args)
        : FunctionCalc(args)
{
}

std::shared_ptr<ValueCalc> ConcatCalc::calculate() const
{
    std::string strRes;
    for(auto val : m_vValues)
        strRes += std::string(" ") + get_string_value(val);

    return std::make_shared<StringValue>(strRes);
}