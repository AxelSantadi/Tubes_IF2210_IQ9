#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include "../Items/Item.hpp"
#include "../Items/Animal.hpp"
#include "../Items/Plant.hpp"
#include "../Items/Product.hpp"
#include "../Exception/Exception.hpp"
#include "../Exception/fileException.hpp"
#include "../Exception/inventoryException.hpp"
#include "../Exception/itemException.hpp"
#include "../Exception/playerException.hpp"

using namespace std;
class Inventory : public MatrixMap<Item *>
{
public:
    // Constructors
    Inventory(int rows, char cols);

    // Getters and Setters
    int getJenisTiapItem(string c) const;
    void setValue(int x, char c, Item *value) override;
    void removeValue(int x, char c) override;

    // Methods
    void setRandomValue(Item *item);

    void printInventory() const;

    bool noFood() const;

    bool noFoodHerbivore() const;
    bool noFoodCarnivore() const;
    bool noPlant() const;
    bool noAnimal() const;

    int getJenisTiapItemNama(string c) const;

    void storeItemInSlot(Item *item, const std::string &slot);

    Inventory& operator+(Item *item);
    Inventory& operator+=(Item *item);
};

#endif