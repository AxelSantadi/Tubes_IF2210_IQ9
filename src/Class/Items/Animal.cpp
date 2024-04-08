#include "Animal.hpp"

int Animal::numOfAnimal = 0;

Animal::Animal() : Item()
{
    this->type = "";
    this->weightToHarvest = 0;

    Animal::numOfAnimal++;
}

Animal::Animal(int id, string code, string name, string type, int weightToHarvest, int price) : Item(id, code, name, price)
{
    this->type = type;
    this->weightToHarvest = weightToHarvest;
    this->berat = 0;

    Animal::numOfAnimal++;
}

Animal::Animal(const Animal &a) : Item(a.id, a.code, a.name, a.price)
{
    this->type = a.type;
    this->weightToHarvest = a.weightToHarvest;

    Animal::numOfAnimal++;
}

Animal::~Animal()
{
    Animal::numOfAnimal--;
}

string Animal::getType() const
{
    return type;
}

void Animal::setType(string t)
{
    type = t;
}

int Animal::getWeightToHarvest() const
{
    return weightToHarvest;
}

void Animal::setWeightToHarvest(int w)
{
    weightToHarvest = w;
}

int Animal::getBerat() const
{
    return berat;
}

void Animal::setBerat(int b)
{
    berat = b;
}


int Animal::getAddedWeight() const { return 0; }

Animal &Animal::operator=(const Animal &a)
{
    Item::operator=(a);
    this->type = a.type;
    this->weightToHarvest = a.weightToHarvest;
    return *this;
}

Animal &Animal::operator+=(int x)
{
    this->weightToHarvest += x;
    return *this;
}

Animal &Animal::operator-=(int x)
{
    this->weightToHarvest -= x;
    return *this;
}

Animal &Animal::operator+=(const Animal &a)
{
    this->weightToHarvest += a.weightToHarvest;
    return *this;
}

Animal &Animal::operator-=(const Animal &a)
{
    this->weightToHarvest -= a.weightToHarvest;
    return *this;
}

void Animal::input(istream &is)
{
    Item::input(is);
    cout << "Type: ";
    is >> type;
    cout << "Weight to Harvest: ";
    is >> weightToHarvest;
}

void Animal::output(ostream &os)
{
    Item::output(os);
    os << "Type: " << type << endl;
    os << "Weight to Harvest: " << weightToHarvest << endl;
}

ostream& operator<<(ostream &os, const Animal &p)
{
    os << p.getCode();
    return os;
}

string Animal::operator*() const
{
    return code;
}

void Animal::display()
{
    Item::display();
    cout << "Type: " << this->type << endl;
    cout << "Weight to Harvest: " << this->weightToHarvest << endl;
}

bool Animal::isUnlimited() const { return true; }

bool Animal::isMakanan() const { return false; }

Herbivore::Herbivore(int id, string code, string name, int weightToHarvest, int price) : Animal(id, code, name, "HERBIVORE", weightToHarvest, price) {}

Carnivore::Carnivore(int id, string code, string name, int weightToHarvest, int price) : Animal(id, code, name, "CARNIVORE", weightToHarvest, price) {}

Omnivore::Omnivore(int id, string code, string name, int weightToHarvest, int price) : Animal(id, code, name, "OMNIVORE", weightToHarvest, price) {}