#include "Inventory.hpp"
#include <iostream>
// #include <iomanip>

Inventory::Inventory(int rows, char cols) : MatrixMap<Product>(rows, cols) {}

int Inventory::getJenisTiapItem(string c) const
{
    int count = 0;
    for (int i = 1; i <= MatrixMap<Product>::getRows(); i++)
    {
        for (char j = 'A'; j <= MatrixMap<Product>::getCols(); j++)
        {
            if (MatrixMap<Product>::isExist(i, j) && MatrixMap<Product>::getValue(i, j).getCode() == c)
            {
                count++;
            }
        }
    }
    return count;
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

    // int width = charToInt(items.getCols()) * 4 + 4;9009
    // int awal = (width / 2) - 8;
    // cout << "    ";
    // cout << setw(awal) << setfill('=') << "";
    // cout << "[ Penyimpanan ]";
    // cout << setw(awal) << setfill('=') << "" << endl;
    cout << "================[ Penyimpanan ]==================" << endl;
    print();
}