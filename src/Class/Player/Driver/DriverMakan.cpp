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

#include "../Items/Product.hpp"
#include "../Items/Product.cpp"

#include "MatrixMap.hpp"

#include "../Data/Exception.cpp"
int main()
{
    Plant* plant1 = new Plant(3, "PL1", "plant1", "type1", 10, 5);
    Plant* plant2 = new Plant(4, "PL2", "plant2", "type2", 20, 5);
    Cow* cow1 = new Cow(5, "COW", "cow1", 30, 5);
    Sheep* sheep1 =  new Sheep(6, "SHP", "sheep1", 40, 5);
    Product* product1 = new Product(7, "MAK", "product1","","" , 50, 5);

    Player p("Player 1", 3, 'D');
    p.addItem(plant1, 1,'A');
    p.addItem(plant2, 1,'B');
    p.addItem(cow1, 2,'A');
    p.addItem(sheep1, 2,'B');
    p.addItem(product1, 3,'A');
    p.getInventory().printInventory();

    p.makan();
    p.getInventory().printInventory();

    return 0;
}