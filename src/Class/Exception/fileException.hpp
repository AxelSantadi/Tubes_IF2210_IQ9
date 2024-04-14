#ifndef FILE_EXCEPTIONS_HPP
#define FILE_EXCEPTIONS_HPP

#include "Exception.hpp"

class FileNotFound : public Exception
{
public:
    string what() override;
};
class FileNotOpen : public Exception
{
public:
    string what() override;
};



#endif