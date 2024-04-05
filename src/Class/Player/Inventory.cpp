#include "Inventory.hpp"
#include <iostream>

Inventory::Inventory(int rows, char cols) : MatrixMap<Item*>(rows, cols) {}

int Inventory::getJenisTiapItem(string c) const
{
    int count = 0;
    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j) && getValue(i, j)->getCode() == c)
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
    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j) && getValue(i, j)->getName() == c)
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
    // cout << "Total slot kosong : " << countEmpty() << endl;
}

bool Inventory::noFood() const
{
    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j) && getValue(i, j)->isMakanan())
            {
                return false;
            }
        }
    }
    return true;
}

void Inventory::storeItemInSlot(Item* item, const std::string &slot)
{
    // Convert the slot string to row and column
    int row = std::stoi(slot.substr(1)); // No need to subtract 1 here
    char col = slot[0]; // Keep this as a char

    // Store the item in the specified slot
    this->setValue(row, col, item);

    std::cout << item->getName() << " berhasil disimpan dalam penyimpanan!" << std::endl;
}