#include "AddCalc.h"
#include "SignValue.h"
#include "StringValue.h"
#include "cast_helpers.h"

#include <numeric>
#include <string>

const std::string& AddCalc::name()
{
    static std::string strName("add");
    return strName;
}

AddCalc::AddCalc(const std::string& args)
    : FunctionCalc(args)
{
}

std::shared_ptr<ValueCalc> AddCalc::calculate() const
{
    int iSum = 0;
    for(auto val : m_vValues)
        iSum += get_sign_value(val);

    return std::shared_ptr<SignValue>(new SignValue(iSum));
}