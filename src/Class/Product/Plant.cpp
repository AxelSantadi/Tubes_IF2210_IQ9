#include "Plant.hpp"

Plant::Plant(int id, const std::string& code, const std::string& name, string type, int harvest_duration, int price){
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
    this->harvest_duration = harvest_duration;
    this->price = price;
}

int Plant::getId() const {
    return id;
}

std::string Plant::getCode() const {
    return code;
}

std::string Plant::getName() const {
    return name;
}

string Plant::getType() const {
    return type;
}

int Plant::getHarvestDuration() const {
    return harvest_duration;
}

ostream& operator<<(ostream& os, const Plant& plant) {
    os << plant.getCode();
    return os;
}