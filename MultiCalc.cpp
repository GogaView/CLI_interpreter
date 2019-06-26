#include "MultiCalc.h"
#include "cast_helpers.h"
#include "SignValue.h"

#include <string>

const std::string& MultiCalc::name()
{
    static std::string strName("mult");
    return strName;
}

MultiCalc::MultiCalc(const std::string& args)
        : FunctionCalc(args)
{
}

std::shared_ptr<ValueCalc> MultiCalc::calculate() const
{
    int iMult = 1;
    for(auto val : m_vValues)
        iMult *= get_sign_value(val);

    return std::shared_ptr<SignValue>(new SignValue(iMult));
}