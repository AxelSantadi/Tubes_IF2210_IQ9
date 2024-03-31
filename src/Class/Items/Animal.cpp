#include "Animal.hpp"

Animal::Animal(int id, const std::string& code, const std::string& name, const std::string& type, int weightToHarvest, int price)
    : id(id), code(code), name(name), type(type), weightToHarvest(weightToHarvest), price(price) {}

int Animal::getId() const {
    return id;
}

std::string Animal::getCode() const {
    return code;
}

std::string Animal::getName() const {
    return name;
}

std::string Animal::getType() const {
    return type;
}

int Animal::getWeightToHarvest() const {
    return weightToHarvest;
}

int Animal::getPrice() const {
    return price;
}
