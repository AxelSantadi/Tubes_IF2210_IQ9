#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
    Animal(int id, const std::string& code, const std::string& name, const std::string& type, int weightToHarvest, int price)
        : id(id), code(code), name(name), type(type), weightToHarvest(weightToHarvest), price(price) {}

    int getId() const { return id; }
    std::string getCode() const { return code; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getWeightToHarvest() const { return weightToHarvest; }
    int getPrice() const { return price; }

private:
    int id;
    std::string code;
    std::string name;
    std::string type;
    int weightToHarvest;
    int price;
};

#endif