#include "Toko.hpp"
#include "Toko.cpp"

#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Animal.hpp"
#include "../Items/Animal.cpp"

#include "Player.hpp"
#include "Player.cpp"

#include "Inventory.hpp"
#include "Inventory.cpp"

#include "MatrixMap.hpp"
#include "MatrixMap.cpp"

int main()
{
    // Create some Item, Plant, and Animal objects
    Plant plant1(3, "code3", "plant1", "type1", 10, 5);
    Plant plant2(4, "code4", "plant2", "type2", 20, 5);
    Cow cow1(5, "code5", "cow1", 30, 5);
    Sheep sheep1(6, "code6", "sheep1", 40, 5);

    // Create a vector of Animal and Plant objects
    std::vector<Animal> animals = {cow1, sheep1};
    std::vector<Plant> plants = {plant1, plant2};

    // Create a Toko object
    Toko toko(animals, plants);

    // Add the Item objects to the Toko
    toko.addItemToko(plant1);
    toko.addItemToko(plant2);
    toko.addItemToko(cow1);
    toko.addItemToko(sheep1);

    // Create an Inventory object
    Inventory inventory(3, 'A');

    // Create a Player object
    Player petani("Player1", DEFAULT_WEIGHT, DEFAULT_MONEY); // Player starts with default weight and money

    // Set the player's inventory
    petani.setInventory(inventory);

    // Call the buyItem function
    petani.buyItem(toko);

    petani.getInventory().printInventory();

    return 0;
}