#ifndef PETANI_HPP
#define PETANI_HPP

#include <iostream>
#include "ladang.hpp"
#include "Player.hpp"
#include "../Data/ReadConfig.hpp"
#include "../Data/Recipe.hpp"

using namespace std;

class Petani : public Player{
private:
    Ladang ladang;
public:
    Petani(string nama,int n, char m,int panjang,char lebar);
    Petani(string nama,int n, char m,int money,int weight,int panjang,char lebar);
    
    ~Petani();

    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;
    
    void addTanaman(Plant plant , int i, char j) override;

    Ladang getLadang() const;


    void tanam()override;
    void panen(vector<Product> product)override;
    
    void nextDay()override;

    int getPajak(vector<Recipe> resep) override;
};

#endif