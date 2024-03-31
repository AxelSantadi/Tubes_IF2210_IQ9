#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
    Animal(int id, const std::string& code, const std::string& name, const std::string& type, int weightToHarvest, int price);

    int getId() const;
    std::string getCode() const;
    std::string getName() const;
    std::string getType() const;
    int getWeightToHarvest() const;
    int getPrice() const;

private:
    int id;
    std::string code;
    std::string name;
    std::string type;
    int weightToHarvest;
    int price;
};

#endif // ANIMAL_HPP
