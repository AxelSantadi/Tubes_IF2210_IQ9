#ifndef PERINTAH_HPP
#define PERINTAH_HPP

#include <iostream>
#include <fstream>
using namespace std;

#include "ReadConfig.hpp"
#include "../Player/Petani.hpp"
#include "../Player/Peternak.hpp"
#include "../Player/walikota.hpp"
#include "../Items/Product.hpp"
#include "../Items/Animal.hpp"
#include "../Items/Plant.hpp"
#include "../Player/Toko.hpp"
#include <limits>

class Perintah
{
    public:
        Perintah();
        ~Perintah();
        void initilization();
        void readConfig();
        void muatState();
        void NEXT();
        void CETAK_PENYIMPANAN();
        void PUNGUT_PAJAK();
        void CETAK_LADANG();
        void CETAK_PETERNAKAN();
        void TANAM();
        void TERNAK();
        void BANGUN();
        void MAKAN();
        void KASIH_MAKAN();
        void BELI();
        void JUAL();
        void PANEN();
        void SIMPAN();
        void TAMBAH_PEMAIN();

    private:
        ReadConfig config;
        bool endGame;
        Toko* toko;
};

#endif