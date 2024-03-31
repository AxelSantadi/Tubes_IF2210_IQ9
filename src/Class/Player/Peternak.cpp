#include "Peternak.hpp"

Peternak::Peternak(string nama, int Berat_badan, int w_gulden, int panjang, int lebar) : Player(nama, Berat_badan, w_gulden),kandang(panjang, lebar){
    this->panjang = panjang;
    this->lebar = lebar;
    kandang = Kandang(panjang, lebar);
}   

Peternak::~Peternak(){}

void Peternak::ternak(const Peternak& p){
    cout << "Belum" << endl;
}