#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include "../Items/Item.hpp"
#include "../Items/Animal.hpp"
#include "../Items/Plant.hpp"
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Toko
{
private:
    map<string, pair<Item*, int>> items; 
    vector<Animal*> animals;
    vector<Plant*> plants;

public:
    // Constructor
    Toko(const vector<Animal*> &animals, const vector<Plant*> &plants);

    void saveStatetoko(ofstream &file);   
    // Add and Remove Item
    void addItemToko(Item* item);
    void removeItemToko(const std::string &itemName);

    // Getter
    int getItemPrice(const std::string &itemName) const;
    int getItemQuantity(const std::string &itemName) const;
    Item* getItemToko(const std::string &itemName) const;
    string getItemNameByNumber(int number) const;

    // Display Toko
    void displayToko() const;
};

#endif