#include <iostream>
#include "Inventory.hpp"
#include "Player.hpp"

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
    void jualBangunan();
    float tagihPajak();
    void tambahPemain();
    void wMakan();
private:
    int Berat_badan;
    int w_gulden;
    Inventory w_storage;
};