#ifndef KANDANG_HPP
#define KANDANG_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include <string>
#include <vector>
#include "../Items/Animal.hpp"
using namespace std;

class Kandang{
    private:
        vector<Animal> listTanaman;
    public:
        MatrixMap<Animal> kandang;
        
        Kandang(int panjang, int lebar);
        void cetakKandang();
        vector<Animal> getListTanaman();
};

#endif