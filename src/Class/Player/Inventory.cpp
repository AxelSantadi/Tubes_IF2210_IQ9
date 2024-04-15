#include "Inventory.hpp"
#include <iostream>

Inventory::Inventory(int rows, char cols) : MatrixMap<Item *>(rows, cols) {}

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

void Inventory::setValue(int x, char c, Item *value)
{

    if (x <= 0 || x > rows || c > cols || c < 'A')
    {
        throw outOfBoundException();
    }
    else if (isFull())
    {
        throw penyimpananPenuhExeption();
    }

    else if (isExist(x, c))
    {
        throw slotTerisiException();
    }

    else
    {
        data[{x, c}] = value;
    }
}

void Inventory::removeValue(int x, char c)
{
    try
    {
        if (x <= 0 || x > rows || c > cols || c < 'A')
        {
            throw outOfBoundException();
        }
        else if (!isExist(x, c))
        {
            throw EmptyInventoryException();
        }
        else
        {
            data.erase({x, c});
        }
    }
    catch (outOfBoundException &e)
    {
        cerr << e.what() << endl
             << endl;
    }
    catch (EmptyInventoryException &e)
    {
        cerr << e.what() << endl
             << endl;
    }
}

void Inventory::setRandomValue(Item *item)
{
    try
    {
        if (isFull())
        {
            throw penyimpananPenuhExeption();
        }
        else
        {
            for (int i = 1; i <= getRows(); i++)
            {
                for (char j = 'A'; j <= getCols(); j++)
                {
                    if (!isExist(i, j))
                    {
                        setValue(i, j, item);
                        return;
                    }
                }
            }
        }
    }
    catch (penyimpananPenuhExeption &e)
    {
        cerr << e.what() << endl
             << endl;
    }
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
    cout << endl
         << endl;
    cout << "Total slot kosong : " << countEmpty() << endl;
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

bool Inventory::noFoodHerbivore() const
{

    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j))
            {
                if (getValue(i, j)->getCode() == "TAW" ||
                    getValue(i, j)->getCode() == "SAW" ||
                    getValue(i, j)->getCode() == "ALW" ||
                    getValue(i, j)->getCode() == "IRW" ||
                    getValue(i, j)->getCode() == "APP" ||
                    getValue(i, j)->getCode() == "ORP" ||
                    getValue(i, j)->getCode() == "BNP" ||
                    getValue(i, j)->getCode() == "GAP")
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Inventory::noFoodCarnivore() const
{
    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j))
            {
                if (getValue(i, j)->getCode() == "COM" ||
                    getValue(i, j)->getCode() == "SHM" ||
                    getValue(i, j)->getCode() == "HRM" ||
                    getValue(i, j)->getCode() == "RBM" ||
                    getValue(i, j)->getCode() == "SNM" ||
                    getValue(i, j)->getCode() == "CHM" ||
                    getValue(i, j)->getCode() == "DCM" ||
                    getValue(i, j)->getCode() == "CHE" ||
                    getValue(i, j)->getCode() == "DCE")
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Inventory::noPlant() const
{
    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j))
            {
                if (getValue(i, j)->getJenis() == "Plant")
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Inventory::noAnimal() const
{
    for (int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j))
            {
                if (getValue(i, j)->getJenis() == "Animal")
                {
                    return false;
                }
            }
        }
    }
    return true;
}

Inventory &Inventory::operator+(Item *item)
{
    this->setRandomValue(item);
    return *this;
}

Inventory &Inventory::operator+=(Item *item)
{
    this->setRandomValue(item);
    return *this;
}