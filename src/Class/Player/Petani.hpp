#ifndef PETANI_HPP
#define PETANI_HPP

#include <iostream>
#include "ladang.cpp"
#include "Player.cpp"

using namespace std;

class Petani : public Player{
private:
    Landang ladang;
    int panjang;
    int lebar;
public:
    Petani(string nama);

    Petani(string nama,int Berat_badan, int w_gulden,int panjang,int lebar);
    
    ~Petani();

    void tanam(const Petani& p);
    void panen();
    void jual();
    void beli();
};

#endif
