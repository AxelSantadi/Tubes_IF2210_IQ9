#ifndef PETANI_HPP
#define PETANI_HPP

#include <iostream>
#include "ladang.hpp"
#include "Player.hpp"
#include "../Data/ReadConfig.hpp"
// #include "../Data/Recipe.hpp"

using namespace std;

class Petani : public Player{
private:
    Ladang ladang;
public:
    Petani(string nama,int n, char m,int panjang,char lebar);
    
    ~Petani();

    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;
    
    void addTanaman(Plant plant , int i, char j);

    Ladang getLadang() const;


    void tanam();
    void panen(vector<Product> product);
    void jual();
    void beli();

    int getPajak();
};

#endif