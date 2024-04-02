#ifndef LADANG_HPP
#define LADANG_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include <string>
#include <unordered_map>
#include <vector>
#include "../Items/Plant.hpp"
using namespace std;

class Ladang : public MatrixMap<Plant>{
        
    public:
        Ladang(int panjang, int lebar);
        void cetakLadang();
        unordered_map<string,int> countPanen();
        void cetakJenisTanaman();
        vector<string> ambilPanen(string code, int n);
        void tambahUmur();
};

#endif