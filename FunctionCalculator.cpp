#include "ValueCalc.h"
#include "AddCalc.h"
#include "SignValue.h"
#include "StringValue.h"
#include "SubCalc.h"
#include "MultiCalc.h"
#include "ConcatCalc.h"
#include "parser_exception.h"

#include <string>

std::pair<std::string, std::string> get_front_param(const std::string& strParams)
{
    auto itSeporator = std::find(strParams.begin(), strParams.end(), ' ');
    std::string strHead(strParams.begin(), itSeporator);
    std::string strTail(itSeporator == strParams.end() ? strParams.end() : itSeporator + 1,
                        strParams.end());

    return std::make_pair(strHead, strTail);
}

std::string::const_iterator find_end_of_string(std::string::const_iterator itBegin, std::string::const_iterator itEnd)
{
    auto it = std::find(itBegin, itEnd, '"');
    if(it == itEnd)
        throw parser_exception("Can't find close commas!");

    return it;
}

bool is_new_function(const std::string& str)
{
    return str.front() == '(';
}

std::string::const_iterator find_end_of_function(std::string::const_iterator itBegin, std::string::const_iterator itEnd)
{
    unsigned uOpenBrase = 0;
    unsigned uCloseBrase = 0;

    for(auto it = itBegin; it != itEnd; ++it)
    {
        if(*it == '(')
            ++uOpenBrase;

        if(*it == ')')
            ++uCloseBrase;

        if(uOpenBrase == uCloseBrase)
            return it;
    }

    throw parser_exception("Invalid count of brackets!");
}

std::shared_ptr<ValueCalc> calculate_function(const std::string &strParams)
{
    std::pair<std::string, std::string> pairHeadTail = get_front_param(strParams);

    if(pairHeadTail.first == AddCalc::name())
        return std::make_shared<AddCalc>(pairHeadTail.second);

    else if(pairHeadTail.first == SubCalc::name())
        return std::make_shared<SubCalc>(pairHeadTail.second);

    else if(pairHeadTail.first == MultiCalc::name())
        return std::make_shared<MultiCalc>(pairHeadTail.second);

    else if(pairHeadTail.first == ConcatCalc::name())
        return std::make_shared<ConcatCalc>(pairHeadTail.second);

    throw parser_exception("Invalid command");
}

std::vector< std::shared_ptr<ValueCalc> > devide_by_args(const std::string& strParams)
{
    std::vector< std::shared_ptr<ValueCalc> > vValues;

    auto itBegin = strParams.begin();
    auto itEnd = std::find(strParams.begin(), strParams.end(), ' ');
    while(true)
    {
        std::string strValue(itBegin, itEnd);

        if(is_sign_value(strValue))
            vValues.push_back( std::make_shared<SignValue>(strValue) );

        else if(is_string_value(strValue))
        {
            itEnd = ::find_end_of_string(itBegin + 1, strParams.end());
            vValues.push_back( std::make_shared<StringValue>( std::string(itBegin + 1, itEnd)) );
        }

        else if(is_new_function(strValue))
        {
            itEnd = ::find_end_of_function(itBegin, strParams.end());
            vValues.push_back(calculate_function(std::string(itBegin + 1, itEnd)));
        }
        else
        {
            throw parser_exception("Undefined symbol!");
        }

        if(itEnd == strParams.end())
            break;

        itBegin = itEnd + 1;
        itEnd = std::find(itBegin, strParams.end(), ' ');
    }

    return vValues;
}

bool is_exit_command(const std::string& strParams)
{
    return strParams == "quit";
}