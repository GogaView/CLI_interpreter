#pragma once
#include "FunctionCalc.h"

class ConcatCalc : public FunctionCalc
{
public:
    static const std::string& name();

    explicit ConcatCalc(const std::string& args);

    std::shared_ptr<ValueCalc> calculate() const;
};
