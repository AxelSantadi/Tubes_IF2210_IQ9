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

    int getBerat() const;
    void setBerat(int b);

    int getWeightToHarvest() const;
    void setWeightToHarvest(int w);

    int getAddedWeight() const override;
    // Operator Overloading
    Animal &operator+=(int x);
    Animal &operator-=(int x);

    Animal &operator+=(const Animal &a);
    Animal &operator-=(const Animal &a);

    // Input and Output
    void input(istream &is) override;
    void output(ostream &os) override;

    friend ostream& operator<<(ostream& os, const Animal& p);
    string operator*() const;

    void display() override;
    bool isUnlimited() const override;

    bool isMakanan() const override;

private:
    static int numOfAnimal;

    string type;
    int weightToHarvest;
    int berat;
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




#endif // ANIMAL_HPP
