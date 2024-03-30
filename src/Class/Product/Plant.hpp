#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>
#include "Product.hpp"

using namespace std;

enum PlantType {
    MATERIAL_PLANT,
    FRUIT_PLANT
};

class Plant : public Product{
public:
    Plant(int id, const std::string& code, const std::string& name, PlantType type, int harvest_duration, int price)
        : id(id), code(code), name(name), type(type), harvest_duration(harvest_duration), price(price) {}

    int getId() const { return id; }
    string getCode() const { return code; }
    string getName() const { return name; }
    PlantType getType() const { return type; }
    int getHarvestDuration() const { return harvest_duration; }

private:
    int id;
    std::string code;
    std::string name;
    PlantType type;
    int harvest_duration;
    int price;
};

class MaterialPlant : public Plant {
public:
    MaterialPlant(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : Plant(id, code, name, MATERIAL_PLANT, harvest_duration, price) {}
};

class FruitPlant : public Plant {
public:
    FruitPlant(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : Plant(id, code, name, FRUIT_PLANT, harvest_duration, price) {}
};

class TaekTree : public MaterialPlant {
public:
    TaekTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : MaterialPlant(id, code, name, harvest_duration, price) {}
};

class sandalWoodTree : public MaterialPlant {
public:
    sandalWoodTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : MaterialPlant(id, code, name, harvest_duration, price) {}
};

class aleoTree : public MaterialPlant {
public:
    aleoTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : MaterialPlant(id, code, name, harvest_duration, price) {}
};

class ironwoodTree : public MaterialPlant {
public:
    ironwoodTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : MaterialPlant(id, code, name, harvest_duration, price) {}
};

class appleTree : public FruitPlant {
public:
    appleTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : FruitPlant(id, code, name, harvest_duration, price) {}
};

class orangeTree : public FruitPlant {
public:
    orangeTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : FruitPlant(id, code, name, harvest_duration, price) {}
};

class bananaTree : public FruitPlant {
public:
    bananaTree(int id, const std::string& code, const std::string& name, int harvest_duration, int price)
        : FruitPlant(id, code, name, harvest_duration, price) {}
};
#endif