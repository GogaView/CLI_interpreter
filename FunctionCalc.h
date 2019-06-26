#pragma once

#include "ValueCalc.h"
#include "FunctionCalculator.h"

#include <vector>

class FunctionCalc : public ValueCalc
{
public:
    explicit FunctionCalc(const std::string& args)
        : m_vValues(devide_by_args(args))
    {

    }

protected:
    std::vector< std::shared_ptr<ValueCalc> > m_vValues;
};