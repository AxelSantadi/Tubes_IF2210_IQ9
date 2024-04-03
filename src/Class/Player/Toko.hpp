#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include "../Items/Item.hpp"
#include <vector>

class Toko
{
public:
    // Constructor
    Toko();
    ~Toko();

    // Methods
    void addItemToko(const Item &item);
    void removeItemToko(int index);

    // Getter
    Item getItemToko(int index) const;
    int getSizeToko() const;

    // Display
    void displayToko() const;

private:
    vector<Item> items;
};

#endif