#include "Toko.hpp"

Toko::Toko(const ReadConfig &config)
{
    for (const auto &animal : config.getAnimalPointer())
    {
        addItemToko(animal);
    }
    for (const auto &plant : config.getPlantPointer())
    {
        addItemToko(plant);
    }
}

void Toko::saveStatetoko(ofstream &file)
{
    file << countItemNotInfinity() << endl;
    for (const auto &pair : items)
    {
        if (pair.second.second != -1)
        {
            file << pair.first << " " << pair.second.second << endl;
        }
    }
}

void Toko::addItemToko(Item *item)
{
    auto it = items.find(item->getName());
    if (it == items.end())
    {
        items[item->getName()] = make_pair(item, item->isUnlimited() ? -1 : 1);
    }
    else if (!item->isUnlimited())
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
            if (!it->second.first->isUnlimited())
            {
                items.erase(it);
            }
        }
    }

    else
    {
        throw ItemNotFoundException();
    }
}

int Toko::getItemPrice(const std::string &itemName) const
{
    auto it = items.find(itemName);
    if (it == items.end())
    {
        throw ItemNotFoundException();
    }
    return it->second.first->getPrice();
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
        throw ItemNotFoundException();
    }
}

Item *Toko::getItemToko(const std::string &itemName) const
{
    auto it = items.find(itemName);
    if (it != items.end())
    {
        return it->second.first;
    }
    else
    {
        throw ItemNotFoundException();
    }
}

string Toko::getItemNameByNumber(int number) const
{
    int counter = 1;

    if (number < 1 || number > static_cast<int>(items.size()))
    {
        throw NumberOutOfRangeException();
    }

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

int Toko::countItemNotInfinity() const
{
    int counter = 0;
    for (const auto &pair : items)
    {
        if (pair.second.second != -1)
        {
            counter++;
        }
    }
    return counter;
}

void Toko::displayToko() const
{
    int counter = 1;
    std::cout << "Selamat datang di toko!!" << endl
              << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    for (const auto &pair : items)
    {
        std::cout << counter << ". " << pair.first << " - " << pair.second.first->getPrice();
        if (pair.second.second != -1)
        {
            std::cout << " (" << pair.second.second << ")";
        }
        std::cout << std::endl;
        counter++;
    }
}

Toko::~Toko()
{
    for (auto &pair : items)
    {
        delete pair.second.first;
    }
}