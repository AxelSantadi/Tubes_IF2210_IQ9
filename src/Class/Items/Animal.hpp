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

    int getBerat() const;
    void setBerat(int b);

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

    // Display
    void display() override;

    // Method buat toko sama Makan
    bool isUnlimited() const override;
    bool isMakanan() const override;

    // Method buat jenis
    string getJenis() const override;

    bool isHerbivore() const;
    bool isCarnivore() const;
    bool isOmnivore() const;

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
    virtual void panen() = 0;
};

class Carnivore : public Animal
{
public:
    Carnivore(int id, string code, string name, int weightToHarvest, int price);
    virtual void panen() = 0;
};

class Omnivore : public Animal
{
public:
    Omnivore(int id, string code, string name, int weightToHarvest, int price);
    virtual void panen() = 0;
};




#endif // ANIMAL_HPP
