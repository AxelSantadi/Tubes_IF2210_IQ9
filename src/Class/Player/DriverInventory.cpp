#include "Inventory.hpp"
#include "Inventory.cpp"
#include "MatrixMap.cpp"
#include "../Items/Item.cpp"
#include "../Items/Animal.cpp"
#include "../Items/Plant.cpp"
#include "../Items/Product.cpp"
#include "../Data/Exception.cpp"
#include "Player.cpp"
#include "../Data/Misc.cpp"
#include "Toko.cpp"

int main()
{
    Player player("Jokowi", 3, 'C');
    player.getInventory().printInventory();

    Inventory inv(3, 'C');

    Item* i = new Animal(1, "ITM", "Item", "MATERIAL", 10, 1000);
    inv.setValue(1, 'B', i);
    inv.setValue(1, 'A', new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000));
    inv.setValue(2, 'B', new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000));
    inv.setValue(3, 'C', new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000));

    player.getInventory().setValue(1, 'A', new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000));
    player.getInventory().setValue(1, 'B', new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000));
    player.getInventory().setValue(1, 'C', new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000));
    player.getInventory().printInventory();

    cout << inv.getData().size() << endl;
    for(auto i : inv.getData())
    {
        cout << i.first.first << i.first.second << " " << i.second->getName() << endl;
    }

    return 0;
}