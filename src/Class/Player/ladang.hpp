#ifndef LADANG_HPP
#define LADANG_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include <string>
#include <vector>
#include "../Product/Plant.hpp"
using namespace std;

class Landang{
    private:
        MatrixMap<Plant> ladang;
        vector<Plant> listTanaman;
    public:
        Landang(int panjang, int lebar);
        void cetakLadang();
        vector<Plant> getListTanaman();
};

#endif