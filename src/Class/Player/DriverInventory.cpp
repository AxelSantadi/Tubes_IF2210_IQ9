#include "Inventory.hpp"
#include "Inventory.cpp"
  
int main()
{
    Inventory inv(3, 'C');
    inv.printInventory();
    inv.setValue(1, 'A', Animal(1, "ANI", "Ayam", "HERBIVORE", 10, 1000));
    inv.setValue(2, 'B', Plant(1, "PLA", "Anggrek", "MATERIAL_PLANT", 10, 1000));
    inv.setValue(3, 'C', Product(1, "PRO", "Pisang", "MATERIAL_PRODUCT", "Indonesia", 10, 1000));
    inv.printInventory();
    return 0;
}