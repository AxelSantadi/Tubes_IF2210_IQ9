#ifndef INVENTORY_EXCEPTIONS_HPP
#define INVENTORY_EXCEPTIONS_HPP

#include "Exception.hpp"

class EmptyInventoryException : public Exception
{
public:
    string what() override;
};

class SlotKosongException : public Exception
{
public:
    string what() override;
};

class outOfBoundException : public Exception
{
public:
    string what() override;
};

class noFoodInInventory : public Exception
{
public:
    string what() override;
};

class penyimpananPenuhExeption : public Exception
{
public:
    string what() override;
};

#endif