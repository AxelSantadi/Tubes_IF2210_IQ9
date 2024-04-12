#ifndef PLANT_HPP
#define PLANT_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Product.hpp"
using namespace std;

class Plant : public Item{
public:
    // 4 Sekawan : ctor, cctor, dtor, op=
    Plant();
    Plant(int id, string code, string name, string type, int harvest_duration, int price);
    Plant(const Plant& p);
    Plant& operator=(const Plant& p);
    ~Plant();

    // Getter and Setter
    string getType() const;
    void setType(string t);

    int getHarvestDuration() const;
    void setHarvestDuration(int h);

    int getUmur() const;
    void setUmur(int u);
    void tambahUmur();  

    int getAddedWeight() const override;

    // Operator Overloading
    Plant& operator+=(int x);
    Plant& operator-=(int x);

    Plant& operator+=(const Plant& p);
    Plant& operator-=(const Plant& p); 

    // Input and Output
    void input(istream& is) override;
    void output(ostream& os) override;

    friend ostream& operator<<(ostream& os, const Plant& p);
    string operator*() const;

    // Determine stock in Toko
    bool isUnlimited() const override;

    // Determine if item is makanan
    bool isMakanan() const override;

    // Determine what kind of item
    string getJenis() const override;

protected:
    static int numOfPlant;
    string type;
    int harvest_duration;
    int umur;
};

class MaterialPlant : public Plant {
public:
    MaterialPlant(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price, int umur);
    virtual void panen() = 0;
};

class FruitPlant : public Plant {
public:
    FruitPlant(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price, int umur);
    virtual void panen() = 0;
};
#endif