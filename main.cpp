#include <iostream>

#include "FunctionCalculator.h"
#include "cast_helpers.h"
#include "parser_exception.h"

int main()
{
    std::string strFunction;
    while(true)
    {
        std::cout << "$ ";
        std::getline(std::cin, strFunction);

        if(is_exit_command(strFunction))
            break;

        try
        {
            auto pValue = ::calculate_function(strFunction);
            std::cout << "> " << get_string_value(pValue->calculate()) << std::endl;
        }
        catch (parser_exception exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }

    return 0;
}