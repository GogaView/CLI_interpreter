#pragma once

#include <exception>
#include <string>

class parser_exception : public std::exception
{
public:
    explicit parser_exception(const std::string& strMsg)
            : m_strMsg(strMsg)
    {
    }

    const char* what () const throw ()
    {
        return m_strMsg.c_str();
    }

private:
    const std::string m_strMsg;
};