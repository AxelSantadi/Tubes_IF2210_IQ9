#include "Inventory.hpp"
#include "Inventory.cpp"
#include "MatrixMap.cpp"
#include "../Items/Item.cpp"
#include "../Items/Animal.cpp"
#include "../Items/Plant.cpp"
#include "../Items/Product.cpp"

int main()
{
    Inventory inv(3, 'C');
    inv.printInventory();
    inv.setValue(1, 'A', new Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000));
    inv.setValue(2, 'B', new Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000));
    inv.setValue(3, 'C', new Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000));
    inv.printInventory();
    return 0;
}