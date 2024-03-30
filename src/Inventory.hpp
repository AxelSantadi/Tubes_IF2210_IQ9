#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include "MatrixMap.cpp"
#include "Product.hpp"
#include "Product.cpp"
using namespace std;
class Inventory : public MatrixMap<Product>
{
public:
    // Constructors
    Inventory(int rows, char cols);

    // Getters and Setters
    int getJenisTiapItem(string c) const;

    // Methods
    void printInventory() const;
};

#endif