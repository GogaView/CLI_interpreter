#pragma once

#include <memory>

class ValueCalc
{
public:
    virtual std::shared_ptr<ValueCalc> calculate() const = 0;
};
