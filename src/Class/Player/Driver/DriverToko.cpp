#include "Walikota.hpp"
#include "Walikota.cpp"

// Item
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

// Player
#include "Player.hpp"
#include "Player.cpp"

#include "Petani.hpp"
#include "Petani.cpp"

#include "Peternak.hpp"
#include "Peternak.cpp"

// Config
#include "../Data/Exception.hpp"
#include "../Data/Exception.cpp"

#include "../Data/ReadConfig.hpp"
#include "../Data/ReadConfig.cpp"

#include "../Data/Misc.hpp"
#include "../Data/Misc.cpp"

#include "../Data/Recipe.hpp"
#include "../Data/Recipe.cpp"

// Per map an
#include "MatrixMap.hpp"

#include "Inventory.hpp"
#include "Inventory.cpp"

#include "Kandang.hpp"
#include "Kandang.cpp"

#include "ladang.hpp"
#include "ladang.cpp"

// Toko
#include "Toko.hpp"
#include "Toko.cpp"

using namespace std;

// very gud verry well kumaha toko? well
int main()
{
    // Baca Config
    ReadConfig config("config1");

    // Bikin Toko
    Toko toko(config);

    // Percobaan membuat item
    Item* product1 = new Product(1, "code1", "product1", "type1", "origin1", 10, 100);
    Item* product2 = new Product(2, "code2", "product2", "type2", "origin2", 20, 200);
    Item* productbaru = new Bangunan(6,"KON","Rumah Mantap",250);

    // Masukin item ke toko
    toko.addItemToko(product1);
    toko.addItemToko(product2);
    toko.addItemToko(productbaru);

    // Membuat player sama inventory
    Inventory inventory(3, 'A');
    Player *petani = new Petani("John Doe", 5, 'M', 5000, 1000, 5, 'A');
    petani->setInventory(inventory);

    // Pengen beli dong
    petani->buyItem(toko);

    // Pengen jual di shopee
    petani->sellItem(toko);

    petani->getInventory().printInventory();

    // Display the items in the toko
    toko.displayToko();

    // Clean up
    delete product1;
    delete product2;

    return 0;
}