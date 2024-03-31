#include "Inventory.hpp"
#include <iostream>

Inventory::Inventory(int rows, char cols) : MatrixMap<Item>(rows, cols) {}

int Inventory::getJenisTiapItem(string c) const
{
    int count = 0;
    for (int i = 1; i <= MatrixMap<Item>::getRows(); i++)
    {
        for (char j = 'A'; j <= MatrixMap<Item>::getCols(); j++)
        {
            if (MatrixMap<Item>::isExist(i, j) && MatrixMap<Item>::getValue(i, j).getCode() == c)
            {
                count++;
            }
        }
    }
    return count;
}

int Inventory::getJenisTiapItemNama(string c) const
{
    int count = 0;
    for (int i = 1; i <= MatrixMap<Item>::getRows(); i++)
    {
        for (char j = 'A'; j <= MatrixMap<Item>::getCols(); j++)
        {
            if (MatrixMap<Item>::isExist(i, j) && MatrixMap<Item>::getValue(i, j).getName() == c)
            {
                count++;
            }
        }
    }
    return count;
}


void Inventory::printInventory() const
{
    cout << "================[ Penyimpanan ]==================" << endl;
    print();
    cout << endl << endl;
    cout << "Total slot kosong : " << countEmpty() << endl;
}