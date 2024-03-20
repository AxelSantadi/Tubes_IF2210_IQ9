#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>

using namespace std;

enum PlantType {
    MATERIAL_PLANT,
    FRUIT_PLANT
};

class Plant {
public:
    Plant(int id, const std::string& code, const std::string& name, PlantType type, int harvest_duration, int price)
        : id(id), code(code), name(name), type(type), harvest_duration(harvest_duration), price(price) {}

    int getId() const { return id; }
    string getCode() const { return code; }
    string getName() const { return name; }
    PlantType getType() const { return type; }
    int getHarvestDuration() const { return harvest_duration; }
    int getPrice() const { return price; }

private:
    int id;
    std::string code;
    std::string name;
    PlantType type;
    int harvest_duration;
    int price;
};

#endif