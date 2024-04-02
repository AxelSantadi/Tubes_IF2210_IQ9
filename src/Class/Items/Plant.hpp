#ifndef PLANT_HPP
#define PLANT_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
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

    // Operator Overloading
    Plant& operator+=(int x);
    Plant& operator-=(int x);

    Plant& operator+=(const Plant& p);
    Plant& operator-=(const Plant& p); 

    // Input and Output
    void input(istream& is) override;
    void output(ostream& os) override;

    friend ostream& operator<<(ostream& os, const Plant& p);

protected:
    static int numOfPlant;

    string type;
    int harvest_duration;
};

class MaterialPlant : public Plant {
public:
    MaterialPlant(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price);
};

class FruitPlant : public Plant {
public:
    FruitPlant(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price);
};

class TaekTree : public MaterialPlant {
public:
    TaekTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : MaterialPlant(id, code, name,type, harvest_duration, price) {}

};

class sandalWoodTree : public MaterialPlant {
public:
    sandalWoodTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : MaterialPlant(id, code, name,type, harvest_duration, price) {}
};

class aleoTree : public MaterialPlant {
public:
    aleoTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : MaterialPlant(id, code, name,type, harvest_duration, price) {}
};

class ironwoodTree : public MaterialPlant {
public:
    ironwoodTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : MaterialPlant(id, code, name,type, harvest_duration, price) {}
};

class appleTree : public FruitPlant {
public:
    appleTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : FruitPlant(id, code, name,type, harvest_duration, price) {}
};

class orangeTree : public FruitPlant {
public:
    orangeTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : FruitPlant(id, code, name,type, harvest_duration, price) {}
};

class bananaTree : public FruitPlant {
public:
    bananaTree(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price)
        : FruitPlant(id, code, name,type, harvest_duration, price) {}
};
#endif