#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception
{
    public :
        virtual string what() = 0;
};

class SlotKosongException : public Exception
{
    public :
        string what() override;
};

class BukanMakananException : public Exception
{
    public :
        string what() override;
};

#endif