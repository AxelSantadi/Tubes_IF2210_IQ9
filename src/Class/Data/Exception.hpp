#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception
{
    public :
        virtual string what() = 0;
};

class FileNotFound : public Exception
{
    public :
        string what() override;
};
class FileNotOpen : public Exception
{
    public :
        string what() override;
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

class noFoodInInventory : public Exception
{
    public :
        string what() override;
};

class BukanMakananException : public Exception
{
    public :
        string what() override;
};

class BukanHewanException : public Exception
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

class belumPanenExeption : public Exception
{
    public :
        string what() override;
};

class bukanPetaniExeption : public Exception
{
    public :
        string what() override;
};

class BukanWalikotaExeption : public Exception
{
    public :
        string what() override;
};

// class FileNotOpen : public exception {
// private:
//     std::string filename;
// public:
//     FileNotOpen(const std::string& filename) : filename(filename) {}
//     const char* what() const throw() {
//         return ("FileNotOpen: " + filename).c_str();
//     }
// };

#endif