#include "Plant.hpp"

int Plant::numOfPlant = 0;

Plant::Plant() : Item()
{
    type = "";
    harvest_duration = 0;

    Plant::numOfPlant++;
}

Plant::Plant (int id, string code, string name, string type, int harvest_duration, int price) : Item(id, code, name, price)
{
    this->type = type;
    this->harvest_duration = harvest_duration;
    this->umur = 0; 

    Plant::numOfPlant++;
}

Plant::Plant(const Plant &p) : Item(p.id, p.code, p.name, p.price)
{
    this->type = p.type;
    this->harvest_duration = p.harvest_duration;

    Plant::numOfPlant++;
}

Plant::~Plant()
{
    Plant::numOfPlant--;
}

string Plant::getType() const
{
    return type;
}

void Plant::setType(string t)
{
    type = t;
}

int Plant::getHarvestDuration() const
{
    return harvest_duration;
}

void Plant::setHarvestDuration(int h)
{
    harvest_duration = h;
}

int Plant::getUmur() const 
{
    return umur;
}

void Plant::setUmur(int h)
{
    umur = h;
}

int Plant::getAddedWeight() const { return 0; }

Plant &Plant::operator=(const Plant &p)
{
    this->id = p.id;
    this->code = p.code;
    this->name = p.name;
    this->type = p.type;
    this->harvest_duration = p.harvest_duration;
    this->price = p.price;

    return *this;
}

Plant &Plant::operator+=(int x)
{
    this->harvest_duration += x;
    return *this;
}

Plant &Plant::operator-=(int x)
{
    this->harvest_duration -= x;
    return *this;
}

Plant &Plant::operator+=(const Plant &p)
{
    this->harvest_duration += p.harvest_duration;
    return *this;
}

Plant &Plant::operator-=(const Plant &p)
{
    this->harvest_duration -= p.harvest_duration;
    return *this;
}

void Plant::input(istream &is)
{
    Item::input(is);
    cout << "Type: ";
    is >> type;
    cout << "Harvest Duration: ";
    is >> harvest_duration;
}

void Plant::output(ostream &os)
{
    Item::output(os);
    os << "Type: " << type << endl;
    os << "Harvest Duration: " << harvest_duration << endl;
}

ostream& operator<<(ostream &os, const Plant &p)
{
    os << p.code;
    return os;
}


bool Plant::isUnlimited() const { return true;}

bool Plant::isMakanan() const { return false;}

// Material Plant
MaterialPlant::MaterialPlant(int id, const std::string &code, const std::string &name, string type, int harvest_duration, int price,int umur) : Plant(id, code, name, type, harvest_duration, price)
{
    type = "Material_plant";
}

FruitPlant::FruitPlant(int id, const std::string &code, const std::string &name, string type, int harvest_duration, int price, int umur) : Plant(id, code, name, type, harvest_duration, price)
{
    type = "Fruit_plant";
}