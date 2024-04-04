#include "Toko.hpp"

Toko::Toko(const vector<Animal> &animals, const vector<Plant> &plants)
    : animals(animals), plants(plants)
{
    for (const auto &animal : animals)
    {
        addItemToko(animal);
    }
    for (const auto &plant : plants)
    {
        addItemToko(plant);
    }
}

void Toko::addItemToko(const Item &item)
{
    auto it = items.find(item.getName());
    if (it == items.end())
    {
        items[item.getName()] = make_pair(item, item.isUnlimited() ? -1 : 1);
    }
    else if (!item.isUnlimited())
    {
        it->second.second++;
    }
}

void Toko::removeItemToko(const string &itemName)
{
    auto it = items.find(itemName);
    if (it != items.end())
    {
        if (it->second.second > 1)
        {
            it->second.second--;
        }
        else
        {
            if (!it->second.first.isUnlimited())
            {
                items.erase(it);
            }
        }
    }
}

int Toko::getItemPrice(const std::string &itemName) const
{
    auto it = items.find(itemName);
    if (it != items.end())
    {
        return it->second.first.getPrice();
    }
    else
    {
        return -1;
    }
}

int Toko::getItemQuantity(const std::string &itemName) const
{
    auto it = items.find(itemName);
    if (it != items.end())
    {
        return it->second.second;
    }
    else
    {
        return -1;
    }
}

Item Toko::getItemToko(const std::string &itemName) const
{
    auto it = items.find(itemName);
    if (it != items.end())
    {
        return it->second.first;
    }
    else
    {
        return Item();
    }
}

string Toko::getItemNameByNumber(int number) const
{
    int counter = 1;
    for (const auto &pair : items)
    {
        if (counter == number)
        {
            return pair.first;
        }
        counter++;
    }
    return "";
}

void Toko::displayToko() const
{
    int counter = 1;
    std::cout << "Selamat datang di toko!!" << endl
              << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    for (const auto &pair : items)
    {
        std::cout << counter << ". " << pair.first << " - " << pair.second.first.getPrice();
        if (pair.second.second != -1)
        {
            std::cout << " (" << pair.second.second << ")";
        }
        std::cout << std::endl;
        counter++;
    }
}