#pragma once

#include "ValueCalc.h"

std::shared_ptr<ValueCalc> calculate_function(const std::string &strParams);
std::vector< std::shared_ptr<ValueCalc> > devide_by_args(const std::string& strParams);
bool is_exit_command(const std::string& strParams);