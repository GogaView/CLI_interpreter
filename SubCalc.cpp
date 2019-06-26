#include "SubCalc.h"
#include "SignValue.h"
#include "cast_helpers.h"

#include <string>

const std::string& SubCalc::name()
{
    static std::string strName("sub");
    return strName;
}

SubCalc::SubCalc(const std::string& args)
    : FunctionCalc(args)
{
}

std::shared_ptr<ValueCalc> SubCalc::calculate() const
{
    int iSub = get_sign_value(m_vValues.front());
    for(auto it = m_vValues.begin() + 1; it != m_vValues.end(); ++it)
        iSub -= get_sign_value(*it);

    return std::shared_ptr<SignValue>(new SignValue(iSub));
}
