#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include <iostream>
#include "Kandang.hpp"
#include "Player.hpp"
#include "../Data/ReadConfig.hpp"


using namespace std;

class Peternak : public Player{
    
private:
    Kandang kandang;

public:

    Peternak(string nama,int n, char m,int panjang,char lebar);
    
    ~Peternak();

    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;

    void addTernak(Animal animal , int i, char j);
    
    void ternak();
    void feedTernak();
    void panenTernak(vector<Product> product);
    void jualTernak();

    int getPajak(vector<Recipe> resep) override;

};

#endif