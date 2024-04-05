#include "Toko.hpp"
#include "Toko.cpp"

#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Animal.hpp"
#include "../Items/Animal.cpp"

#include "../Items/Product.hpp"
#include "../Items/Product.cpp"

#include "Player.hpp"
#include "Player.cpp"

#include "Inventory.hpp"
#include "Inventory.cpp"

#include "MatrixMap.hpp"
#include "MatrixMap.cpp"

#include "../Data/Exception.hpp"
#include "../Data/Exception.cpp"

int main()
{
    // Create some Item, Plant, and Animal objects
    Plant* plant1 = new Plant(3, "code3", "plant1", "type1", 10, 5);
    Plant* plant2 = new Plant(4, "code4", "plant2", "type2", 20, 5);
    Cow* cow1 = new Cow(5, "code5", "cow1", 30, 5);
    Sheep* sheep1 = new Sheep(6, "code6", "sheep1", 40, 5);

    // Create a vector of Animal and Plant pointers
    std::vector<Animal*> animals = {cow1, sheep1};
    std::vector<Plant*> plants = {plant1, plant2};

    // Create a Toko object
    Toko toko(animals, plants);

    // Create an Inventory object
    Inventory inventory(3, 'A');
    
    // Create a Player object
    Player petani("Player1", DEFAULT_WEIGHT, DEFAULT_MONEY); // Player starts with default weight and money
    Product* product1 = new Product(7, "MAK", "product1","","" , 50, 5);


    // Set the player's inventory
    petani.setInventory(inventory);
    petani.addItem(product1, 1, 'A');

    // Call the buyItem function
    petani.buyItem(toko);

    // Call the sellItem function
    petani.sellItem(toko);

    petani.getInventory().printInventory();

    toko.displayToko();

    // Don't forget to delete the dynamically allocated objects
    delete plant1;
    delete plant2;
    delete cow1;
    delete sheep1;

    return 0;
}