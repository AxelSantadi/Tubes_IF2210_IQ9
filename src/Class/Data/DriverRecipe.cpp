#include <vector>

#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Animal.hpp"
#include "../Items/Animal.cpp"

#include "../Items/Product.hpp"
#include "../Items/Product.cpp"

#include "../Items/Bangunan.hpp"
#include "../Items/Bangunan.cpp"

#include "../Player/MatrixMap.hpp"
#include "../Player/MatrixMap.cpp"

#include "ReadConfig.hpp"
#include "ReadConfig.cpp"

#include "Misc.hpp"
#include "Misc.cpp"

#include "Recipe.hpp"
#include "Recipe.cpp"

#include "Exception.hpp"
#include "Exception.cpp"

#include "../Player/Inventory.hpp"
#include "../Player/Inventory.cpp"

#include <iostream>

int main() {
    // Create a ReadConfig object
    ReadConfig config("config1");

    // Get the list of recipes
    std::vector<Recipe> recipes = config.getRecipe();

    // Print each recipe
    for (int i = 0; i < recipes.size(); i++) {
        recipes[i].printBangunan(i+1);
    }

    string p = "SMALL_HOUSE";
    for (int i = 0; i < recipes.size(); i++) {
        if(recipes[i].cekResep(p)){
            cout << "Resep " << p << " ada di resep ke-" << i+1 << endl;
        }
    }
    
    return 0;
}