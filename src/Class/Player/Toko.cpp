#include "Toko.hpp"

// Add an item to the inventory
void Toko::addItemToko(const Item &item)
{
    items.push_back(item);
}

// Remove an item from the inventory
void Toko::removeItemToko(int index)
{
    items.erase(items.begin() + index);
}

// Get an item from the inventory
Item Toko::getItemToko(int index) const
{
    return items[index];
}

// Get the size of the inventory
int Toko::getSizeToko() const
{
    return items.size();
}

void Toko::displayToko() const
{
    cout << "Selamat datang di toko!!" << endl
         << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    for (int i = 0; i < items.size(); i++)
    {
        cout << i + 1 << ". " << getItemToko(i).getName() << " - " << getItemToko(i).getPrice() << endl;
    }
    
}
