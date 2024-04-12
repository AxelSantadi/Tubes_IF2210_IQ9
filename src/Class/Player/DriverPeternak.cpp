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
#include "MatrixMap.cpp"

#include "Inventory.hpp"
#include "Inventory.cpp"

#include "Kandang.hpp"
#include "Kandang.cpp"

#include "ladang.hpp"
#include "ladang.cpp"

// Toko
#include "Toko.hpp"
#include "Toko.cpp"

int main(){
    ReadConfig readConfig("config1");

    vector<Product> iventory =  readConfig.getProduct();
    Item * animal1 = new Animal(1, "COW", "Cow", "HERBIVORE", 100, 1000);
    Item * animal2 = new Animal(2, "COW", "Cow", "HERBIVORE", 100, 1000);
    Item * animal3 = new Animal(3, "COW", "Cow", "HERBIVORE", 100, 3000);
    Item * animal4 = new Animal(4, "CHK", "Chicken", "OMNIVORE", 100, 500);
    Item * animal5 = new Animal(5, "SHP", "Sheep", "OMNIVORE", 10, 750);
    Item * product1 = new Product(6, "SHM", "SHEEP_MEAT", "PRODUCT_ANIMAL", "SHEEP", 15, 1000);
    Item * product2 = new Product(7, "TAW", "TEAK_WOOD", "PRODUCT_MATERIAL_PLANT", "SANDALWOOD_TREE", 3, 1000);
    Item * product3 = new Product(8, "CHE", "CHICKEN_EGG", "PRODUCT_ANIMAL", "CHICKEN", 20, 1000);
    Item * product4 = new Product(9, "ALW", "ALOE_WOOD", "PRODUCT_MATERIAL_PLANT", "ALOE_TREE", 20, 1000);



    Player * player1 = new Peternak("Jokowi", 5, 'F',5,'F');

    player1->addItem(animal1, 1, 'A');
    player1->addItem(animal2, 1, 'B');
    player1->addItem(animal3, 1, 'C');
    player1->addItem(animal4, 2, 'A');
    player1->addItem(animal5, 2, 'B');
    player1->addItem(product1, 4, 'A');
    player1->addItem(product2, 4, 'B');
    player1->addItem(product3, 4, 'C');
    player1->addItem(product4, 4, 'D');


    player1->ternak();
    Peternak * player2 = dynamic_cast<Peternak*>(player1);
    Animal p = player2->getKandang().getValue(1,'A');
    Animal p2 = player2->getKandang().getValue(1,'B');
    cout << p.getBerat() << endl;
    cout << p2.getBerat() << endl;
    cout << p.getWeightToHarvest() << endl;
    player1->ternak();
    // player1->feedTernak();
    Animal p1 = player2->getKandang().getValue(1,'A');
    Animal p3 = player2->getKandang().getValue(1,'B');
    cout << p1.getBerat() << endl;
    cout << p3.getBerat() << endl;
    player1->panenTernak(iventory);
    player1->getInventory().printInventory();
    player2->getKandang().cetakKandang();
}


