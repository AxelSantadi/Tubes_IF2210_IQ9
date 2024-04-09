#ifndef READCONFIG_HPP
#define READCONFIG_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>
#include "Misc.hpp"
#include "Recipe.hpp"
#include "../Items/Animal.hpp"
#include "../Items/Plant.hpp"
#include "../Items/Product.hpp"

using namespace std;

class ReadConfig
{
private:
    Misc misc;
    vector<Animal> animal;
    vector<Plant> plant;
    vector<Recipe> recipe;
    vector<Product> product;

public:
    ReadConfig();
    ReadConfig(string pathName);
    void readMisc(string filename);
    void readAnimal(string filename);
    void readPlant(string filename);
    void readRecipe(string filename);
    void readProduct(string filename);

    Misc getMisc() const;
    vector<Animal> getAnimal() const;
    vector<Plant> getPlant() const;
    vector<Recipe> getRecipe() const;
    vector<Product> getProduct() const;
    Item *createItem(string itemName) const;
    Plant createItemPlant(string itemName) const;

    vector<Item *> getPlantPointer() const;
    vector<Item *> getAnimalPointer() const;
};

#endif