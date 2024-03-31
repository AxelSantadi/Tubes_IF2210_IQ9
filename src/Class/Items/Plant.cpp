#include "Plant.hpp"

Plant::Plant(int id, const std::string &code, const std::string &name, string type, int harvest_duration, int price) : Item(id, code, name, price)
{
    this->type = type;
    this->harvest_duration = harvest_duration;
}

int Plant::getId() const
{
    return id;
}

std::string Plant::getCode() const
{
    return code;
}

std::string Plant::getName() const
{
    return name;
}

string Plant::getType() const
{
    return type;
}

int Plant::getHarvestDuration() const
{
    return harvest_duration;
}

ostream& operator<<(ostream& os, const Plant& p){
    os << p.getCode();
    return os;
} 

MaterialPlant::MaterialPlant(int id, const std::string &code, const std::string &name, string type, int harvest_duration, int price) : Plant(id, code, name, type, harvest_duration, price)
{
    type = "Material_plant";
}

void MaterialPlant::setharvest_duration(int harvest_duration)
{
    harvest_duration = harvest_duration;
}

FruitPlant::FruitPlant(int id, const std::string &code, const std::string &name, string type, int harvest_duration, int price) : Plant(id, code, name, type, harvest_duration, price)
{
    type = "Fruit_plant";
}

void FruitPlant::setharvest_duration(int harvest_duration)
{
    harvest_duration = harvest_duration;
}
