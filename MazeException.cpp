#include "MazeException.hpp"

MazeException::MazeException(const std::string & msg) : m_msg(msg)
{
}

const char * MazeException::what() const throw()
{
    return this->m_msg.c_str();
}
