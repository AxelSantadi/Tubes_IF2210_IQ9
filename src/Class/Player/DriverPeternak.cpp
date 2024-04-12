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
    Item * animal1 = new Animal(1, "COW", "Cow", "HERBIVORE", 100000000000, 1000);
    Item * animal2 = new Animal(2, "COW", "Cow", "HERBIVORE", 100000000000, 1000);
    Item * animal3 = new Animal(3, "COW", "Cow", "HERBIVORE", 100, 3000);
    Item * animal4 = new Animal(4, "CHK", "Chicken", "OMNIVORE", 100, 500);
    Item * animal5 = new Animal(5, "SHP", "Sheep", "OMNIVORE", 10, 750);
    Item * product1 = new Product(6, "SHM", "SHEEP_MEAT", "PRODUCT_ANIMAL", "SHEEP", 15, 1000);
    Item * product2 = new Product(7, "TAW", "TEAK_WOOD", "PRODUCT_MATERIAL_PLANT", "SANDALWOOD_TREE", 3, 1000);
    Item * product3 = new Product(8, "CHE", "CHICKEN_EGG", "PRODUCT_ANIMAL", "CHICKEN", 20, 1000);
    Item * product4 = new Product(9, "ALW", "ALOE_WOOD", "PRODUCT_MATERIAL_PLANT", "ALOE_TREE", 20, 1000);



    Player * peternak = new Peternak("Jokowi", 5, 'F',5,'F');

    peternak->addItem(animal1, 1, 'A');
    peternak->addItem(animal2, 1, 'B');
    peternak->addItem(animal3, 1, 'C');
    peternak->addItem(animal4, 2, 'A');
    peternak->addItem(animal5, 2, 'B');
    peternak->addItem(product1, 4, 'A');
    peternak->addItem(product2, 4, 'B');
    peternak->addItem(product3, 4, 'C');
    peternak->addItem(product4, 4, 'D');


    peternak->ternak();
    Peternak * p = dynamic_cast<Peternak*>(peternak);
    Animal p1 = p->getKandang().getValue(1,'A');
    cout << "Berat : " << p1.getBerat() << endl;
    cout <<"Weight to harvest : " << p1.getWeightToHarvest() << endl;
    // peternak->ternak();
    peternak->feedTernak();
    Animal p2 = p->getKandang().getValue(1,'A');
    cout << "Berat : " << p2.getBerat() << endl;
    peternak->panenTernak(iventory);
    peternak->getInventory().printInventory();
    p->getKandang().cetakKandang();
}


