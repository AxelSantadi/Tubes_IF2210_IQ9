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
    Peternak(string nama,int n, char m,int weight,int money,int panjang,char lebar);    
    ~Peternak();

    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;

    void addTernak(Animal animal , int i, char j) override;

    Kandang getKandang() const;
    
    void ternak()override;
    void feedTernak()override;

    void panen(vector<Product> product)override;

    int getPajak(vector<Recipe> resep) override;

};

#endif