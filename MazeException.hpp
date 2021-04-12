#pragma once

#include <string>
#include <exception>
#include <stdexcept>

class MazeException final : public std::exception
{
private:
    std::string m_msg;

public:
    MazeException(const std::string &);
    const char * what() const throw();
};
