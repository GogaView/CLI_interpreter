#pragma once
#include "FunctionCalc.h"

class MultiCalc : public FunctionCalc
{
public:
    static const std::string& name();

    explicit MultiCalc(const std::string& args);

    std::shared_ptr<ValueCalc> calculate() const;
};
