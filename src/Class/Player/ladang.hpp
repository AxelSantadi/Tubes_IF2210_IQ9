#ifndef LADANG_HPP
#define LADANG_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include <string>
#include <unordered_map>
#include <vector>
#include "../Items/Plant.hpp"
#include "../Data/Exception.hpp"
using namespace std;

class Ladang : public MatrixMap<Plant>{
        
    public:
        Ladang(int panjang, char lebar);
        void cetakLadang();
        unordered_map<string,int> countPanen();
        void cetakJenisTanaman();
        Plant getPlant(int x, char a) const;
        vector<string> ambilPanen(string code, int n);
        void nextUmur();
};

#endif