#include <iostream>
#include "Inventory.hpp"
#include "Player.hpp"
#include "../Data/Misc.hpp"
#include "../Data/Recipe.hpp"

using namespace std;

class Walikota : public Player
{
public:
    Walikota();
    ~Walikota();
    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;
    void removeBahan(string namaBahan, int jumlah);
    void buatBangunan();
    float tagihPajak();
    void tambahPemain();
    void wMakan();
private:
    int Berat_badan;
    int w_gulden;
    Inventory w_storage;

    Misc misc;
    vector<Recipe> resep;
};