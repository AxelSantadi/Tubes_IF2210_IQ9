#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include <iostream>
#include "Kandang.cpp"
#include "Player.cpp"

using namespace std;

class Peternak : public Player{
    
private:
    Kandang kandang;
    int panjang;
    int lebar;

public:

    Peternak(string nama, int Berat_badan, int w_gulden, int panjang, int lebar);
    
    ~Peternak();

    string getRole() const override;
    void saveStatePlayer(ofstream &file) const override;
    
    void ternak(const Peternak& p);
    void feedTernak();
    void panenTernak();
    void jualTernak();

    int getPajak();

};

#endif