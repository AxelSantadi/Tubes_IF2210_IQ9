#include "Inventory.hpp"
#include <iostream>
#include <iomanip>

Inventory::Inventory(int rows, char cols) : items(rows, cols) {}

Product Inventory::getItem(int i, char j) const
{
    return items.getValue(i, j);
}

void Inventory::setItem(int i, char j, Product item)
{
    items.setValue(i, j, item);
}

// int charToInt(char c)
// {
//     if (c >= 'a' && c <= 'z')
//     {
//         return c - 'a' + 1;
//     }
//     else if (c >= 'A' && c <= 'Z')
//     {
//         return c - 'A' + 1;
//     }
//     else
//     {
//         return -1;
//     }
// }

void Inventory::printInventory() const
{

    // int width = charToInt(items.getCols()) * 4 + 4;
    // int awal = (width / 2) - 8;
    // cout << "    ";
    // cout << setw(awal) << setfill('=') << "";
    // cout << "[ Penyimpanan ]";
    // cout << setw(awal) << setfill('=') << "" << endl;
    cout << "================[ Penyimpanan ]==================" << endl;
    items.print();
}