#pragma once

#include "FunctionCalc.h"

class SubCalc : public FunctionCalc
{
public:
    static const std::string& name();

    explicit SubCalc(const std::string& args);

    std::shared_ptr<ValueCalc> calculate() const;
};

