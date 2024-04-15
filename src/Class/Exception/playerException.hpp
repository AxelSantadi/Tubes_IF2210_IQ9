#ifndef PLAYER_EXCEPTIONS_HPP
#define PLAYER_EXCEPTIONS_HPP

#include "Exception.hpp"

class salahPanenExeption : public Exception
{
public:
    string what() override;
};

class jumlahPanenExeption : public Exception
{
public:
    string what() override;
};

class salahPetakExeption : public Exception
{
public:
    string what() override;
};

class petakTerisiExeption : public Exception
{
public:
    string what() override;
};

class belumPanenExeption : public Exception
{
public:
    string what() override;
};

class bukanPetaniExeption : public Exception
{
public:
    string what() override;
};

class BukanWalikotaExeption : public Exception
{
public:
    string what() override;
};

class BukanPeternakExeption : public Exception
{
public:
    string what() override;
};

class bukanPetanidanPeternakExeption : public Exception
{   
public:
    string what() override;
};

class ItemNotFoundException : public Exception
{
public:
    string what() override;
};

class NumberOutOfRangeException : public Exception
{
public:
    string what() override;
};

class takAdaResep : public Exception
{
public:
    string what() override;
};

class FullKandgangException : public Exception
{
public:
    string what() override;
};

class FullLadangException : public Exception
{
public:
    string what() override;
};

class TidakPunyaTanamanException : public Exception
{   
public:
    string what() override;
};

class TidakPunyaHewanException : public Exception
{
public:
    string what() override;
};

class jumlahPanenTernakException : public Exception
{
public:
    string what() override;
};

#endif