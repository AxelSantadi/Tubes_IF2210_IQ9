#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include "../Items/Item.hpp"
#include "../Items/Animal.hpp"
#include "../Items/Plant.hpp"
#include "../Items/Product.hpp"

using namespace std;
class Inventory : public MatrixMap<Item>
{
public:
    // Constructors
    Inventory(int rows, char cols);

    // Getters and Setters
    int getJenisTiapItem(string c) const;

    // Methods
    void printInventory() const;

    int getJenisTiapItemNama(string c) const;
};

#endif