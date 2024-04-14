#include "../Walikota.hpp"
#include "../Walikota.cpp"

// Item
#include "../../Items/Item.hpp"
#include "../../Items/Item.cpp"

#include "../../Items/Plant.hpp"
#include "../../Items/Plant.cpp"

#include "../../Items/Animal.hpp"
#include "../../Items/Animal.cpp"

#include "../../Items/Product.hpp"
#include "../../Items/Product.cpp"

#include "../../Items/Bangunan.hpp"
#include "../../Items/Bangunan.cpp"

// Player
#include "../Player.hpp"
#include "../Player.cpp"

#include "../Petani.hpp"
#include "../Petani.cpp"

#include "../Peternak.hpp"
#include "../Peternak.cpp"

// Config
#include "../../Data/Exception.hpp"
#include "../../Data/Exception.cpp"

#include "../../Data/ReadConfig.hpp"
#include "../../Data/ReadConfig.cpp"

#include "../../Data/Misc.hpp"
#include "../../Data/Misc.cpp"

#include "../../Data/Recipe.hpp"
#include "../../Data/Recipe.cpp"

// Per map an
#include "../MatrixMap.hpp"

#include "../Inventory.hpp"
#include "../Inventory.cpp"

#include "../Kandang.hpp"
#include "../Kandang.cpp"

#include "../ladang.hpp"
#include "../ladang.cpp"

// Toko
#include "../Toko.hpp"
#include "../Toko.cpp"

int main()
{
    Player *walikota = new Walikota("John Doe", 5, 'M', 5000, 50);
    walikota->getInventory().printInventory();

    Inventory inv(3, 'C');

    Item* i = new Animal(1, "ITM", "Item", "MATERIAL", 10, 1000);
    inv = inv + i;
    inv += new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000);
    inv += new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000);
    inv += new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000);
    inv.printInventory();

    walikota->getInventoryPointer() += new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000);
    walikota->getInventoryPointer() += new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000);
    walikota->getInventoryPointer().printInventory();
    
    walikota->getInventoryPointer() = walikota->getInventoryPointer() + new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000);
    walikota->getInventoryPointer().printInventory();

    cout << inv.getData().size() << endl;
    for(auto i : inv.getData())
    {
        cout << i.first.first << i.first.second << " " << i.second->getName() << endl;
    }

    return 0;
}