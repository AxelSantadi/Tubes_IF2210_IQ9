#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception
{
    public :
        virtual string what() = 0;
};

class EmptyInventoryException : public Exception
{
    public :
        string what() override;
};
class SlotKosongException : public Exception
{
    public :
        string what() override;
};

class outOfBoundException : public Exception
{
    public :
        string what() override;
};

class BukanMakananException : public Exception
{
    public :
        string what() override;
};

class BukanTanamanExeption : public Exception
{
    public :
        string what() override;
};

class penyimpananPenuhExeption : public Exception
{
    public :
        string what() override;
};

class salahPanenExeption : public Exception
{
    public :
        string what() override;
};

class jumlahPanenExeption : public Exception
{
    public :
        string what() override;
};

class salahPetakExeption : public Exception
{
    public :
        string what() override;
};

class petakTerisiExeption : public Exception
{
    public :
        string what() override;
};


#endif