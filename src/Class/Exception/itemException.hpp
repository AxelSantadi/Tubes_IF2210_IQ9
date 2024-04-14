#ifndef ITEM_EXCEPTIONS_HPP
#define ITEM_EXCEPTIONS_HPP

#include "Exception.hpp"

class BukanMakananException : public Exception
{
public:
    string what() override;
};

class BukanMakananHewanException : public Exception
{
public:
    string what() override;
};

class BukanMakananHerbivore : public Exception
{
public:
    string what() override;
};

class BukanMakananCarnivore : public Exception
{
public:
    string what() override;
};

class BukanHewanException : public Exception
{
public:
    string what() override;
};

class BukanTanamanExeption : public Exception
{
public:
    string what() override;
};

class NegativePriceException : public Exception
{
public:
    string what() override;
};

class NegativeHarvestDurationException : public Exception
{
public:
    string what() override;
};

class NegativeUmurException : public Exception
{
public:
    string what() override;
};

class NegativeWeightToHarvestException : public Exception
{
public:
    string what() override;
};

class NegativeBeratException : public Exception
{
public:
    string what() override;
};

class NegativeAddedWeightException : public Exception
{
public:
    string what() override;
};



#endif