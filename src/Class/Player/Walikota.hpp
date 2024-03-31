#include <iostream>
#include "Inventory.hpp"
#include "Player.hpp"

using namespace std;

class Walikota : public Player
{
public:
    Walikota();
    ~Walikota();
    void buatBangunan();
    void jualBangunan();
    float tagihPajak();
    void tambahPemain();
private:
    int Berat_badan;
    int w_gulden;
    Inventory w_storage;
};