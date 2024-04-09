#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include <iostream>
#include "Inventory.hpp"
#include "Player.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "../Data/Misc.hpp"
#include "../Data/Recipe.hpp"
#include "../Data/ReadConfig.hpp"

using namespace std;

class Walikota : public Player
{
public:
    Walikota(string nama,int n, char m);
    Walikota(string nama,int n, char m,int money, int weight);
    ~Walikota();
    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;
    void removeBahan(string namaBahan, int jumlah) override;
    void buatBangunan(vector<Recipe> resep) override ;
    int getPajak(vector<Recipe> resep) override;
    void dapatPajak(vector<Recipe> resep) override ;
    
    void tambahPemain(Misc misc) override;
};

#endif