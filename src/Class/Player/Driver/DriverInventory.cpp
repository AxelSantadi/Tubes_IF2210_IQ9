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
#include "../MatrixMap.cpp"

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
    inv.setValue(1, 'B', i);
    inv.setValue(1, 'A', new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000));
    inv.setValue(2, 'B', new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000));
    inv.setValue(3, 'C', new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000));

    walikota->addItem(new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000),1, 'A' );
    walikota->addItem(new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000),1, 'B' );
    walikota->addItem(new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000),1, 'C');
    walikota->getInventoryPointer().printInventory();

    cout << inv.getData().size() << endl;
    for(auto i : inv.getData())
    {
        cout << i.first.first << i.first.second << " " << i.second->getName() << endl;
    }

    return 0;
}