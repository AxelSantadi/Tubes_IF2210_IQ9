#ifndef LADANG_HPP
#define LADANG_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include <string>
#include <unordered_map>
#include <vector>
#include "../Items/Plant.hpp"
#include "../Exception/Exception.hpp"
#include "../Exception/fileException.hpp"
#include "../Exception/inventoryException.hpp"
#include "../Exception/itemException.hpp"
#include "../Exception/playerException.hpp"
using namespace std;

class Ladang : public MatrixMap<Plant>{
        
    public:
        Ladang(int panjang, char lebar);
        void cetakLadang();
        void cetakLadangPanen();
        unordered_map<string,int> countPanen();
        void cetakJenisTanaman();
        Plant getPlant(int x, char a) const;
        vector<string> ambilPanenTumbuhan(string code, int n);
        void nextUmur();
};

#endif