#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>
#include "Item.hpp"

using namespace std;

class Plant : public Item{
public:
    Plant(int id, const std::string& code, const std::string& name, string type, int harvest_duration, int price);

    int getId() const ;
    string getCode() const ;
    string getName() const ;
    string getType() const;
    int getHarvestDuration() const; 

protected:
    string type;
    int harvest_duration;
};

class MaterialPlant : public Plant {
public:
    MaterialPlant(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price);
    void setharvest_duration(int harvest_duration);
};

class FruitPlant : public Plant {
public:
    FruitPlant(int id, const std::string& code, const std::string& name,string type, int harvest_duration, int price);
    void setharvest_duration(int harvest_duration);
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