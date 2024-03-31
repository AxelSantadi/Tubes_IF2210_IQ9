#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

using namespace std;

class Animal {
public:
    Animal(int id, const std::string& code, const std::string& name, const std::string& type, int weightToHarvest, int price);

    int getId() const;
    std::string getCode() const;
    std::string getName() const;
    std::string getType() const;
    int getWeightToHarvest() const;
    int getPrice() const;
    friend std::ostream& operator<<(std::ostream& os, const Animal& animal);

private:
    int id;
    std::string code;
    std::string name;
    std::string type;
    int weightToHarvest;
    int price;
};

class Herbivore: public Animal {
public:
    Herbivore(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Animal(id, code, name, "HERBIVORE", weightToHarvest, price) {}
};

class Carnivore: public Animal {
public:
    Carnivore(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Animal(id, code, name, "CARNIVORE", weightToHarvest, price) {}
};

class Omnivore: public Animal {
public:
    Omnivore(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Animal(id, code, name, "OMNIVORE", weightToHarvest, price) {}
};

class Cow: public Herbivore {
public:
    Cow(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Sheep: public Herbivore {
public:
    Sheep(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Horse: public Herbivore {
public:
    Horse(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Rabbit: public Herbivore {
public:
    Rabbit(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Snake: public Carnivore {
public:
    Snake(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Carnivore(id, code, name, weightToHarvest, price) {}
};

class chicken: public Omnivore {
public:
    chicken(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Omnivore(id, code, name, weightToHarvest, price) {}
};

class duck: public Omnivore {
public:
    duck(int id, const std::string& code, const std::string& name, int weightToHarvest, int price)
        : Omnivore(id, code, name, weightToHarvest, price) {}
};

#endif // ANIMAL_HPP
