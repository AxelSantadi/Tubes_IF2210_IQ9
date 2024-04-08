#include <iostream>
#include "Inventory.hpp"
#include "Player.hpp"
#include "../Data/Misc.hpp"
#include "../Data/Recipe.hpp"

using namespace std;

class Walikota : public Player
{
public:
    Walikota(Misc m);
    ~Walikota();
    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;
    void removeBahan(string namaBahan, int jumlah);
    void buatBangunan(Misc m, vector<Recipe> resep);
    float tagihPajak();
    void tambahPemain(Misc misc);
    void wMakan();
};