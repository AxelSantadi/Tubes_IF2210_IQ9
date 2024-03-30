#include "Plant.hpp"

Plant::Plant(int id, const std::string& code, const std::string& name, PlantType type, int harvest_duration, int price) : Product(id, code, name, PRODUCT_MATERIAL_PLANT, "", 0, price) {
    this->type = type;
    this->harvest_duration = harvest_duration;
}

int Plant::getId() const {
    return Product::getId();
}

std::string Plant::getCode() const {
    return Product::getCode();
}

std::string Plant::getName() const {
    return Product::getName();
}

PlantType Plant::getType() const {
    return type;
}

int Plant::getHarvestDuration() const {
    return harvest_duration;
}

