#pragma once

#include "FunctionCalc.h"

#include <vector>

class AddCalc : public FunctionCalc
{
public:
    static const std::string& name();

    explicit AddCalc(const std::string& args);

    std::shared_ptr<ValueCalc> calculate() const;
};