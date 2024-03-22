#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include "Product.hpp"
using namespace std;

class Inventory
{
private:
    int n;
    int m;
    MatrixMap<Product> items;

public:
    Inventory(int n, int m);
    int getN() const;
    int getM() const;
    Product getItem(int i, int j) const ;
    void setItem(int i, int j, Product item);
    void setN(int n);
    void setM(int m);
};

#endif