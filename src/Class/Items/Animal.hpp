#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Product.hpp"
using namespace std;

class Animal : public Item
{
public:
    // 4 sekawan : ctor, cctor, dtor, op=
    Animal();
    Animal(int id, string code, string name, string type, int weightToHarvest, int price);
    Animal(const Animal &a);
    Animal &operator=(const Animal &a);
    ~Animal();

    // Getter and Setter
    string getType() const;
    void setType(string t);

    int getWeightToHarvest() const;
    void setWeightToHarvest(int w);

    // Operator Overloading
    Animal &operator+=(int x);
    Animal &operator-=(int x);

    Animal &operator+=(const Animal &a);
    Animal &operator-=(const Animal &a);

    // Input and Output
    void input(istream &is) override;
    void output(ostream &os) override;

    void display() override;
    bool isUnlimited() const override;

private:
    static int numOfAnimal;

    string type;
    int weightToHarvest;
};

class Herbivore : public Animal
{
public:
    Herbivore(int id, string code, string name, int weightToHarvest, int price);
    
};

class Carnivore : public Animal
{
public:
    Carnivore(int id, string code, string name, int weightToHarvest, int price);
};

class Omnivore : public Animal
{
public:
    Omnivore(int id, string code, string name, int weightToHarvest, int price);
};


class Cow : public Herbivore
{
public:
    Cow(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Sheep : public Herbivore
{
public:
    Sheep(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Horse : public Herbivore
{
public:
    Horse(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Rabbit : public Herbivore
{
public:
    Rabbit(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Herbivore(id, code, name, weightToHarvest, price) {}
};

class Snake : public Carnivore
{
public:
    Snake(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Carnivore(id, code, name, weightToHarvest, price) {}
};

class chicken : public Omnivore
{
public:
    chicken(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Omnivore(id, code, name, weightToHarvest, price) {}
};

class duck : public Omnivore
{
public:
    duck(int id, const std::string &code, const std::string &name, int weightToHarvest, int price)
        : Omnivore(id, code, name, weightToHarvest, price) {}
};

#endif // ANIMAL_HPP
