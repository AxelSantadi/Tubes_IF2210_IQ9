#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include "MatrixMap.cpp"
#include "Product.hpp"
#include "Product.cpp"
using namespace std;

class Inventory
{
private:
    MatrixMap<Product> items;

public:
    // Constructors
    Inventory(int rows, char cols);
    
    // Getters and Setters
    Product getItem(int i, char j) const ;
    void setItem(int i, char j, Product item);
    
    // Methods
    void printInventory() const;
};

#endif